#pragma once

#include "Stdafx.h"
#include "StdafxUm.h"

#include <limits>

#include "LmkBase.h"
#include "LmkRectangleDbl.h"

using namespace System;
using namespace LmkImageLib;

namespace LmkImageLib {

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
		LmkRegion(LmkRectangleInt^ rectangle);
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
		property LmkRectangleInt^ SmallestRectangle { LmkRectangleInt^ get(); }
		/// <summary>
		/// Region area size
		/// </summary>
		property int AreaSize { int get(); }
	internal:
		/// <summary>
		/// Create by inner object
		/// </summary>
		LmkRegion(run_length* rl);
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
		LmkRectangleInt^ smallestRectangle;
	};

}
