#pragma once

#include "Stdafx.h"

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
		/// Image width
		/// </summary>
		property int Width;
		/// <summary>
		/// Image height
		/// </summary>
		property int Height;
		/// <summary>
		/// Content
		/// </summary>
		property IntPtr^ Data;
		/// <summary>
		/// Tags
		/// </summary>
		property String^ Tags;
	};

}
