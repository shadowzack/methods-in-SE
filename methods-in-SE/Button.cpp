#include "stdafx.h"
#include "Button.h"

Button::Button(int width) :Label(width) {}

void Button::addListener(MouseListener &listener) {
	_listener = &listener;
}

void Button::mousePressed(int x, int y, bool isLeft) {
	_listener->MousePressed(*this, x, y, isLeft);
}
