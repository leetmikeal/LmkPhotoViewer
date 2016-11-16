#pragma once

#include "Stdafx.h"
#include "StdafxUm.h"

#include <stdio.h>

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

		property LmkRectangle^ SmallestRectangle { LmkRectangle^ get(); }
		//property LmkImageClrLib::LmkRectangle^ SmallestRectangle;
	private:
		coor_array* coor;
	};

}
