#include "Stdafx.h"
#include "LmkVector.h"
#include "LmkRectangle.h"

using namespace LmkImageClrLib;

/// <summary>
/// Constructor
/// </summary>
LmkVector::LmkVector()
{
	this->coor = new coor_array();
	this->coor->arr = new coor2d[0];
	this->coor->size = 0;

	// cache
	this->smallestRectangle = nullptr;
}
/// <summary>
/// Copy constructor
/// </summary>
LmkVector::LmkVector(LmkVector^ vector)
{
	this->coor = new coor_array();
	this->coor->arr = new coor2d[vector->coor->size];
	memcpy(this->coor->arr, vector->coor->arr, sizeof(coor2d) * vector->coor->size);
	this->coor->size = vector->coor->size;

	// cache
	this->smallestRectangle = nullptr;
}
/// <summary>
/// From rectangle
/// </summary>
LmkVector::LmkVector(LmkRectangle^ rectangle)
{
	// create not rotated coordinate
	coor2d* base_coor = new coor2d[4];
	base_coor[0].x = rectangle->Column;
	base_coor[0].y = rectangle->Row;
	base_coor[1].x = rectangle->Column + rectangle->Width;
	base_coor[1].y = rectangle->Row;
	base_coor[2].x = rectangle->Column + rectangle->Width;
	base_coor[2].y = rectangle->Row + rectangle->Height;
	base_coor[3].x = rectangle->Column;
	base_coor[3].y = rectangle->Row + rectangle->Height;

	// insert rotated angle
	this->coor = new coor_array();
	this->coor->size = 4;
	this->coor->arr = new coor2d[4];
	for (int i = 0; i < 4; i++)
	{
		this->coor->arr[i] = LmkImageClrLibUm::Rotate(base_coor[i], rectangle->Angle);
	}
	// release temporaly data
	delete base_coor;

	// cache
	this->smallestRectangle = nullptr;
}
/// <summary>
/// Destructor
/// </summary>
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
/// <summary>
/// Get smallest rectangle
/// </summary>
/// <returns></returns>
LmkRectangle^ LmkVector::SmallestRectangle::get()
{
	// return cache
	if (this->smallestRectangle != nullptr)
		return this->smallestRectangle;

	// set initial value
	double minRow = std::numeric_limits<double>::max(); // compare to maximum
	double maxRow = std::numeric_limits<double>::min(); // compare to minimum
	double minCol = std::numeric_limits<double>::max(); // compare to maximum
	double maxCol = std::numeric_limits<double>::min(); // compare to minimum
	for (int i = 0; i < this->coor->size; i++)
	{
		if (minRow > this->coor->arr[i].y)
			minRow = this->coor->arr[i].y;
		if (maxRow < this->coor->arr[i].y)
			maxRow = this->coor->arr[i].y;
		if (minCol > this->coor->arr[i].x)
			minCol = this->coor->arr[i].x;
		if (maxCol < this->coor->arr[i].x)
			maxCol = this->coor->arr[i].x;
	}

	// caching
	this->smallestRectangle = gcnew LmkRectangle(minRow, minCol, maxCol - minCol + 1, maxRow - maxRow + 1);
	return this->smallestRectangle;
}
