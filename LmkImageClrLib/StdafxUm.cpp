#include "stdafx.h"
#include "StdafxUm.h"

namespace LmkImageClrLibUm
{
	/// <summary>
	/// Rotation of 2d coordinate 
	/// </summary>
	/// <param name="coor">original 2d coordinate</param>
	/// <param name="angle">counter-clockwise radian angle</param>
	/// <returns>rotated coordinate</returns>
	coor2d Rotate(coor2d coor, double angle)
	{
		coor2d rtn;
		rtn.x = coor.x * cos(angle) - coor.y * sin(angle);
		rtn.y = coor.x * sin(angle) + coor.y * cos(angle);
		return rtn;
	}
}
