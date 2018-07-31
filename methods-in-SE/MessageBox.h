#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

#pragma once
#include "Panel.h"
#include "Button.h"

class Messagebox : public Panel {
	wstring _message;
	bool value;
	MouseListener* _listener;

public:
	//ctor && dtor
	Messagebox(int width, int height, wstring error);
	//setters
	inline virtual void setTop(int top);
	inline  virtual void setLeft(int left);
	inline void setText(wstring in);
	inline MouseListener* getListener()const;
	inline void setValue(bool val);
	//getters
	inline bool isOK()const;

	virtual void draw(Graphics& g, int x, int y, size_t layer);
	virtual void mousePressed(int x, int y, bool isLeft);
	virtual string className() { return "Messagebox"; }
	void addlistener(MouseListener* ms);



};

void Messagebox::setValue(bool val) {
	value = val;
}


void Messagebox::setTop(int top) {
	_top = top;
	_controls[0]->setTop(_height - 3);
	_controls[1]->setTop(_height - 3);
}
void Messagebox::setLeft(int left) {
	_left = left;
	_controls[0]->setLeft(2);
	_controls[1]->setLeft(_width - 9);
}
void Messagebox::setText(wstring in) {
	_message = in;
}
bool Messagebox::isOK()const {
	return value;
}
MouseListener* Messagebox::getListener()const {
	return _listener;
}

#endif
