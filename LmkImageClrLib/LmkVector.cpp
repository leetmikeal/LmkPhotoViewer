#include "stdafx.h"
#include "LmkVector.h"
#include "LmkRectangle.h"

using namespace LmkImageClrLib;

LmkVector::LmkVector()
{
}
LmkVector::~LmkVector() {
	// release managed resource
	delete coor->arr;
	delete coor;

	this->!LmkVector();
}
/// <summary>
/// Finalizer
/// </summary>
LmkVector::!LmkVector() {
	// release unmanaged resource
}
LmkRectangle^ LmkVector::SmallestRectangle::get()
{
	throw gcnew NotImplementedException();
}
