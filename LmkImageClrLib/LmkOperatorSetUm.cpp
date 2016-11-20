#include "Stdafx.h"
#include "StdafxUm.h"
#include "LmkOperatorSetUm.h"

using namespace LmkImageClrLibUm;

byte* LmkOperatorSetUm::RgbToGray(byte* red, byte* green, byte* blue, int width, int height)
{
	int size = width * height;
	byte* new_array = new byte[size];
	for (int i = 0; i < size; i++)
	{
		new_array[i] = (byte)(((int)red[i] + (int)blue[i] + (int)green[i]) / 3);
	}
	return new_array;
}
