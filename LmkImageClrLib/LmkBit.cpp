#include "stdafx.h"
#include "LmkBit.h"

using namespace LmkImageLib;

/// <summary>
/// Constructor
/// </summary>
LmkBit::LmkBit() {
	this->data = new byte[0];
}

/// <summary>
/// Destructor
/// </summary>
LmkBit::~LmkBit() {
	// release managed resource
	delete this->data;

	this->!LmkBit();
}

/// <summary>
/// Finalizer
/// </summary>
/// <returns></returns>
LmkBit::!LmkBit() {
	// release unmanaged resource
}

/// <summary>
/// Copy constructor
/// </summary>
/// <param name="bit">original bit image</param>
/// <returns>image</returns>
LmkBit::LmkBit(LmkBit^ bit) {
	this->width = this->Width;
	this->height = this->Height;
	byte* newByte = nullptr;
	std::memcpy(newByte, this->data, sizeof(byte) * this->SizeByte);
	this->data = newByte;
	this->tags = this->tags;
}

/// <summary>
/// Copy object
/// </summary>
/// <returns>copied object</returns>
LmkBit^ LmkBit::Clone() {
	return gcnew LmkBit(this);
}

int LmkBit::Width::get() {
	return this->width;
}
int LmkBit::Height::get() {
	return this->height;
}
int LmkBit::Size::get() {
	return this->width * this->Height;
}
int LmkBit::WidthByte::get() {
	double w = (double)this->width / sizeof(byte);
	return (int)floor(w);
}
int LmkBit::HeightByte::get() {
	double h = (double)this->height / sizeof(byte);
	return (int)floor(h);
}
int LmkBit::SizeByte::get() {
	return this->WidthByte * this->HeightByte;
}
IntPtr^ LmkBit::Data::get() {
	return gcnew IntPtr(this->data);
}
String^ LmkBit::Tags::get() {
	return this->tags;
}

