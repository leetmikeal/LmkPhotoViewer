#pragma once

#include "Stdafx.h"
#include "StdafxUm.h"

#include <stdio.h>
#include <limits>

#include "LmkBase.h"
#include "LmkRectangle.h"

using namespace System;
using namespace LmkImageClrLibUm;
using namespace LmkImageClrLib;

namespace LmkImageClrLib {

	/// <summary>
	/// 2D line, point array
	/// </summary>
	public ref class LmkVector : LmkBase
	{
	public:
		/// <summary>
		/// Constructor
		/// </summary>
		LmkVector();
		/// <summary>
		/// Destructor
		/// </summary>
		~LmkVector();
		/// <summary>
		/// Finalizer
		/// </summary>
		!LmkVector();

		/// <summary>
		/// Smallest rectangle
		/// </summary>
		property LmkRectangle^ SmallestRectangle { LmkRectangle^ get(); }
	private:
		/// <summary>
		/// coordinate body
		/// </summary>
		coor_array* coor;
		/// <summary>
		/// Smallest rectangle cache
		/// </summary>
		LmkRectangle^ smallestRectangle;
	};

}
