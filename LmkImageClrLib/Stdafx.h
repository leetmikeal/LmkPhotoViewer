// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently,
// but are changed infrequently

#pragma once

//#include <cstdio>
//#include <cstring>

//using namespace System;
//using namespace LmkImageClrLib;
//using namespace LmkImageClrLibUm;

typedef unsigned char byte;

namespace LmkImageClrLib {

	ref class LmkRectangle;
	ref class LmkRegion;
	ref class LmkVector;
	ref class LmkBit;
	ref class LmkImage;
	ref class LmkMatrix;
	value class LmkPoint2d;

	/// <summary>
	/// Image color type
	/// </summary>
	public enum class ColorType : int
	{
		Red,
		Green,
		Blue,
		Hue,
		Saturation,
		Brightness,
	};
}
