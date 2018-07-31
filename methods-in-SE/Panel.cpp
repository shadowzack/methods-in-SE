#include "stdafx.h"
#include "Panel.h"

void Panel::AddControl(Control &control, int x, int y) {
	control.setTop(y);
	control.setLeft(x);
	_controls.push_back(&control);
	_layer = 0;
}

Panel::Panel(int height, int width) :Control() {
	this->_height = height;
	this->_width = width;
	_top = 0;
	_left = 0;
}

void Panel::getAllControls(vector<Control*>* controls) {
	for (int i = 0; i < _controls.size(); i++) {
		controls->push_back(_controls[i]);
	}
}

void Panel::mousePressed(int x, int y, bool isLeft) {
	Button* temp;
	TextBox* tempo;
	for (int i = 0; i < _controls.size(); i++) {
		if (isInside(x, y, _controls[i]->getLeft(), _controls[i]->getTop(), _controls[i]->getWidth(), _controls[i]->getHeight())) {
			if (_controls[i]->className() == "Button") {
				temp = static_cast<Button*>(_controls[i]);
				temp->getListener().MousePressed(*this, x, y, isLeft);
				break;
			}
			else
				_controls[i]->mousePressed(x, y, isLeft);
		}
	}
}


void Panel::draw(Graphics& g, int x, int y, size_t layer) {
	if (layer == getLayer()) {
		if (getVisibilty()) {
			g.setForeground(getForeground());
			g.setBackground(getBackground());
			Control::draw(g, x, y, layer);
			for (int i = 0; i < _height - 1; i++) {
				g.write(x + getLeft() + 1, y + getTop() + i + 1, wstring(getWidth(), ' '));
			}
			for (int i = 0; i < _controls.size(); i++) {
				this->_controls[i]->draw(g, x + getLeft(), y + getTop(), _controls[i]->getLayer());
			}
		}
	}
}

bool Panel::canGetFocus() {
	return false;
}