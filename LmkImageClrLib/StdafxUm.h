#pragma once

#include <cmath>

typedef unsigned char byte;

namespace LmkImageClrLibUm {

	/// <summary>
	/// run 
	/// </summary>
	typedef struct run
	{
		int row;
		int column_begin;
		int column_end;
	} run;

	/// <summary>
	/// run array
	/// </summary>
	typedef struct run_length
	{
		int size;
		run* run_ptr;
	} run_length;

	/// <summary>
	/// 2D point
	/// </summary>
	typedef struct coor2d
	{
		double x;
		double y;
	} coor2d;

	/// <summary>
	/// 2D point array
	/// </summary>
	typedef struct coor_array
	{
		int size;
		coor2d* arr;
	} coor_array;

	/// <summary>
	/// 2D Matrix
	/// </summary>
	typedef struct matrix2d
	{
		double m11;
		double m12;
		double offset1;
		double m21;
		double m22;
		double offset2;
	} matrix2d;

	/// <summary>
	/// Rotation of 2d coordinate 
	/// </summary>
	/// <param name="coor">original 2d coordinate</param>
	/// <param name="angle">counter-clockwise radian angle</param>
	/// <returns>rotated coordinate</returns>
	coor2d Rotate(coor2d coor, double angle);
	/// <summary>
	/// Rotation of 2d coordinate 
	/// </summary>
	/// <param name="coor">original 2d coordinate</param>
	/// <param name="matrix">affine transform matrix</param>
	/// <returns>transformed coordinate</returns>
	coor2d Transform(coor2d coor, matrix2d* matrix);
}

