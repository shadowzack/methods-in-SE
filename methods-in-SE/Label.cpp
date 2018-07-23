#include "stdafx.h"
#include "Label.h"

Label::Label(int width) :TextBox(width) {}
bool Label::canGetFocus() { return false; }