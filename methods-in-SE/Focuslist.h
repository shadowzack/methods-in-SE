#pragma once
#include "Button.h"

class Focuslist : public Button {

public:
	Focuslist(int width);
	virtual bool canGetFocus() { return true; }
	virtual string className() { return "Focuslist"; }

};