#pragma once
#ifndef TEXTBOX_H
#define TEXTBOX_H

#include "Control.h"

class TextBox : public Control {
protected:
	wstring _text;
public:
	//ctor && dtor
	TextBox(int width);
	virtual ~TextBox() = default;

	virtual void restCursor() { _cursorPositionx = _text.size() + this->getLeft() + 1; }
	//setters
	void setText(wstring value);
	//getters
	wstring getText() const;
	//control 
	virtual void draw(Graphics& g, int x, int y, size_t z);
	virtual void mousePressed(int x, int y, bool isLeft);
	void keyDown(int keyCode, char charecter);
	virtual bool canGetFocus();
	virtual string className() { return "TextBox"; }
	virtual void setLeft(int left);
};

#endif // !TEXTBOX_H