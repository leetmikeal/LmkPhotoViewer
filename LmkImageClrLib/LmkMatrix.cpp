#include "stdafx.h"
#include "LmkMatrix.h"

using namespace LmkImageClrLib;

/// <summary>
/// Constructor
/// </summary>
LmkMatrix::LmkMatrix()
{
	this->elements = new double[6];
}

/// <summary>
/// Desctructor
/// </summary>
LmkMatrix::~LmkMatrix()
{
	// release managed resource
	delete elements;

	this->!LmkMatrix();
}

/// <summary>
/// Finalizer
/// </summary>
LmkMatrix::!LmkMatrix()
{
	// release unmanaged resource
}
/// <summary>
/// Initialize elements
/// </summary>
LmkMatrix::LmkMatrix(double m11, double m12, double m21, double m22, double offset1, double offset2)
{
	double* elem = new double[6]
		{
			m11,
			m12,
			offset1,
			m21,
			m22,
			offset2
		};
	this->elements = &elem[0];
}

LmkMatrix^ LmkMatrix::Translate(double x, double y)
{
	return gcnew LmkMatrix(
		this->elements[0] + x,
		this->elements[1] + x,
		this->elements[3] + y,
		this->elements[4] + y,
		this->elements[2] + x,
		this->elements[5] + y
	);
}
LmkMatrix^ LmkMatrix::TranslatePre(double x, double y)
{
	double* e = this->elements;
	return gcnew LmkMatrix(
		e[0],
		e[1],
		e[3],
		e[4],
		e[0] * x + e[1] * y + e[2],
		e[3] * x + e[4] * y + e[5]
	);
}
LmkMatrix^ LmkMatrix::Scale(double column, double row)
{
	return gcnew LmkMatrix(
		this->elements[0] * column,
		this->elements[1] * column,
		this->elements[3] * row,
		this->elements[4] * row,
		this->elements[2] * column,
		this->elements[5] * row
	);
}
LmkMatrix^ LmkMatrix::ScalePre(double column, double row)
{
	double* e = this->elements;
	return gcnew LmkMatrix(
		e[0] * column,
		e[1] * row,
		e[3] * column,
		e[4] * row,
		e[2],
		e[5]
	);
}
LmkMatrix^ LmkMatrix::Rotate(double a)
{
	double* e = this->elements;
	return gcnew LmkMatrix(
		e[0] * cos(a) - e[3] * sin(a),
		e[1] * cos(a) - e[4] * sin(a),
		e[0] * sin(a) + e[3] * cos(a),
		e[1] * sin(a) + e[4] * cos(a),
		e[2] * cos(a) - e[5] * sin(a),
		e[2] * sin(a) + e[5] * cos(a)
	);
}
LmkMatrix^ LmkMatrix::RotatePre(double a)
{
	double* e = this->elements;
	return gcnew LmkMatrix(
		e[0] * cos(a) + e[1] * sin(a),
		e[1] * cos(a) - e[0] * sin(a),
		e[3] * cos(a) + e[4] * sin(a),
		e[4] * cos(a) - e[3] * sin(a),
		e[2],
		e[5]
	);
}


double LmkMatrix::M11::get()
{
	return this->elements[0];
}
double LmkMatrix::M12::get()
{
	return this->elements[1];
}
double LmkMatrix::M21::get()
{
	return this->elements[3];

}
double LmkMatrix::M22::get()
{
	return this->elements[4];
}
double LmkMatrix::Offset1::get()
{
	return this->elements[2];
}
double LmkMatrix::Offset2::get()
{
	return this->elements[5];
}
LmkMatrix^ LmkMatrix::Identity::get()
{
	return gcnew LmkMatrix(1.0, 0.0, 0.0, 1.0, 0.0, 0.0);
}
