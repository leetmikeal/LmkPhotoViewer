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

public ref class LmkOperatorSet
{
public:
	//LmkOperatorSet();
	static LmkRegion^ Threshold(LmkImage^ image, byte minVal, byte maxVal);
	static LmkRegion^ ThresholdMulti(LmkImage^ image, byte minVal, byte maxVal);
};

