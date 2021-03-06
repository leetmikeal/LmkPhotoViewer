#pragma once

#include "Stdafx.h"

#include <stdio.h>
#include <string.h>
#include <iostream>

#include "LmkBase.h"

using namespace System;

namespace LmkImageLib {

	public ref class LmkImageChannel : LmkBase
	{
#pragma region Constructor
	public:
		/// <summary>
		/// Constructor
		/// </summary>
		LmkImageChannel();
		/// <summary>
		/// Copy constructor
		/// </summary>
		LmkImageChannel(LmkImageChannel^ channel);
		/// <summary>
		/// Destructor
		/// </summary>
		~LmkImageChannel();
		/// <summary>
		/// Finalizer
		/// </summary>
		!LmkImageChannel();
#pragma endregion

#pragma region Method
	public:
		/// <summary>
		/// Copy object
		/// </summary>
		/// <returns></returns>
		LmkImageChannel^ Clone();
	internal:
		/// <summary>
		/// From byte array
		/// </summary>
		LmkImageChannel(byte* data, int width, int height, ColorType colorType);
#pragma endregion

#pragma region Property
	public:
		/// <summary>
		/// color type
		/// </summary>
		property ColorType Color { ColorType get(); }
		/// <summary>
		/// byte array
		/// </summary>
		property IntPtr Data { IntPtr get(); }
		/// <summary>
		/// Image width
		/// </summary>
		property int Width { int get(); }
		/// <summary>
		/// Image height
		/// </summary>
		property int Height { int get(); }
#pragma endregion

#pragma region Field
	internal:
		ColorType color;
		byte* data;
		int width;
		int height;
#pragma endregion

	};

	/// <summary>
	/// Generic image class
	/// 
	/// 8-bit multi channel
	/// </summary>
	[System::Runtime::Serialization::DataContract(Namespace = "")]
	public ref class LmkImage : LmkBase
	{
#pragma region Constructor
	public:
		/// <summary>
		/// Constructor
		/// </summary>
		LmkImage();
		/// <summary>
		/// Copy constructor
		/// </summary>
		LmkImage(LmkImage^ image);
		/// <summary>
		/// load from image file
		/// </summary>
		LmkImage(String^ filePath);
		/// <summary>
		/// Destructor
		/// </summary>
		~LmkImage();
		/// <summary>
		/// Finalizer
		/// </summary>
		!LmkImage();
	internal:
		/// <summary>
		/// From channel object
		/// </summary>
		LmkImage(array<LmkImageChannel^>^ image);
#pragma endregion

#pragma region Method
	public:
		/// <summary>
		/// Copy object
		/// </summary>
		LmkImage^ Clone();
		/// <summary>
		/// Check contained color channel
		/// </summary>
		bool ContainChannel(ColorType colorType);
		/// <summary>
		/// Extract single channel image
		/// </summary>
		LmkImage^ ExtractChannel(ColorType colorType);
#pragma endregion

#pragma region Property
	public:
		/// <summary>
		/// Image width
		/// </summary>
		property int Width { int get(); }
		/// <summary>
		/// Image height
		/// </summary>
		property int Height { int get(); }
		/// <summary>
		/// Image height
		/// </summary>
		property array<LmkImageChannel^>^ Channel { array<LmkImageChannel^>^ get(); }
		/// <summary>
		/// Tags
		/// </summary>
		property String^ Tags { String^ get(); }
		/// <summary>
		/// Image height
		/// </summary>
		[System::Runtime::Serialization::DataMember(Name = "D")]
		property array<Byte>^ D { array<Byte>^ get(); void set(array<Byte>^ value); }
#pragma endregion

#pragma region Field
	internal:
		int width;
		int height;
		array<LmkImageChannel^>^ channel;
		String^ tags;
#pragma endregion 

	};
}
