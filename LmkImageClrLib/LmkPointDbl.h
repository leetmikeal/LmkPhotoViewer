#pragma once

#include "Stdafx.h"

#include "LmkBase.h"

namespace LmkImageClrLib {

	/// <summary>
	/// 2D point
	/// </summary>
	public value class LmkPointDbl
	{
	public:
		/// <summary>
		/// Constructor
		/// </summary>
		LmkPointDbl(double x, double y);
		/// <summary>
		/// X (Column)
		/// </summary>
		property double X { double get(); }
		/// <summary>
		/// Y (Row)
		/// </summary>
		property double Y { double get(); }
	private:
		/// <summary>
		/// X (Column)
		/// </summary>
		double x;
		/// <summary>
		/// Y (Row)
		/// </summary>
		double y;
	};

}