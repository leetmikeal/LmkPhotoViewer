#include "stdafx.h"
#include "LmkRectangleInt.h"
#include "LmkRegion.h"
#include "LmkVector.h"
#include "LmkPointDbl.h"

using namespace LmkImageLib;

LmkRectangleInt::LmkRectangleInt() {
	this->column = 0;
	this->row    = 0;
	this->width  = 0;
	this->height = 0;
}

/// <summary>
/// Copy constructor
/// </summary>
/// <param name="rectangle"></param>
LmkRectangleInt::LmkRectangleInt(LmkRectangleInt^ rectangle) {
	this->column = rectangle->Column;
	this->row    = rectangle->Row;
	this->width  = rectangle->Width;
	this->height = rectangle->Height;
}

LmkRectangleInt::LmkRectangleInt(int column, int row, int width, int height) { 
	this->column = column;
	this->row    = row;
	this->width  = width;
	this->height = height;
}


LmkRectangleInt^ LmkRectangleInt::Clone() {
	return gcnew LmkRectangleInt(this);
}

LmkRectangleDbl^ LmkRectangleInt::ToDouble() {
	return gcnew LmkRectangleDbl(
		this->column,
		this->row,
		this->width,
		this->height
	);
}

int LmkRectangleInt::Column::get() {
	return this->column;
}
int LmkRectangleInt::Row::get() {
	return this->row;
}
int LmkRectangleInt::Width::get() {
	return this->width;
}
int LmkRectangleInt::Height::get() {
	return this->height;
}
LmkPointDbl^ LmkRectangleInt::Center::get() {
	return gcnew LmkPointDbl(
		(double)this->column + (double)this->width / 2.0,
		(double)this->row + (double)this->height / 2.0
	);
}
