#pragma once

#include "Stdafx.h"

#include "LmkBase.h"

namespace LmkImageClrLib {

	/// <summary>
	/// Rectangle
	/// </summary>
	public ref class LmkRectangle : LmkBase
	{
	public:
		/// <summary>
		/// Constructor
		/// </summary>
		LmkRectangle();
		/// <summary>
		/// Constructor
		/// </summary>
		LmkRectangle(double row, double column, double width, double height);

		/// <summary>
		/// Row
		/// </summary>
		property double Row;
		/// <summary>
		/// Column
		/// </summary>
		property double Column;
		/// <summary>
		/// Width
		/// </summary>
		property double Width;
		/// <summary>
		/// Height
		/// </summary>
		property double Height;
		/// <summary>
		/// Angle (unclock-wise, radian)
		/// </summary>
		property double Angle;
	};

}
