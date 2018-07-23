#pragma once
#ifndef LABEL_H
#define LABEL_H

#include "TextBox.h"

class Label :public TextBox {
public:
	Label(int width);
	virtual bool canGetFocus();
	virtual void mousePressed(int x, int y, bool isLeft) {}
};
#endif // !LABEL_H