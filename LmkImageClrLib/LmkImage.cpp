#include "stdafx.h"
#include "LmkImage.h"
#include "LmkOperatorSet.h"

using namespace LmkImageLib;
using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;


#pragma region LmkImageChannel
#pragma region Constructor
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

LmkImageChannel::LmkImageChannel(byte* data, int width, int height, ColorType colorType)
{
	this->data = data;
	this->width = width;
	this->height = height;
	this->color = colorType;
}
#pragma endregion

#pragma region Method
LmkImageChannel^ LmkImageChannel::Clone() {
	return gcnew LmkImageChannel(this);
}
#pragma endregion

#pragma region Property
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
#pragma endregion
#pragma endregion


#pragma region LmkImage
#pragma region Constructor
/// <summary>
/// Constructor
/// </summary>
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
#pragma endregion

#pragma region Method
/// <summary>
/// Load from image file
/// </summary>
LmkImage::LmkImage(String^ filePath) {
	//const char* c = static_cast<const char*>(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(filePath)->ToPointer());
	const char* c = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(filePath);
	cv::Mat cvImage = cv::imread(c, cv::IMREAD_ANYCOLOR);
	System::Runtime::InteropServices::Marshal::FreeHGlobal((IntPtr)((void*)c));

	this->width = cvImage.cols;
	this->height = cvImage.rows;

	int size = cvImage.rows * cvImage.cols;
	if (cvImage.channels() == 1) // gray
	{
		byte* d = new byte[size];
		std::memcpy(d, cvImage.data, size);
		LmkImageChannel^ channel = gcnew LmkImageChannel(d, cvImage.cols, cvImage.rows, ColorType::Brightness);
		this->channel = gcnew array<LmkImageChannel^> { channel };
		this->tags = "";
	}
	else if (cvImage.channels() == 3) // RGB color image
	{
		cv::Mat cvChannel[3];
		cv::split(cvImage, cvChannel);
		this->channel = gcnew array<LmkImageChannel^>(3);
		for (int i = 0; i < 3; i++)
		{
			byte* d = new byte[size];
			std::memcpy(d, cvChannel[i].data, size);
			this->channel[i] = gcnew LmkImageChannel(d, cvImage.cols, cvImage.rows, ColorType::Brightness);
		}
		this->channel = gcnew array<LmkImageChannel^>{};
		this->tags = nullptr;

		cvChannel->release();
	}

	cvImage.release();
}
/// <summary>
/// Copy object
/// </summary>
LmkImage^ LmkImage::Clone() {
	return gcnew LmkImage(this);
}
/// <summary>
/// Check to contain selecrted color in a image
/// </summary>
/// <param name="colorType">selected color</param>
/// <returns>judge</returns>
bool LmkImage::ContainChannel(ColorType colorType) {
	for (int i = 0; i < this->Channel->Length; i++) {
		if (this->Channel[i]->Color == colorType)
			return true;
	}
	return false;
}
/// <summary>
/// Extract specific color single channel image
/// </summary>
/// <param name="colorType">selected color</param>
/// <returns>extracted image</returns>
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
#pragma endregion

#pragma region Method
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
array<Byte>^ LmkImage::D::get() {
	List<Byte>^ byteList = gcnew List<Byte>();
	// tag
	array<Byte>^ tagsByte = System::Text::Encoding::UTF8->GetBytes(this->tags->ToCharArray());
	array<Byte>^ tagsSize = BitConverter::GetBytes(tagsByte->Length);
	byteList->AddRange(tagsSize);
	byteList->AddRange(tagsByte);

	// channel count
	array<Byte>^ widthByte = BitConverter::GetBytes(this->Width);
	array<Byte>^ heightByte = BitConverter::GetBytes(this->Height);
	array<Byte>^ channelCountByte = BitConverter::GetBytes(this->Channel->Length);
	byteList->AddRange(widthByte);
	byteList->AddRange(heightByte);
	byteList->AddRange(channelCountByte);

	// each channel loop
	int size = this->width * this->height;
	for (int i = 0; i < this->Channel->Length; i++)
	{
		// color
		array<Byte>^ colorTypeByte = BitConverter::GetBytes((int)this->Channel[i]->Color);
		byteList->AddRange(colorTypeByte);

		// data
		array<Byte>^ dataArray = gcnew array<Byte>(size);
		System::Runtime::InteropServices::Marshal::Copy((IntPtr)this->Channel[i]->Data, dataArray, 0, size);
		array<Byte>^ compressed = LmkOperatorSet::Compress(dataArray);
		array<Byte>^ dataSizeByte = BitConverter::GetBytes(compressed->Length);
		byteList->AddRange(dataSizeByte);
		byteList->AddRange(compressed);
	}

	return byteList->ToArray();
}
void LmkImage::D::set(array<Byte>^ value) {
	// tag
	int tagsSize = BitConverter::ToInt32(value, 0);
	array<Byte>^ tagsByte;
	System::Array::Copy(value, tagsByte, tagsSize);
	this->tags = System::Text::Encoding::UTF8->GetString(tagsByte);

	// channel count
	int arrPtr = sizeof(int) + tagsSize;
	int width = BitConverter::ToInt32(value, arrPtr);
	int height = BitConverter::ToInt32(value, arrPtr + sizeof(int));
	int channelCount = BitConverter::ToInt32(value, arrPtr + sizeof(int) * 2);

	// each channel loop
	arrPtr += sizeof(int) * 3;
	this->channel = gcnew array<LmkImageChannel^>(channelCount);
	for (int i = 0; i < channelCount; i++)
	{
		int colorTypeInt = BitConverter::ToInt32(value, arrPtr);
		arrPtr += sizeof(int);

		int channelSize = BitConverter::ToInt32(value, arrPtr);
		arrPtr += sizeof(int);

		array<Byte>^ compressed;
		System::Array::Copy(value, arrPtr, compressed, 0, channelSize);
		array<Byte>^ dataArray = LmkOperatorSet::Decompress(compressed);
		byte* data = new byte[dataArray->Length];
		System::Runtime::InteropServices::Marshal::Copy(dataArray, 0, (IntPtr)data, dataArray->Length);
		LmkImageChannel^ channel = gcnew LmkImageChannel(data, width, height, (ColorType)colorTypeInt);
		this->channel[i] = channel;

		arrPtr += channelSize;
	}

}
#pragma endregion
#pragma endregion

