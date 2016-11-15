#pragma once

#include "Stdafx.h"
#include "StdafxUm.h"

#include "LmkBase.h"

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
		/// Destructor
		/// </summary>
		~LmkRegion() {
			// release managed resource
			run_length* Rl = (run_length*)(void*)RunLength;
			delete Rl->run_ptr;
			delete Rl;

			this->!LmkRegion();
		}
		/// <summary>
		/// Finalizer
		/// </summary>
		!LmkRegion() {
			// release unmanaged resource
		}

		property IntPtr RunLength;
	};

}
