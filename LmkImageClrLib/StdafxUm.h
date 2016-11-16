#pragma once

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

}

