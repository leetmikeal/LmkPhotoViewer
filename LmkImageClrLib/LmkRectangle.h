#pragma once

#include "Stdafx.h"
#include "StdafxUm.h"

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
		/// Copy constructor
		/// </summary>
		LmkRectangle(LmkRectangle^ rectangle);
		/// <summary>
		/// Constructor
		/// </summary>
		LmkRectangle(double row, double column, double width, double height);

		/// <summary>
		/// Copy object
		/// </summary>
		/// <returns>copied object</returns>
		LmkRectangle^ Clone();

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
		property LmkRectangle^ SmallestRectangle { LmkRectangle^ get(); }
	private:
		double row;
		double column;
		double width;
		double height;
		double angle;
	};

}
