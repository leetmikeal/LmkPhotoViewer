#pragma once

#include "Stdafx.h"
#include "StdafxUm.h"

#include <cmath>

#include "LmkBase.h"

using namespace LmkImageClrLibUm;

namespace LmkImageClrLib {

	/// <summary>
	/// Affine trans matrix
    /// 
    /// Matrix element is composed by 6 values;
    /// [[m11, m12, offset1], [m12, m22, offset2]]
    /// 3rd row [0, 0, 1] is abbreviated.
    /// 
    /// Transformation is operated by left hand at 2D coordinate matrix [x, y, 0].
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
		~LmkMatrix();
		/// <summary>
		/// Finalizer
		/// </summary>
		!LmkMatrix();
		/// <summary>
		/// Initialize elements
		/// </summary>
		LmkMatrix(double m11, double m12, double m21, double m22, double offset1, double offset2);

		/// <summary>
		/// Translate
		/// </summary>
		/// <param name="x">Column</param>
		/// <param name="y">Row</param>
		/// <returns>trnalating matrix</returns>
		LmkMatrix^ Translate(double x, double y);
		/// <summary>
		/// Prepend translate
		/// </summary>
		/// <param name="x">Column value</param>
		/// <param name="y">Row value</param>
		/// <returns>translating matrix</returns>
		LmkMatrix^ TranslatePre(double x, double y);
		/// <summary>
		/// Scale
		/// </summary>
		/// <param name="column">Column value</param>
		/// <param name="row">Row value</param>
		/// <returns>scaling matrix</returns>
		LmkMatrix^ Scale(double column, double row);
		/// <summary>
		/// Prepend scale
		/// </summary>
		/// <param name="column">Column value</param>
		/// <param name="row">Row value</param>
		/// <returns>scaling matrix</returns>
		LmkMatrix^ ScalePre(double column, double row);
		/// <summary>
		/// Rotate
		/// </summary>
		/// <param name="angle">rotation angle [radian] (counter-clockwise)</param>
		/// <returns>rotation matrix</returns>
		LmkMatrix^ Rotate(double angle);
		/// <summary>
		/// Rotate
		/// </summary>
		/// <param name="angle">rotation angle [radian] (counter-clockwise)</param>
		/// <param name="x">column of rotation center</param>
		/// <param name="y">row of rotation center</param>
		/// <returns>rotation matrix</returns>
		LmkMatrix^ Rotate(double angle, double x, double y);
		/// <summary>
		/// Prepend rotate
		/// </summary>
		/// <param name="angle">rotation angle [radian] (counter-clockwise)</param>
		/// <returns>rotation matrix</returns>
		LmkMatrix^ RotatePre(double angle);

		/// <summary>
		/// (1, 1) value
		/// </summary>
		property double M11 { double get(); }
		/// <summary>
		/// (1, 2) value
		/// </summary>
		property double M12 { double get(); }
		/// <summary>
		/// (2, 1) value
		/// </summary>
		property double M21 { double get(); }
		/// <summary>
		/// (2, 2) value
		/// </summary>
		property double M22 { double get(); }
		/// <summary>
		/// Offset Column (X axis)
		/// </summary>
		property double Offset1 { double get(); }
		/// <summary>
		/// Offset Row (Y axis)
		/// </summary>
		property double Offset2 { double get(); }
		/// <summary>
		/// Identity matrix
		/// </summary>
		property static LmkMatrix^ Identity { LmkMatrix^ get(); }
		/// <summary>
		/// Elements pointer
		/// </summary>
		property matrix2d* ElementsPointer { matrix2d* get(); }
	private:
		matrix2d* elements;
	};

}
