#pragma once

#include "StdafxUm.h"

#include <cmath>

namespace LmkImageClrLibUm {
	/// <summary>
	/// Common unmanaged operator set class
	/// </summary>
	private class LmkOperatorSetUm
	{
	public:
		/// <summary>
		/// converting rgb color to gray image
		/// </summary>
		/// <param name="red">red channel byte array</param>
		/// <param name="green">green channel byte array</param>
		/// <param name="blue">blue channel byte array</param>
		/// <param name="width">image width</param>
		/// <param name="height">image height</param>
		static byte* RgbToGray(byte* red, byte* green, byte* blue, int width, int height);
	};
}
