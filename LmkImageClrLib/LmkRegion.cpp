#include "Stdafx.h"
#include "StdafxUm.h"
#include "LmkRegion.h"
#include "LmkRectangleInt.h"

using namespace System;
using namespace LmkImageClrLib;
using namespace LmkImageClrLibUm;

LmkRegion::LmkRegion()
{
	// body
	this->rl = new run_length();
	this->rl->size = 0;
	this->rl->run_ptr = new run[0];

	// cache
	this->areaSize = -1; // undefined
	this->smallestRectangle = nullptr;
}
LmkRegion::~LmkRegion()
{
	// release managed resource
	delete rl->run_ptr;
	delete rl;

	this->!LmkRegion();
}
LmkRegion::!LmkRegion()
{
	// release unmanaged resource
}

LmkRegion::LmkRegion(LmkRectangleInt^ rectangle)
{
	this->rl = new run_length();
	this->rl->size = rectangle->Height;
	this->rl->run_ptr = new run[this->rl->size];

	for (int i = 0; i < this->rl->size; i++)
	{
		this->rl->run_ptr[i].row = (int)rectangle->Row + i;
		this->rl->run_ptr[i].column_begin = (int)rectangle->Column;
		this->rl->run_ptr[i].column_end = (int)(rectangle->Column + rectangle->Width) - 1;
	}

	// create cache
	this->areaSize = (int)rectangle-> Width * (int)rectangle->Height;
	this->smallestRectangle = rectangle->Clone();
}

LmkRegion::LmkRegion(int row, int column, int width, int height)
{
	this->rl = new run_length();
	this->rl->size = height;
	this->rl->run_ptr = new run[height];

	for (int i = 0; i < height; i++)
	{
		this->rl->run_ptr[i].row = row + i;
		this->rl->run_ptr[i].column_begin = column;
		this->rl->run_ptr[i].column_end = column + width - 1;
	}

	// create cache
	this->areaSize = width * height;
	this->smallestRectangle = gcnew LmkRectangleInt(row, column, width, height);
}

LmkRectangleInt^ LmkRegion::SmallestRectangle::get()
{
	// return cache
	if (this->smallestRectangle != nullptr)
		return this->smallestRectangle;

	// set initial value
	int minRow = std::numeric_limits<int>::max(); // compare to maximum
	int maxRow = std::numeric_limits<int>::min(); // compare to minimum
	int minCol = std::numeric_limits<int>::max(); // compare to maximum
	int maxCol = std::numeric_limits<int>::min(); // compare to minimum
	for (int i = 0; i < this->rl->size; i++)
	{
		if (minRow > this->rl->run_ptr[i].row)
			minRow = this->rl->run_ptr[i].row;
		if (maxRow < this->rl->run_ptr[i].row)
			maxRow = this->rl->run_ptr[i].row;
		if (minCol > this->rl->run_ptr[i].column_begin)
			minCol = this->rl->run_ptr[i].column_begin;
		if (maxCol < this->rl->run_ptr[i].column_end)
			maxCol = this->rl->run_ptr[i].column_end;
	}

	// caching
	this->smallestRectangle = gcnew LmkRectangleInt(minRow, minCol, maxCol - minCol + 1, maxRow - maxRow + 1);
	return this->smallestRectangle;
}

int LmkRegion::AreaSize::get()
{
	// return cache
	if (this->areaSize >= 0)
		return this->areaSize;

	// calculate arae size
	int area = 0;
	for (int i = 0; i < this->rl->size; i++)
	{
		area += this->rl->run_ptr[i].column_end - this->rl->run_ptr[i].column_begin + 1;
	}

	// caching
	this->areaSize = area;
	return this->areaSize;
}
