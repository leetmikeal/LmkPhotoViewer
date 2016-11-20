#include "stdafx.h"
#include "LmkImage.h"

using namespace LmkImageClrLib;

/// <summary>
/// Constructor
/// </summary>
LmkImageChannel::LmkImageChannel() {
	this->data = new byte[0];
	this->width = 0;
	this->height = 0;
	this->color = ColorType::None;
}
/// <summary>
/// Copy constructor
/// </summary>
LmkImageChannel::LmkImageChannel(LmkImageChannel^ channel) {
	int size = channel->Width * channel->Height;
	byte* newData = new byte[size];
	memcpy(newData, channel->data, sizeof(byte) * size);
	this->data = newData;

	this->width = channel->width;
	this->height = channel->height;
	this->color = channel->color;
}
/// <summary>
/// Destructor
/// </summary>
LmkImageChannel::~LmkImageChannel() {
	// release managed resource
	delete this->data;

	this->!LmkImageChannel();
}
/// <summary>
/// Finalizer
/// </summary>
LmkImageChannel::!LmkImageChannel() {
	// release unmanaged resource
}

LmkImageChannel^ LmkImageChannel::Clone() {
	return gcnew LmkImageChannel(this);
}


LmkImageChannel::LmkImageChannel(byte* data, int width, int height, ColorType colorType)
{
	this->data = data;
	this->width = width;
	this->height = height;
	this->color = colorType;
}

ColorType LmkImageChannel::Color::get() {
	return this->color;
}
IntPtr LmkImageChannel::Data::get() {
	return (IntPtr)this->data;
}
int LmkImageChannel::Width::get() {
	return this->width;
}
int LmkImageChannel::Height::get() {
	return this->height;
}


LmkImage::LmkImage() {
	this->width = 0;
	this->height = 0;
	this->channel = gcnew array<LmkImageChannel^>{};
	this->tags = nullptr;
}
/// <summary>
/// Copy constructor
/// </summary>
/// <param name="image">copied image</param>
LmkImage::LmkImage(LmkImage^ image)
{
	this->width = image->width;
	this->height = image->height;
	this->channel = gcnew array<LmkImageChannel^>(image->channel->Length);
	for (int i = 0; i < image->channel->Length; i++)
	{
		this->channel[i] = image->channel[i]->Clone();
	}
	this->tags = image->tags;
}
/// <summary>
/// Destructor
/// </summary>
LmkImage::~LmkImage() {
	// release managed resource

	this->!LmkImage();
}
/// <summary>
/// Finalizer
/// </summary>
LmkImage::!LmkImage() {
	// release unmanaged resource
}
/// <summary>
/// Copy object
/// </summary>
LmkImage^ LmkImage::Clone() {
	return gcnew LmkImage(this);
}
bool LmkImage::ContainChannel(ColorType colorType) {
	for (int i = 0; i < this->Channel->Length; i++) {
		if (this->Channel[i]->Color == colorType)
			return true;
	}
	return false;
}
LmkImage^ LmkImage::ExtractChannel(ColorType colorType) {
	LmkImageChannel^ channel = nullptr;
	for (int i = 0; i < this->Channel->Length; i++) {
		if (this->Channel[i]->Color == colorType)
		{
			channel = this->Channel[i];
			break;
		}
	}
	if (channel == nullptr)
		return nullptr;
	else
		return gcnew LmkImage(gcnew array<LmkImageChannel^> { channel });
}

/// <summary>
/// From channel object
/// </summary>
/// <param name="image">copied image</param>
LmkImage::LmkImage(array<LmkImageChannel^>^ channel)
{
	if (channel == nullptr)
		throw gcnew System::ArgumentNullException();
	else if (channel->Length == 0)
		throw gcnew System::ArgumentException();

	// get first channel
	LmkImageChannel^ first = channel[0];

	this->width = first->Width;
	this->height = first->Height;
	this->channel = channel;
	this->tags = "";
}
array<LmkImageChannel^>^ LmkImage::Channel::get() {
	return this->channel;
}
int LmkImage::Width::get() {
	return this->width;
}
int LmkImage::Height::get() {
	return this->height;
}
String^ LmkImage::Tags::get() {
	return this->tags;
}

