#ifndef NUMERICBOX_H
#define NUMERICBOX_H

#pragma once
#include "Panel.h"
#include"Button.h"

class NumericBox : public Panel {
protected:
	int _min;
	int _max;
	int _value;
public:
	//ctor && dtor
	NumericBox(int width, int min, int max);
	~NumericBox() {}
	//setters
	inline virtual void setLeft(int left);
	inline virtual void setTop(int top);
	//getters
	bool setValue(int value);
	int getValue();

	virtual bool canGetFocus() { return false; }
	virtual string className() { return "NumericBox"; }
	virtual void mousePressed(int x, int y, bool isLeft);
};

/*
* Inline Methods
*/

void NumericBox::setTop(int top) {
	_top = top;
	for (int i = 0; i < _controls.size(); i++) {
		_controls[i]->setTop(0);
	}

}
void NumericBox::setLeft(int left) {
	_left = left;
	for (int i = 0; i < _controls.size(); i++) {
		if (i == 0) {
			_controls[i]->setLeft(0);
		}
		else {
			_controls[i]->setLeft(_controls[i - 1]->getWidth() + _controls[i - 1]->getLeft());
		}
	}

}

//button plus 
class Plus_button :public MouseListener {
public:
	Plus_button() {}
	virtual void MousePressed(Control &control, int x, int y, bool isLeft) {
		NumericBox * tmp = static_cast<NumericBox*>(&control);
		tmp->setValue(tmp->getValue() + 1);
	}
};

//button minus
class Minus_button :public MouseListener {
public:
	virtual void MousePressed(Control &control, int x, int y, bool isLeft) {
		NumericBox * tmp = static_cast<NumericBox*>(&control);
		tmp->setValue(tmp->getValue() - 1);
	}
};

#endif
