#include "stdafx.h"
#include "TextBox.h"


TextBox::TextBox(int width) {
	_width = width;
	_height = 2;
	_top = 0;
	_left = 0;
	_layer = 0;
	_cursorPositionx = 0;
}

void TextBox::mousePressed(int x, int y, bool isLeft) {
	Control::getFocus()->restCursor();
	Control::setFocus(*this);
}

void TextBox::keyDown(int keyCode, char charecter) {
	auto _pos = SingletonFocused::instance()->getGraph()->getInfo();
	this->_cursorPositionx = _pos.dwCursorPosition.X;

	if (keyCode == VK_LEFT) {
		if (_pos.dwCursorPosition.X > this->getLeft() + 1) {
			this->_cursorPositionx--;
			SingletonFocused::instance()->getGraph()->moveTo(_cursorPositionx, _pos.dwCursorPosition.Y);
		}
	}
	else if (keyCode == VK_RIGHT) {
		if (_pos.dwCursorPosition.X <= _text.size() + _left)
			this->_cursorPositionx++;
		SingletonFocused::instance()->getGraph()->moveTo(_cursorPositionx, _pos.dwCursorPosition.Y);
	}
	else if (keyCode == VK_BACK) {
		if (_pos.dwCursorPosition.X == this->getText().size() + _left + 1) {
			if (_text.size() != 0)
				_text.pop_back();
		}
		if (_cursorPositionx > _left + 1)
			SingletonFocused::instance()->getGraph()->moveTo(_cursorPositionx--, _pos.dwCursorPosition.Y);
		else
			SingletonFocused::instance()->getGraph()->moveTo(_cursorPositionx, _pos.dwCursorPosition.Y);
	}
	else {
		if (_cursorPositionx < _left + getWidth()) {
			char temp[1];
			temp[0] = charecter;
			if (_text.size() == 0) {
				_text = (temp[0], temp[0]);
			}
			else
				_text += (temp[0], temp[0]);
			_cursorPositionx++;
		}
	}
}

bool TextBox::canGetFocus() {
	return true;
}

void TextBox::draw(Graphics& g, int x, int y, size_t layer) {
	if (layer == getLayer()) {
		if (getVisibilty()) {
			g.setBackground(this->getBackground());
			g.setForeground(this->getForeground());
			g.write(x + getLeft() + 1, getTop() + y + 1, _text + wstring(getWidth() - _text.size(), ' '));
			Control::draw(g, x, y, layer);
		}
	}
}

//setters
void TextBox::setLeft(int left) {
	_left = left;
	_cursorPositionx = left + _text.size() + 1;
}
void TextBox::setText(wstring value) {
	this->_text = value;
}
//getters
wstring TextBox::getText() const {
	return this->_text;
}

