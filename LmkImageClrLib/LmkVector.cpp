#include "Stdafx.h"
#include "StdafxUm.h"
#include "LmkVector.h"
#include "LmkRectangleDbl.h"
#include "LmkPointDbl.h"
#include "LmkMatrix.h"

using namespace LmkImageClrLib;

/// <summary>
/// Constructor
/// </summary>
LmkVector::LmkVector() {
	this->coor = new coor_array();
	this->coor->arr = new coor2d[0];
	this->coor->size = 0;

	// cache
	this->smallestRectangle = nullptr;
}
LmkVector::LmkVector(coor_array* coor) {
	this->coor = coor;

	// cache
	this->smallestRectangle = nullptr;
}

/// <summary>
/// Copy constructor
/// </summary>
LmkVector::LmkVector(LmkVector^ vector) {
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
LmkVector::LmkVector(LmkRectangleDbl^ rectangle) {
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
/// Transformation
/// </summary>
LmkVector^ LmkVector::Transform(LmkMatrix^ matrix) {
	matrix2d* e = matrix->ElementsPointer;
	coor_array* nc = new coor_array(); // new coordinate array
	coor_array* oc = this->coor; // old coordinate array pointer
	nc->size = this->coor->size;
	nc->arr = new coor2d[nc->size];
	for (int i = 0; i < this->coor->size; i++)
	{
		nc->arr[i].x = oc->arr[i].x * e->m11 + oc->arr[i].y * e->m12 + e->offset1;
		nc->arr[i].y = oc->arr[i].x * e->m21 + oc->arr[i].y * e->m22 + e->offset2;
	}
	return gcnew LmkVector(nc);
}
array<LmkPointDbl^>^ LmkVector::Points::get() {
	coor_array* c = this->coor;
	array<LmkPointDbl^>^ pointArr = gcnew array<LmkPointDbl^>(c->size);
	for (int i = 0; i < c->size; i++)
	{
		pointArr[i] = gcnew LmkPointDbl(c->arr[i].x, c->arr[i].y);
	}
	return pointArr;
}


/// <summary>
/// Get smallest rectangle
/// </summary>
/// <returns></returns>
LmkRectangleDbl^ LmkVector::SmallestRectangle::get() {
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
	this->smallestRectangle = gcnew LmkRectangleDbl(minRow, minCol, maxCol - minCol + 1, maxRow - maxRow + 1);
	return this->smallestRectangle;
}

int LmkVector::Length::get()
{
	return this->coor->size;
}
