#include "stdafx.h"
#include "LmkImage.h"

using namespace LmkImageClrLib;

/// <summary>
/// Constructor
/// </summary>
LmkImageChannel::LmkImageChannel()
{
}
/// <summary>
/// Copy constructor
/// </summary>
LmkImageChannel::LmkImageChannel(LmkImageChannel^ channel)
{
	int size = channel->Width * channel->Height;
	byte* newData = new byte[size];
	memcpy(newData, channel->data, sizeof(byte) * size);

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

LmkImageChannel^ LmkImageChannel::Clone()
{
	return gcnew LmkImageChannel(this);
}
ColorType LmkImageChannel::Color::get()
{
	return this->color;
}
IntPtr LmkImageChannel::Data::get()
{
	return (IntPtr)this->data;
}
int LmkImageChannel::Width::get()
{
	return this->width;
}
int LmkImageChannel::Height::get()
{
	return this->height;
}


LmkImage::LmkImage()
{
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
array<LmkImageChannel^>^ LmkImage::Channel::get()
{
	return this->channel;
}
int LmkImage::Width::get()
{
	return this->width;
}
int LmkImage::Height::get()
{
	return this->height;
}
String^ LmkImage::Tags::get()
{
	return this->tags;
}

