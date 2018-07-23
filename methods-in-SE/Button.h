#pragma once
#include "Label.h"


struct MouseListener
{
	virtual void MousePressed(Control &control, int x, int y, bool isLeft) = 0;
};


class Button : public Label {
protected:
	MouseListener * _listener;
public:
	Button(int width);
	void addListener(MouseListener &listener);
	virtual bool canGetFocus() { return false; }
	virtual void mousePressed(int x, int y, bool isLeft);
	inline MouseListener& getListener();
	virtual string className() { return "Button"; }

};

MouseListener& Button::getListener() {
	return *_listener;
}
