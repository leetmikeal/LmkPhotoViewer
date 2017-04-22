#pragma once

#include "Stdafx.h"
#include <cmath>
#include <string>

#include "LmkBase.h"

using namespace System;

namespace LmkImageLib {

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
		~LmkBit();
		/// <summary>
		/// Finalizer
		/// </summary>
		!LmkBit();
		/// <summary>
		/// Copy constructor
		/// </summary>
		LmkBit(LmkBit^ bit);
		/// <summary>
		/// Clone object
		/// </summary>
		/// <returns></returns>
		LmkBit^ Clone();

		/// <summary>
		/// Image bit width
		/// </summary>
		property int Width { int get(); }
		/// <summary>
		/// Image bit height
		/// </summary>
		property int Height { int get(); }
		/// <summary>
		/// Image bit size
		/// </summary>
		property int Size { int get(); }
		/// <summary>
		/// byte length width
		/// </summary>
		property int WidthByte { int get(); }
		/// <summary>
		/// byte length height
		/// </summary>
		property int HeightByte { int get(); }
		/// <summary>
		/// Image bit size
		/// </summary>
		property int SizeByte { int get(); }
		/// <summary>
		/// Content
		/// </summary>
		property IntPtr^ Data { IntPtr^ get(); }
		/// <summary>
		/// Tags
		/// </summary
		/// >
		property String^ Tags { String^ get(); }
	private:
		int width;
		int height;
		byte* data;
		String^ tags;
	};

}
