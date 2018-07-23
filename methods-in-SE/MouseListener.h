#pragma once
#include "Label.h"


struct MouseListener
{
	virtual void MousePressed(Control &control, int x, int y, bool isLeft) = 0;
};

