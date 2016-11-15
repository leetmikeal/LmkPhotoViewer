// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently,
// but are changed infrequently

#pragma once

//using namespace System;
//using namespace LmkImageClrLib;
//using namespace LmkImageClrLibUm;

typedef unsigned char byte;

namespace LmkImageClrLib {

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
