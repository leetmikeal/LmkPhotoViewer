#include "Stdafx.h"
#include "StdafxUm.h"
#include "LmkOperatorSetUm.h"

using namespace LmkImageLib;

#pragma unmanaged

byte* LmkImageLib::RgbToGray(byte* red, byte* green, byte* blue, int width, int height)
{
	int size = width * height;
	byte* new_array = new byte[size];
	for (int i = 0; i < size; i++)
	{
		new_array[i] = (byte)(((int)red[i] + (int)blue[i] + (int)green[i]) / 3);
	}
	return new_array;
}

void LmkImageLib::ConvByte1to3(byte source[], byte channel1[], byte channel2[], byte channel3[], int size)
{
	for (int i = 0; i < size; i++)
	{
		channel1[i] = source[i * 3 + 0];
		channel2[i] = source[i * 3 + 1];
		channel3[i] = source[i * 3 + 2];
	}
}

void LmkImageLib::ConvByte1to3Stride(byte source[], byte channel1[], byte channel2[], byte channel3[], int width, int height, int stride)
{
	byte* pointer = source;
	for(int i = 0; i < height; i++)
	{
		pointer = &source[i * stride];
		for (int j = 0; j < width; j++)
		{
			channel1[i * width + j] = *(pointer++);
			channel2[i * width + j] = *(pointer++);
			channel3[i * width + j] = *(pointer++);
		}

	}
}


void LmkImageLib::ConvByte1to4(byte source[], byte channel1[], byte channel2[], byte channel3[], byte channel4[], int size)
{
	for (int i = 0; i < size; i++)
	{
		channel1[i] = source[i * 4 + 0];
		channel2[i] = source[i * 4 + 1];
		channel3[i] = source[i * 4 + 2];
		channel4[i] = source[i * 4 + 3];
	}
}

void LmkImageLib::ConvByte3to1(byte source1[], byte source2[], byte source3[], byte outcome[], int size)
{
	for (int i = 0; i < size; i++)
	{
		outcome[i * 3 + 0] = source1[i];
		outcome[i * 3 + 1] = source2[i];
		outcome[i * 3 + 2] = source3[i];
	}
}

void LmkImageLib::ConvByte3to1Stride(byte source1[], byte source2[], byte source3[], int width, int height, byte outcome[], int stride)
{
	byte* pointer = outcome;
	byte* source1Pointer = &source1[0];
	byte* source2Pointer = &source2[0];
	byte* source3Pointer = &source3[0];
	for(int i = 0; i < height; i++)
	{
		byte* p = pointer;
		for (int j = 0; j < width; j++)
		{
			*(p++) = *(source1Pointer++);
			*(p++) = *(source2Pointer++);
			*(p++) = *(source3Pointer++);
		}
		pointer += stride;

		// normal way
		//outcome[i*3+0] = source1[i];
		//outcome[i*3+1] = source2[i];
		//outcome[i*3+2] = source3[i];
	}
}

void LmkImageLib::ConvByte4to1(byte source1[], byte source2[], byte source3[], byte source4[], byte outcome[], int size)
{
	for (int i = 0; i < size; i++)
	{
		outcome[i * 4 + 0] = source1[i];
		outcome[i * 4 + 1] = source2[i];
		outcome[i * 4 + 2] = source3[i];
		outcome[i * 4 + 3] = source4[i];
	}
}


void LmkImageLib::TranslateArray(double source[], double num, int size)
{
	for (int i = 0; i < size; i++)
	{
		source[i] += num;
	}
}

