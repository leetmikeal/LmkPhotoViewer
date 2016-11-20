// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently,
// but are changed infrequently

#pragma once

#include "StdafxUm.h"
//#include <cstdio>
//#include <cstring>

//using namespace System;
//using namespace LmkImageClrLib;
//using namespace LmkImageClrLibUm;

namespace LmkImageClrLib {

	ref class LmkRectangleInt;
	ref class LmkRectangleDbl;
	ref class LmkRegion;
	ref class LmkVector;
	ref class LmkBit;
	ref class LmkImage;
	ref class LmkMatrix;
	value class LmkPointInt;
	value class LmkPointDbl;

	/// <summary>
	/// Image color type
	/// </summary>
	public enum class ColorType : int
	{
		None,
		Red,
		Green,
		Blue,
		Hue,
		Saturation,
		Brightness,
	};

	/// <summary>
	/// Image color converting type
	/// </summary>
	public enum class ConvertColorType : int
	{
		RgbToGray,
	};
}
