#include "Stdafx.h"
#include "StdafxUm.h"

#include "LmkMatrix.h"

using namespace LmkImageLib;

/// <summary>
/// Rotation of 2d coordinate 
/// </summary>
/// <param name="coor">original 2d coordinate</param>
/// <param name="angle">counter-clockwise radian angle</param>
/// <returns>rotated coordinate</returns>
coor2d Rotate(coor2d coor, double angle) {
	coor2d rtn;
	rtn.x = coor.x * cos(angle) - coor.y * sin(angle);
	rtn.y = coor.x * sin(angle) + coor.y * cos(angle);
	return rtn;
}

/// <summary>
/// Transform of 2d coordinate 
/// </summary>
/// <param name="coor">original 2d coordinate</param>
/// <param name="matrix">affine transofrm matrix</param>
/// <returns>rotated coordinate</returns>
coor2d Transform(coor2d coor, matrix2d* matrix) { 
	coor2d rtn;
	rtn.x = coor.x * matrix->m11 + coor.y * matrix->m12 + matrix->offset1;
	rtn.y = coor.x * matrix->m21 + coor.y * matrix->m22 + matrix->offset2;
	return rtn;
}

