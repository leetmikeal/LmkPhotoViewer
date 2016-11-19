#pragma once

#include "Stdafx.h"
#include "StdafxUm.h"

#include "LmkBase.h"

namespace LmkImageClrLib {

	/// <summary>
	/// Integer type rectangle
	/// </summary>
	public ref class LmkRectangleInt : LmkBase
	{
	public:
		/// <summary>
		/// Constructor
		/// </summary>
		LmkRectangleInt();
		/// <summary>
		/// Copy constructor
		/// </summary>
		LmkRectangleInt(LmkRectangleInt^ rectangle);
		/// <summary>
		/// Constructor
		/// </summary>
		LmkRectangleInt(int row, int column, int width, int height);
		/// <summary>
		/// Convert to double type rectangle
		/// </summary>
		LmkRectangleDbl^ ToDouble();

		/// <summary>
		/// Copy object
		/// </summary>
		/// <returns>copied object</returns>
		LmkRectangleInt^ Clone();

		/// <summary>
		/// Row
		/// </summary>
		property int Row { int get(); }
		/// <summary>
		/// Column
		/// </summary>
		property int Column { int get(); }
		/// <summary>
		/// Width
		/// </summary>
		property int Width { int get(); }
		/// <summary>
		/// Height
		/// </summary>
		property int Height { int get(); }
	private:
		int row;
		int column;
		int width;
		int height;
	};

}