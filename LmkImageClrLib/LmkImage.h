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
		LmkImageChannel(LmkImageChannel^ image);
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
	internal:
		int width;
		int height;
		array<LmkImageChannel^>^ channel;
		String^ tags;

	};
}
