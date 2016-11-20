#pragma once

#include "Stdafx.h"

#include <stdio.h>
#include <string.h>

#include "LmkBase.h"

using namespace System;

namespace LmkImageClrLib {

	public ref class LmkImageChannel : LmkBase
	{
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
		/// <summary>
		/// Copy object
		/// </summary>
		/// <returns></returns>
		LmkImageChannel^ Clone();

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
	internal:
		/// <summary>
		/// From byte array
		/// </summary>
		LmkImageChannel(byte* data, int width, int height, ColorType colorType);
		ColorType color;
		byte* data;
		int width;
		int height;
	};

	/// <summary>
	/// Generic image class
	/// 
	/// 8-bit multi channel
	/// </summary>
	[System::Runtime::Serialization::DataContract(Namespace = "")]
	public ref class LmkImage : LmkBase
	{
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
		/// Destructor
		/// </summary>
		~LmkImage();
		/// <summary>
		/// Finalizer
		/// </summary>
		!LmkImage();
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
	internal:
		/// <summary>
		/// From channel object
		/// </summary>
		LmkImage(array<LmkImageChannel^>^ image);
		int width;
		int height;
		array<LmkImageChannel^>^ channel;
		String^ tags;

	};
}
