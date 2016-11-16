#pragma once

#include "Stdafx.h"
#include "StdafxUm.h"

#include "LmkBase.h"
#include "LmkRectangle.h"

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
		LmkRegion(int row, int column, int width, int height);
		/// <summary>
		/// Destructor
		/// </summary>
		~LmkRegion();
		/// <summary>
		/// Finalizer
		/// </summary>
		!LmkRegion();

		property LmkRectangle^ SmallestRectangle { LmkRectangle^ get(); }
	private:
		property run_length* rl;
	};

}
