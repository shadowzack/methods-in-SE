#include "stdafx.h"
#include "Control.h"

Control::Control()
{
	this->setForeground(Color::White);
	this->setBackground(Color::Black);
	_layer = 0;
	setBorderDrawer(BorderFactory::instance().getNull());
	_visible = true;
	opened = false;
}


//draw func
void Control::draw(Graphics& g, int x, int y, size_t z) {
	if (z > _layer) return;
	if (getVisibilty())
		_borderDrawer->draw(g, _left + x, _top + y, _width, _height);
}

//getters
Control* Control::getFocus() {
	return SingletonFocused::instance()->getfocus();
}
bool Control::canGetFocus() {
	return false;
}
size_t Control::getLayer() const {
	return _layer;
}
void Control::setLayer(size_t layer) {
	this->_layer = layer;
}
int Control::getWidth() const {
	return _width;
}
int Control::getLeft()const {
	return _left;
}
int Control::getTop()const {
	return _top;
}
Color Control::getBackground()const {
	return _backgroundcolor;
}
Color Control::getForeground()const {
	return _forgroundcolor;
}
int Control::getHeight()const {
	return _height;
}
bool Control::getVisibilty()const {
	return _visible;
}


//setters
void Control::setFocus(Control& control) {
	if (control.canGetFocus()) {
		SingletonFocused::instance()->setFocus(control);
		if (SingletonFocused::instance()->getGraph()) {
			SingletonFocused::instance()->getGraph()->moveTo(control._cursorPositionx, control.getTop() + control.getHeight() - 1);
		}
	}
}
void Control::setVisibility(bool visibility) {
	_visible = visibility;
}
void Control::setForeground(Color color) {
	this->_forgroundcolor = color;
}
void Control::setBackground(Color color) {
	this->_backgroundcolor = color;
}
void Control::setBorder(BorderType border) {
	if (border == BorderType::Single) {
		setBorderDrawer(BorderFactory::instance().getSingle());
	}
	else if (border == BorderType::Double) {
		setBorderDrawer(BorderFactory::instance().getDouble());
	}
	else {
		setBorderDrawer(BorderFactory::instance().getNull());
	}

}
void Control::setTop(int top) {
	_top = top;
	_cursorPositiony = this->getTop() + this->getHeight() - 1;
}
void Control::setLeft(int left) {
	_left = left;
}
void Control::restCursor() {
	_cursorPositionx = 0;
}
void Control::setHeight(int _y) {
	_height = _y;
}
