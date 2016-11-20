#include "stdafx.h"
#include "LmkOperatorSet.h"

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

LmkRegion^ LmkOperatorSet::ThresholdMulti(LmkImage^ image, byte minVal, byte maxVal)
{
	throw gcnew NotImplementedException();
}


