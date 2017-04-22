#include "stdafx.h"
#include "LmkPointDbl.h"
#include "LmkMatrix.h"

using namespace LmkImageLib;

LmkPointDbl::LmkPointDbl(double x, double y) {
	this->x = x;
	this->y = y;
}

LmkPointDbl^ LmkPointDbl::Transform(LmkMatrix^ matrix) {
	return gcnew LmkPointDbl(
		this->x * matrix->M11 + this->y * matrix->M12 + matrix->Offset1,
		this->x * matrix->M21 + this->y * matrix->M22 + matrix->Offset2
	);
}

double LmkPointDbl::X::get() {
	return this->x;
}

double LmkPointDbl::Y::get() {
	return this->y;
}