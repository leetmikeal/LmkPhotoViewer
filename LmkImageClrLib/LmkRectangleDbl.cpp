#include "stdafx.h"
#include "LmkRectangleDbl.h"
#include "LmkRegion.h"
#include "LmkVector.h"
#include "LmkPointDbl.h"

using namespace LmkImageClrLib;

LmkRectangleDbl::LmkRectangleDbl()
{
	this->row    = 0.0;
	this->column = 0.0;
	this->width  = 0.0;
	this->height = 0.0;
}

/// <summary>
/// Copy constructor
/// </summary>
/// <param name="rectangle"></param>
LmkRectangleDbl::LmkRectangleDbl(LmkRectangleDbl^ rectangle)
{
	this->row    = rectangle->Row;
	this->column = rectangle->Column;
	this->width  = rectangle->Width;
	this->height = rectangle->Height;
	this->angle  = rectangle->Angle;
}

LmkRectangleDbl::LmkRectangleDbl(double row, double column, double width, double height)
{
	this->row    = row;
	this->column = column;
	this->width  = width;
	this->height = height;
	this->angle  = 0.0;
}

LmkRectangleDbl^ LmkRectangleDbl::Clone()
{
	return gcnew LmkRectangleDbl(this);
}

double LmkRectangleDbl::Row::get()
{
	return this->row;
}
double LmkRectangleDbl::Column::get()
{
	return this->column;
}
double LmkRectangleDbl::Width::get()
{
	return this->width;
}
double LmkRectangleDbl::Height::get()
{
	return this->height;
}
double LmkRectangleDbl::Angle::get()
{
	return this->angle;
}
LmkRectangleDbl^ LmkRectangleDbl::LmkRectangleDbl::SmallestRectangle::get()
{
	LmkVector^ vector = gcnew LmkVector(this);
	return vector->SmallestRectangle;
}
LmkPointDbl^ LmkRectangleDbl::Center::get()
{
	return gcnew LmkPointDbl(
		this->column + this->width / 2.0,
		this->row + this->height / 2.0
	);
}


// -------------------------------------------------------------------------
