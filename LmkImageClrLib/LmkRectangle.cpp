#include "stdafx.h"
#include "LmkRectangle.h"
#include "LmkRegion.h"
#include "LmkVector.h"

using namespace LmkImageClrLib;

LmkRectangle::LmkRectangle()
{
}

/// <summary>
/// Copy constructor
/// </summary>
/// <param name="rectangle"></param>
LmkRectangle::LmkRectangle(LmkRectangle^ rectangle)
{
	this->row    = rectangle->Row;
	this->column = rectangle->Column;
	this->width  = rectangle->Width;
	this->height = rectangle->Height;
	this->angle  = rectangle->Angle;
}

LmkRectangle::LmkRectangle(double row, double column, double width, double height)
{
	this->row = row;
	this->column = column;
	this->width = width;
	this->height = height;
	this->angle = 0;
}

LmkRectangle^ LmkRectangle::Clone()
{
	return gcnew LmkRectangle(this);
}

double LmkRectangle::LmkRectangle::Row::get()
{
	return this->row;
}
double LmkRectangle::LmkRectangle::Column::get()
{
	return this->column;
}
double LmkRectangle::LmkRectangle::Width::get()
{
	return this->width;
}
double LmkRectangle::LmkRectangle::Height::get()
{
	return this->height;
}
double LmkRectangle::LmkRectangle::Angle::get()
{
	return this->angle;
}
LmkRectangle^ LmkRectangle::LmkRectangle::SmallestRectangle::get()
{
	LmkVector^ vector = gcnew LmkVector(this);
	return vector->SmallestRectangle;
}

// -------------------------------------------------------------------------
