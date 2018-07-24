#include "stdafx.h"
#include "NumericBox.h"


NumericBox::NumericBox(int width, int min, int max) :Panel(2, width + 4), _min(min), _max(max) {
	_value = min;
	Button* minus = new Button(2);
	minus->setText(L"-");
	minus->addListener(*new Minus_button);
	minus->setBackground(Color::Blue);
	minus->setForeground(Color::White);
	this->_controls.push_back(minus);
	Label* value = new Label(width);
	value->setText(L" " + to_wstring(_value));    //the value
	value->setBackground(Color::White);
	value->setForeground(Color::Black);
	this->_controls.push_back(value);
	Button* plus = new Button(2);
	plus->setText(L" +");
	plus->setBackground(Color::Blue);
	plus->setForeground(Color::White);
	plus->addListener(*new Plus_button);
	this->_controls.push_back(plus);
}


bool NumericBox::setValue(int value) {
	if (value>_max || value<_min)
		return false;
	_value = value;
	Label* temp = static_cast<Label*>(_controls[1]);
	temp->setText(L" " + to_wstring(_value));
	return true;

}

int NumericBox::getValue() {
	return this->_value;
}

void NumericBox::mousePressed(int x, int y, bool isLeft) {
	x -= _left;
	y -= _top;
	for (int i = 0; i < _controls.size(); i++) {
		int myx = _controls[i]->getLeft() + _controls[i]->getWidth();
		//int myy = _controls[i]->getTop() + _controls[i]->getHeight();
		int x_l = _controls[i]->getLeft();
		//int y_t = _controls[i]->getTop();
		if ((x >= x_l && x <= myx) && (_controls[i]->className() == "Button")) {
			Button* tmp = static_cast<Button*>(_controls[i]);
			tmp->getListener().MousePressed(*this, x, y, isLeft);
		}
	}
}


