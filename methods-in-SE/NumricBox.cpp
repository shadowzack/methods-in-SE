#include "stdafx.h"
#include "NumericBox.h"


NumericBox::NumericBox(int width, int min, int max) :Panel(2,width+4),_min(min),_max(max){
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
