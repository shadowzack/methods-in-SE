#pragma once
#ifndef MOUSELISTENER_H
#define MOUSELISTENER_H
#include "Label.h"

struct MouseListener
{
	virtual void MousePressed(Control &control, int x, int y, bool isLeft) = 0;
};
#endif // !MOUSELISTENER_H
