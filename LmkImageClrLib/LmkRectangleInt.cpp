#include "stdafx.h"
#include "LmkRectangleInt.h"
#include "LmkRegion.h"
#include "LmkVector.h"

using namespace LmkImageClrLib;

LmkRectangleInt::LmkRectangleInt()
{
	this->row    = 0;
	this->column = 0;
	this->width  = 0;
	this->height = 0;
}

/// <summary>
/// Copy constructor
/// </summary>
/// <param name="rectangle"></param>
LmkRectangleInt::LmkRectangleInt(LmkRectangleInt^ rectangle)
{
	this->row    = rectangle->Row;
	this->column = rectangle->Column;
	this->width  = rectangle->Width;
	this->height = rectangle->Height;
}

LmkRectangleInt::LmkRectangleInt(int row, int column, int width, int height)
{
	this->row    = row;
	this->column = column;
	this->width  = width;
	this->height = height;
}


LmkRectangleInt^ LmkRectangleInt::Clone()
{
	return gcnew LmkRectangleInt(this);
}

LmkRectangleDbl^ LmkRectangleInt::ToDouble()
{
	return gcnew LmkRectangleDbl(
		this->row,
		this->column,
		this->width,
		this->height
	);
}

// -------------------------------------------------------------------------

int LmkRectangleInt::LmkRectangleInt::Row::get()
{
	return this->row;
}
int LmkRectangleInt::LmkRectangleInt::Column::get()
{
	return this->column;
}
int LmkRectangleInt::LmkRectangleInt::Width::get()
{
	return this->width;
}
int LmkRectangleInt::LmkRectangleInt::Height::get()
{
	return this->height;
}
