#pragma once

#include "Stdafx.h"
#include "StdafxUm.h"

#include <stdio.h>
#include <limits>

#include "LmkBase.h"
#include "LmkRectangleDbl.h"

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
		/// Copy constructor
		/// </summary>
		LmkVector(LmkVector^ vector);
		/// <summary>
		/// From rectangle
		/// </summary>
		LmkVector(LmkRectangleDbl^ rectangle);
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
		property LmkRectangleDbl^ SmallestRectangle { LmkRectangleDbl^ get(); }
	private:
		/// <summary>
		/// coordinate body
		/// </summary>
		coor_array* coor;
		/// <summary>
		/// Smallest rectangle cache
		/// </summary>
		LmkRectangleDbl^ smallestRectangle;
	};

}
