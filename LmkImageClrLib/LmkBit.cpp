#include "stdafx.h"
#include "LmkBit.h"

using namespace LmkImageClrLib;

LmkBit::LmkBit()
{
}

LmkBit^ LmkBit::Clone()
{
	LmkBit^ newObj = gcnew LmkBit();
	newObj->Width = this->Width;
	newObj->Height = this->Height;
	byte* newByte = nullptr;
	std::memcpy(newByte, this->dataInstance, this->SizeByte);
	newObj->Data = gcnew IntPtr(newByte);
	newObj->Tags = this->Tags;

	return newObj;
}
