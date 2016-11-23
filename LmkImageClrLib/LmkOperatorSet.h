#pragma once

#include "Stdafx.h"
#include "StdafxUm.h"

#include <list>

#include "LmkImage.h"
#include "LmkMatrix.h"
#include "LmkBit.h"
#include "LmkRegion.h"
#include "LmkVector.h"
#include "LmkPointInt.h"
#include "LmkPointDbl.h"
#include "LmkRectangleInt.h"
#include "LmkRectangleDbl.h"

namespace LmkImageLib {
	/// <summary>
	/// Common operator set class
	/// </summary>
	public ref class LmkOperatorSet
	{
	public:
		//LmkOperatorSet();
		static LmkRegion^ Threshold(LmkImage^ image, byte minVal, byte maxVal);
		static array<LmkRegion^>^ ThresholdMulti(LmkImage^ image, byte minVal, byte maxVal);
		static LmkImage^ ConvertColor(LmkImage^ image, ConvertColorType colorType);
	internal:
		static array<Byte>^ Compress(array<Byte>^ row);
		static array<Byte>^ Decompress(array<Byte>^ compressed);
	};
}

