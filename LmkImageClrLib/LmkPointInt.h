#pragma once

#include "Stdafx.h"

#include "LmkBase.h"

namespace LmkImageClrLib {

	/// <summary>
	/// 2D point
	/// </summary>
	public value class LmkPointInt
	{
	public:
		/// <summary>
		/// Constructor
		/// </summary>
		LmkPointInt(int x, int y);
		/// <summary>
		/// X (Column)
		/// </summary>
		property int X { int get(); }
		/// <summary>
		/// Y (Row)
		/// </summary>
		property int Y { int get(); }
	private:
		/// <summary>
		/// X (Column)
		/// </summary>
		int x;
		/// <summary>
		/// Y (Row)
		/// </summary>
		int y;
	};

}
