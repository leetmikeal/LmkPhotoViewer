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

}

