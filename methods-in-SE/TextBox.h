#pragma once
#ifndef TEXTBOX_H
#define TEXTBOX_H


#include "Control.h"

class TextBox : public Control {
protected:
	wstring _text;
public:
	TextBox(int width);
	virtual ~TextBox() = default;
	inline void setText(wstring value);
	inline wstring getText() const;
	virtual void restCursor() { _cursorPositionx = _text.size() + this->getLeft() + 1; }
	/* Control Methods*/
	virtual void draw(Graphics& g, int x, int y, size_t z);
	virtual void mousePressed(int x, int y, bool isLeft);
	void keyDown(int keyCode, char charecter);
	virtual bool canGetFocus();
	virtual string className() { return "TextBox"; }
	inline virtual void setLeft(int left);
};

/*
* Inline Methods
*/

void TextBox::setLeft(int left) {
	_left = left;
	_cursorPositionx = left + _text.size() + 1;
}
void TextBox::setText(wstring value) {
	this->_text = value;
}
wstring TextBox::getText() const {
	return this->_text;
}

#endif // !TEXTBOX_H