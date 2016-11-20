#include "stdafx.h"
#include "LmkOperatorSet.h"
#include "LmkOperatorSetUm.h"

using namespace System;
using namespace LmkImageClrLib;

LmkRegion^ LmkOperatorSet::Threshold(LmkImage^ image, byte minVal, byte maxVal)
{
	if (image->Channel->Length != 1)
		throw gcnew ArgumentException();

	byte* data = image->Channel[0]->data;
	int width = image->Channel[0]->width;
	int height = image->Channel[0]->height;

	int size = width * height;
	// threshold
	bool* extracted_data = new bool[size + 1] { false };
	for (int i = 0; i < size; i++)
	{
		if (data[i] >= minVal && data[i] <= maxVal)
			extracted_data[i] = true;
	}

	// make run length
	std::list<run*> run_list;
	int state = 0; // 0: out region, 1: out to in, 2: in region, 3: in to out
	int tmp_row;
	int tmp_column_begin;
	bool* cur = &extracted_data[0];
	bool* prev = nullptr;
	for (int ih = 0; ih < height; ih++)
	{
		// iw == 0
		if (*cur)
			state = 1;

		if (state == 1)
		{
			tmp_row = ih;
			tmp_column_begin = 0;
		}

		prev = cur;
		cur++;

		for (int iw = 1; iw < width; iw++)
		{
			if (*prev && *cur)
				state = 2;
			else if (*prev && !*cur)
				state = 3;
			else if (!*prev && *cur)
				state = 1;
			else if (!*prev && !*cur)
				state = 0;

			if (state == 3)
			{
				run* r = new run();
				r->row = tmp_row;
				r->column_begin = tmp_column_begin;
				r->column_end = iw - 1;
				run_list.push_back(r);
			}

			prev = cur;
			cur++;
		}

		// last column in a row
		if (state == 2)
		{
			run* r = new run();
			r->row = tmp_row;
			r->column_begin = tmp_column_begin;
			r->column_end = width - 1;
			run_list.push_back(r);
		}
	}

	// added run length
	run_length* rl = new run_length();
	int count = 0;
	for (std::list<run*>::iterator itr = run_list.begin(); itr != run_list.end(); ++itr)
	{
		count++;
	}
	rl->size = count;
	rl->run_ptr = new run[rl->size];
	count = 0;
	for (std::list<run*>::iterator itr = run_list.begin(); itr != run_list.end(); ++itr)
	{
		rl->run_ptr[count] = *(*itr);
	}

	delete extracted_data;
	return gcnew LmkRegion(rl);
}

array<LmkRegion^>^ LmkOperatorSet::ThresholdMulti(LmkImage^ image, byte minVal, byte maxVal)
{
	throw gcnew NotImplementedException();
}

LmkImage^ LmkOperatorSet::ConvertColor(LmkImage^ image, ConvertColorType colorType)
{
	// check
	if (!image->ContainChannel(ColorType::Red)
		|| !image->ContainChannel(ColorType::Green)
		|| !image->ContainChannel(ColorType::Blue))
		throw gcnew System::ArgumentException();

	switch (colorType)
	{
	case LmkImageClrLib::ConvertColorType::RgbToGray:
	{
		byte* red_data = image->ExtractChannel(ColorType::Red)->Channel[0]->data;
		byte* green_data = image->ExtractChannel(ColorType::Green)->Channel[0]->data;
		byte* blue_data = image->ExtractChannel(ColorType::Blue)->Channel[0]->data;
		byte* new_array = LmkOperatorSetUm::RgbToGray(red_data, green_data, blue_data, image->Width, image->Height);
		LmkImageChannel^ channel = gcnew LmkImageChannel(new_array, image->Width, image->Height, ColorType::Brightness);
		return gcnew LmkImage(gcnew array<LmkImageChannel^> { channel });
		break;
	}
	default:
		throw gcnew System::NotSupportedException();
		break;
	}
}


