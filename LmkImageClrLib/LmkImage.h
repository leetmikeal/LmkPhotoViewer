#pragma once

#include "stdafx.h"

#include "LmkBase.h"

using namespace System;

namespace LmkImageClrLib {

	public value class LmkImageChannel
	{
	public:
		/// <summary>
		/// color type
		/// </summary>
		property ColorType ColorType;
		/// <summary>
		/// byte array
		/// </summary>
		property IntPtr Data;
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
		/// Destructor
		/// </summary>
		~LmkImage() {
			// release managed resource
			for each (LmkImageChannel var in Channel)
			{
				byte* d = (byte*)(void*)var.Data;
				delete d;
			}

			this->!LmkImage();
		}
		/// <summary>
		/// Finalizer
		/// </summary>
		!LmkImage() {
			// release unmanaged resource
		}

		/// <summary>
		/// Image width
		/// </summary>
		property int Width;
		/// <summary>
		/// Image height
		/// </summary>
		property int Height;
		/// <summary>
		/// Image height
		/// </summary>
		property array<LmkImageChannel>^ Channel;
		/// <summary>
		/// Tags
		/// </summary>
		property String^ Tags;

	};
}
