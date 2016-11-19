#include "stdafx.h"
#include "LmkPointDbl.h"

using namespace LmkImageClrLib;

LmkPointDbl::LmkPointDbl(double x, double y)
{
	this->x = x;
	this->y = y;
}

double LmkPointDbl::X::get()
{
	return this->x;
}

double LmkPointDbl::Y::get()
{
	return this->y;
}