#include "stdafx.h"
#include "LmkRectangle.h"
#include "LmkRegion.h"
#include "LmkVector.h"

using namespace LmkImageClrLib;

LmkRectangle::LmkRectangle()
{
}
LmkRectangle::LmkRectangle(double row, double column, double width, double height)
{
	this->Row = row;
	this->Column = column;
	this->Width = width;
	this->Height = height;
	this->Angle = 0;
}
