#include "stdafx.h"
#include "LmkOperatorSet.h"
#include "LmkOperatorSetUm.h"

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace LmkImageLib;

#pragma region General

/// <summary>
/// Convert System::String to unmanaged char type
/// This char pointer must be release to use (System::Runtime::InteropServices::Marshal::FreeHGlobal(ptr)).
/// </summary>
/// <param name="str">string</param>
/// <returns>char type pointer</returns>
char* LmkOperatorSet::ToUnmanagedChar(String^ str) {
	return (char*)Marshal::StringToHGlobalAnsi(str).ToPointer();
}

void LmkOperatorSet::ReleaseChar(char* c) {
	Marshal::FreeHGlobal(IntPtr(c));
}

array<Byte>^ LmkOperatorSet::Compress(array<Byte>^ raw) {
	if (raw->Length == 0)
		return gcnew array<Byte> { };

	System::IO::MemoryStream^ memory = gcnew System::IO::MemoryStream();
	try {
		System::IO::Compression::GZipStream^ gzip = gcnew System::IO::Compression::GZipStream(
			memory,
			System::IO::Compression::CompressionLevel::Fastest,
			true
		);
		try {
			gzip->Write(raw, 0, raw->Length);
			return memory->ToArray();
		}
		__finally {
			gzip->Close();
		}
	}
	__finally {
		memory->Close();
	}
}

array<Byte>^ LmkOperatorSet::Decompress(array<Byte>^ compressed) {
	if (compressed->Length == 0)
		return gcnew array<Byte>(0);

	System::IO::Compression::GZipStream^ stream = gcnew System::IO::Compression::GZipStream(
		gcnew System::IO::MemoryStream(compressed), 
		System::IO::Compression::CompressionMode::Decompress
	);
	try {
		const int size = 65536;
		array<Byte>^ buffer = gcnew array<Byte>(size);
		System::IO::MemoryStream^ memory = gcnew System::IO::MemoryStream();
		try
		{
			int count = 0;
			do {
				count = stream->Read(buffer, 0, size);
				if (count > 0)
					memory->Write(buffer, 0, count);
			} while (count < 0);
			return memory->ToArray();
		}
		__finally {
			memory->Close();
		}
	}
	__finally {
		stream->Close();
	}

}

#pragma endregion

#pragma region Convert
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
	case LmkImageLib::ConvertColorType::RgbToGray:
	{
		byte* red_data = image->ExtractChannel(ColorType::Red)->Channel[0]->data;
		byte* green_data = image->ExtractChannel(ColorType::Green)->Channel[0]->data;
		byte* blue_data = image->ExtractChannel(ColorType::Blue)->Channel[0]->data;
		byte* new_array = LmkImageLib::RgbToGray(red_data, green_data, blue_data, image->Width, image->Height);
		LmkImageChannel^ channel = gcnew LmkImageChannel(new_array, image->Width, image->Height, ColorType::Brightness);
		return gcnew LmkImage(gcnew array<LmkImageChannel^> { channel });
		break;
	}
	default:
		throw gcnew System::NotSupportedException();
		break;
	}
}

#pragma endregion

#pragma region Image

LmkImage^ LmkOperatorSet::LoadImage(String^ filePath)
{
	// read file
	const char* filePathChar = LmkOperatorSet::ToUnmanagedChar(filePath);
	cv::Mat image;
	cv::String filePathCvs = cv::String(filePathChar);
	image = cv::imread(filePathChar, cv::IMREAD_UNCHANGED);
	LmkOperatorSet::ReleaseChar((char*)filePathChar);

	// fetch size
	int size = image.rows * image.cols;

	// extract pointer
	if (image.channels() == 1)
	{
		byte* byteGray = new byte[size];
		std::memcpy(byteGray, image.data, sizeof(byte) * size);
		LmkImageChannel^ channel = gcnew LmkImageChannel(byteGray, image.cols, image.rows, ColorType::Brightness);
		LmkImage^ lmkImage = gcnew LmkImage(gcnew array<LmkImageChannel^>{ channel });
		return lmkImage;
	}
	else if (image.channels() == 3)
	{
		std::vector<cv::Mat> multiImage;
		cv::split(image, multiImage);

		byte* byteR = new byte[size];
		byte* byteG = new byte[size];
		byte* byteB = new byte[size];

		// OpenCV image order is BGR not RGB
		std::memcpy(byteR, multiImage[2].data, sizeof(byte) * size);
		std::memcpy(byteG, multiImage[1].data, sizeof(byte) * size);
		std::memcpy(byteB, multiImage[0].data, sizeof(byte) * size);

		LmkImageChannel^ channelR = gcnew LmkImageChannel(byteR, image.cols, image.rows, ColorType::Red);
		LmkImageChannel^ channelG = gcnew LmkImageChannel(byteG, image.cols, image.rows, ColorType::Green);
		LmkImageChannel^ channelB = gcnew LmkImageChannel(byteB, image.cols, image.rows, ColorType::Blue);
		LmkImage^ lmkImage = gcnew LmkImage(gcnew array<LmkImageChannel^>{ channelR, channelG, channelB });
		return lmkImage;
	}
	else
		throw gcnew System::NotSupportedException();

}


#pragma endregion


