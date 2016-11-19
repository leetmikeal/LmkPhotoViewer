#include "stdafx.h"
#include "LmkMatrix.h"

using namespace LmkImageClrLib;
using namespace LmkImageClrLibUm;

/// <summary>
/// Constructor
/// </summary>
LmkMatrix::LmkMatrix() {
	this->elements = new matrix2d();
}

/// <summary>
/// Desctructor
/// </summary>
LmkMatrix::~LmkMatrix() {
	// release managed resource
	delete elements;

	this->!LmkMatrix();
}

/// <summary>
/// Finalizer
/// </summary>
LmkMatrix::!LmkMatrix() {
	// release unmanaged resource
}
/// <summary>
/// Initialize elements
/// </summary>
LmkMatrix::LmkMatrix(double m11, double m12, double m21, double m22, double offset1, double offset2) {
	this->elements = new matrix2d();
	this->elements->m11 = m11;
	this->elements->m12 = m12;
	this->elements->m21 = m21;
	this->elements->m22 = m22;
	this->elements->offset1 = offset1;
	this->elements->offset2 = offset2;
}

LmkMatrix^ LmkMatrix::Translate(double x, double y) {
	return gcnew LmkMatrix(
		this->elements->m11 + x,
		this->elements->m12 + x,
		this->elements->m21 + y,
		this->elements->m22 + y,
		this->elements->offset1 + x,
		this->elements->offset2 + y
	);
}
LmkMatrix^ LmkMatrix::TranslatePre(double x, double y) {
	matrix2d* e = this->elements;
	return gcnew LmkMatrix(
		e->m11,
		e->m12,
		e->m21,
		e->m22,
		e->m11 * x + e->m12 * y + e->offset1,
		e->m21 * x + e->m22 * y + e->offset2
	);
}
LmkMatrix^ LmkMatrix::Scale(double column, double row) {
	return gcnew LmkMatrix(
		this->elements->m11 * column,
		this->elements->m12 * column,
		this->elements->m21 * row,
		this->elements->m22 * row,
		this->elements->offset1 * column,
		this->elements->offset2 * row
	);
}
LmkMatrix^ LmkMatrix::ScalePre(double column, double row) {
	matrix2d* e = this->elements;
	return gcnew LmkMatrix(
		e->m11 * column,
		e->m12 * row,
		e->m21 * column,
		e->m22 * row,
		e->offset1,
		e->offset2
	);
}
LmkMatrix^ LmkMatrix::Rotate(double a) {
	matrix2d* e = this->elements;
	return gcnew LmkMatrix(
		e->m11 * cos(a) - e->m21 * sin(a),
		e->m12 * cos(a) - e->m22 * sin(a),
		e->m11 * sin(a) + e->m21 * cos(a),
		e->m12 * sin(a) + e->m22 * cos(a),
		e->offset1 * cos(a) - e->offset2 * sin(a),
		e->offset1 * sin(a) + e->offset2 * cos(a)
	);
}
LmkMatrix^ LmkMatrix::Rotate(double a, double x, double y) {
	return this->Translate(-x, -y)->Rotate(a)->Translate(x, y);
}
LmkMatrix^ LmkMatrix::RotatePre(double a) {
	matrix2d* e = this->elements;
	return gcnew LmkMatrix(
		e->m11 * cos(a) + e->m12 * sin(a),
		e->m12 * cos(a) - e->m11 * sin(a),
		e->m21 * cos(a) + e->m22 * sin(a),
		e->m22 * cos(a) - e->m21 * sin(a),
		e->offset1,
		e->offset2
	);
}

double LmkMatrix::M11::get() {
	return this->elements->m11;
}
double LmkMatrix::M12::get() {
	return this->elements->m12;
}
double LmkMatrix::M21::get() {
	return this->elements->m21;
}
double LmkMatrix::M22::get() {
	return this->elements->m22;
}
double LmkMatrix::Offset1::get() {
	return this->elements->offset1;
}
double LmkMatrix::Offset2::get() {
	return this->elements->offset2;
}
LmkMatrix^ LmkMatrix::Identity::get() {
	return gcnew LmkMatrix(1.0, 0.0, 0.0, 1.0, 0.0, 0.0);
}
matrix2d* LmkMatrix::ElementsPointer::get() {
	return this->elements;
}
