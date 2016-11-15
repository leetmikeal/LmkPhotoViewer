#pragma once

#include "Stdafx.h"

#include "LmkBase.h"

namespace LmkImageClrLib {

	/// <summary>
	/// Affine trans matrix
	/// </summary>
	public ref class LmkMatrix : LmkBase
	{
	public:
		/// <summary>
		/// Constructor
		/// </summary>
		LmkMatrix();
		/// <summary>
		/// Destructor
		/// </summary>
		~LmkMatrix() {
			// release managed resource
			delete elements;

			this->!LmkMatrix();
		}
		/// <summary>
		/// Finalizer
		/// </summary>
		!LmkMatrix() {
			// release unmanaged resource
		}

		/// <summary>
		/// (1, 1) value
		/// </summary>
		property double M11 
		{
			double get()
			{
				return this->elements[0];
			}
		}
		/// <summary>
		/// (1, 2) value
		/// </summary>
		property double M12
		{
			double get()
			{
				return this->elements[1];
			}
		}
		/// <summary>
		/// (2, 1) value
		/// </summary>
		property double M21
		{
			double get()
			{
				return this->elements[3];
			}
		}
		/// <summary>
		/// (2, 2) value
		/// </summary>
		property double M22
		{
			double get()
			{
				return this->elements[4];
			}
		}
		/// <summary>
		/// Offset Column (X axis)
		/// </summary>
		property double Offset1
		{
			double get()
			{
				return this->elements[2];
			}
		}
		/// <summary>
		/// Offset Row (Y axis)
		/// </summary>
		property double Offset2
		{
			double get()
			{
				return this->elements[5];
			}
		}
	private:
		byte* elements;

	};

}
