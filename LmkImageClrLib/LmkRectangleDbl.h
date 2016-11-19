#pragma once

#include "Stdafx.h"
#include "StdafxUm.h"

#include "LmkBase.h"

namespace LmkImageClrLib {

	/// <summary>
	/// Double type rectangle
	/// </summary>
	public ref class LmkRectangleDbl : LmkBase
	{
	public:
		/// <summary>
		/// Constructor
		/// </summary>
		LmkRectangleDbl();
		/// <summary>
		/// Copy constructor
		/// </summary>
		LmkRectangleDbl(LmkRectangleDbl^ rectangle);
		/// <summary>
		/// Constructor
		/// </summary>
		LmkRectangleDbl(double row, double column, double width, double height);

		/// <summary>
		/// Copy object
		/// </summary>
		/// <returns>copied object</returns>
		LmkRectangleDbl^ Clone();

		/// <summary>
		/// Row
		/// </summary>
		property double Row { double get(); }
		/// <summary>
		/// Column
		/// </summary>
		property double Column { double get(); }
		/// <summary>
		/// Width
		/// </summary>
		property double Width { double get(); }
		/// <summary>
		/// Height
		/// </summary>
		property double Height { double get(); }
		/// <summary>
		/// Angle (unclock-wise, radian)
		/// </summary>
		property double Angle { double get(); }
		/// <summary>
		/// Smallest rectangle. disabled rotation.
		/// </summary>
		property LmkRectangleDbl^ SmallestRectangle { LmkRectangleDbl^ get(); }
		/// <summary>
		/// Center 2d coordinate
		/// </summary>
		property LmkPointDbl^ Center { LmkPointDbl^ get(); }
	private:
		double row;
		double column;
		double width;
		double height;
		double angle;
	};

}
