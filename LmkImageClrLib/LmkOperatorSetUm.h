#pragma once

#include "StdafxUm.h"

#include <cmath>

namespace LmkImageLib {
	/// <summary>
	/// converting rgb color to gray image
	/// </summary>
	/// <param name="red">red channel byte array</param>
	/// <param name="green">green channel byte array</param>
	/// <param name="blue">blue channel byte array</param>
	/// <param name="width">image width</param>
	/// <param name="height">image height</param>
	byte* RgbToGray(byte* red, byte* green, byte* blue, int width, int height);
	byte* RgbToGray(byte* red, byte* green, byte* blue, int width, int height);
	void ConvByte1to3(byte source[], byte channel1[], byte channel2[], byte channel3[], int size);
	void ConvByte1to3Stride(byte source[], byte channel1[], byte channel2[], byte channel3[], int width, int height, int stride);
	void ConvByte1to4(byte source[], byte channel1[], byte channel2[], byte channel3[], byte channel4[], int size);
	void ConvByte3to1(byte source1[], byte source2[], byte source3[], byte outcome[], int size);
	void ConvByte3to1Stride(byte source1[], byte source2[], byte source3[], int width, int height, byte outcome[], int stride);
	void ConvByte4to1(byte source1[], byte source2[], byte source3[], byte source4[], byte outcome[], int size);
	void TranslateArray(double source[], double num, int size);
}

