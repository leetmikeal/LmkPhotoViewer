#include "stdafx.h"
#include "LmkPointInt.h"

using namespace LmkImageClrLib;

LmkPointInt::LmkPointInt(int x, int y)
{
	this->x = x;
	this->y = y;
}

int LmkPointInt::X::get()
{
	return this->x;
}

int LmkPointInt::Y::get()
{
	return this->y;
}