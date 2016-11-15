#pragma once

#include "Stdafx.h"
#include <cmath>
#include <string>

#include "LmkBase.h"

using namespace System;

namespace LmkImageClrLib {

	/// <summary>
	/// 1-bit image
	/// </summary>
	public ref class LmkBit : LmkBase
	{
	public:
		/// <summary>
		/// Constructor
		/// </summary>
		LmkBit();
		/// <summary>
		/// Destructor
		/// </summary>
		~LmkBit() {
			// release managed resource

			this->!LmkBit();
		}
		/// <summary>
		/// Finalizer
		/// </summary>
		!LmkBit() {
			// release unmanaged resource
		}
		/// <summary>
		/// Clone object
		/// </summary>
		/// <returns></returns>
		LmkBit^ Clone();

		/// <summary>
		/// Image bit width
		/// </summary>
		property int Width;
		/// <summary>
		/// Image bit height
		/// </summary>
		property int Height;
		/// <summary>
		/// Image bit size
		/// </summary>
		property int Size
		{
			int get()
			{
				return this->Width * this->Height;
			}
		}
		/// <summary>
		/// byte length width
		/// </summary>
		property int WidthByte
		{
			int get()
			{
				double w = (double)this->Width / sizeof(byte);
				return (int)floor(w);
			}
		}
		/// <summary>
		/// byte length height
		/// </summary>
		property int HeightByte
		{
			int get()
			{
				double h = (double)this->Height / sizeof(byte);
				return (int)floor(h);
			}
		}
		/// <summary>
		/// Image bit size
		/// </summary>
		property int SizeByte
		{
			int get()
			{
				return this->WidthByte * this->HeightByte;
			}
		}
		/// <summary>
		/// Content
		/// </summary>
		property IntPtr^ Data;
		/// <summary>
		/// Tags
		/// </summary>
		property String^ Tags;
	private:
		property byte* dataInstance {
			byte* get()
			{
				byte* ptr = (byte*)Data->ToPointer();
				return ptr;
			}
		}
	};

}
