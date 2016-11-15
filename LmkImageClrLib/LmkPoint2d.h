#pragma once

#include "Stdafx.h"

#include "LmkBase.h"

namespace LmkImageClrLib {

	/// <summary>
	/// 2D point
	/// </summary>
	public ref class LmkPoint2d : LmkBase
	{
	public:
		LmkPoint2d();

		/// <summary>
		/// X (Column)
		/// </summary>
		property double X;
		/// <summary>
		/// Y (Row)
		/// </summary>
		property double Y;
	};

}
