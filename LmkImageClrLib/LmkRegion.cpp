#include "stdafx.h"
#include "LmkRegion.h"
#include "LmkRectangle.h"

using namespace System;
using namespace LmkImageClrLib;

LmkRegion::LmkRegion()
{
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

LmkRegion::LmkRegion(int row, int column, int width, int height)
{
}

LmkRectangle^ LmkRegion::SmallestRectangle::get()
{
	throw gcnew NotImplementedException();
}
