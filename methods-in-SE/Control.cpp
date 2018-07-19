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

//getters
Control* Control::getFocus() {
	return Focused::instance()->getfocus();
}
bool Control::canGetFocus() {
	return false;
}

//drawer
void Control::draw(Graphics& g, int x, int y, size_t z) {
	if (z > _layer) return;
	if (getVisibilty())
		_borderDrawer->draw(g, _left + x, _top + y, _width, _height);
}

//setters list
void Control::setFocus(Control& control) {
	if (control.canGetFocus()) {
		Focused::instance()->setFocus(control);
		if (Focused::instance()->getGraph()) {
			Focused::instance()->getGraph()->moveTo(control._cursorPositionx, control.getTop() + control.getHeight() - 1);
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

Focused * Focused::instance()
{
		if (!_instance)
			_instance = new Focused;
		return _instance;
	
}
