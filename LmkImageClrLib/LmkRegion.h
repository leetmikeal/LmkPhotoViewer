#pragma once

#include "Stdafx.h"
#include "StdafxUm.h"

#include <limits>

#include "LmkBase.h"
#include "LmkRectangleDbl.h"

using namespace System;
using namespace LmkImageClrLibUm;

namespace LmkImageClrLib {

	/// <summary>
	/// region, same as 1-bit image
	/// </summary>
	public ref class LmkRegion : LmkBase
	{
	public:
		/// <summary>
		/// Constructor
		/// </summary>
		LmkRegion();
		/// <summary>
		/// Constructor
		/// </summary>
		LmkRegion(LmkRectangleDbl^ rectangle);
		/// <summary>
		/// from rectangle coordinate
		/// </summary>
		LmkRegion(int row, int column, int width, int height);
		/// <summary>
		/// Destructor
		/// </summary>
		~LmkRegion();
		/// <summary>
		/// Finalizer
		/// </summary>
		!LmkRegion();

		/// <summary>
		/// Smallest Rectangle
		/// </summary>
		property LmkRectangleDbl^ SmallestRectangle { LmkRectangleDbl^ get(); }
		/// <summary>
		/// Region area size
		/// </summary>
		property int AreaSize { int get(); }
	private:
		/// <summary>
		/// Pointer of run length
		/// </summary>
		run_length* rl;
		/// <summary>
		/// Region area size cache
		/// </summary>
		int areaSize;
		/// <summary>
		/// Smallest rectangle cache
		/// </summary>
		LmkRectangleDbl^ smallestRectangle;
	};

}
