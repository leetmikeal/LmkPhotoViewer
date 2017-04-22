#pragma once

#include "Stdafx.h"
#include "StdafxUm.h"

#include <list>

#include "LmkImage.h"
#include "LmkMatrix.h"
#include "LmkBit.h"
#include "LmkRegion.h"
#include "LmkVector.h"
#include "LmkPointInt.h"
#include "LmkPointDbl.h"
#include "LmkRectangleInt.h"
#include "LmkRectangleDbl.h"

namespace LmkImageLib {
	/// <summary>
	/// Common operator set class
	/// </summary>
	public ref class LmkOperatorSet
	{
#pragma region General
	public:
	internal:
		static char* ToUnmanagedChar(String^ str);
		static void ReleaseChar(char* c);
		static array<Byte>^ Compress(array<Byte>^ row);
		static array<Byte>^ Decompress(array<Byte>^ compressed);
#pragma endregion
#pragma region Convert
	public:
		//LmkOperatorSet();
		static LmkRegion^ Threshold(LmkImage^ image, byte minVal, byte maxVal);
		static array<LmkRegion^>^ ThresholdMulti(LmkImage^ image, byte minVal, byte maxVal);
		static LmkImage^ ConvertColor(LmkImage^ image, ConvertColorType colorType);
#pragma endregion
#pragma region Image
	public:
		//LmkOperatorSet();
		static LmkImage^ LoadImage(String^ filePath);

#pragma endregion
#pragma region UnmanagedWrapper
	public:
		static void ConvByte1to3(byte source[], byte channel1[], byte channel2[], byte channel3[], int size);
		static void ConvByte1to3Stride(byte source[], byte channel1[], byte channel2[], byte channel3[], int width, int height, int stride);
		static void ConvByte1to4(byte source[], byte channel1[], byte channel2[], byte channel3[], byte channel4[], int size);
		static void ConvByte3to1(byte source1[], byte source2[], byte source3[], byte outcome[], int size);
		static void ConvByte3to1Stride(byte source1[], byte source2[], byte source3[], int width, int height, byte outcome[], int stride);
		static void ConvByte4to1(byte source1[], byte source2[], byte source3[], byte source4[], byte outcome[], int size);
		static void TranslateArray(double source[], double num, int size);
#pragma endregion


	};
}

