#include "stdafx.h"
#include "RadioBox.h"
#include "Button.h"

RadioBox::RadioBox(int width, int height, vector<string> entries) :CheckList(width, height, entries), _index(-1) {}

int RadioBox::GetSelectedIndex() {
	return _index;

}

void RadioBox::restCursor() {
	for (int i = 0; i < _controls.size(); i++) {
		_controls[i]->setBackground(Color::White);
		_controls[i]->setForeground(Color::Black);
		if (i == _index) {
			_controls[i]->setBackground(Color::Green);
		}
	}
}

void RadioBox::keyDown(int keyCode, char charecter) {

	if (this->isOpened()) {
		auto f = Control::getFocus();
		auto it = find(_controls.begin(), _controls.end(), f);
		if (keyCode == VK_DOWN) {
			if (++it != _controls.end()) {
				Control::setFocus(**it);
				restCursor();
				(**it).setBackground(Color::Orange);
				(**it).setForeground(Color::White);
			}
		}
		else if (keyCode == VK_UP) {
			if (it != _controls.begin()) {
				it--;
				Control::setFocus(**it);
				restCursor();
				(**it).setBackground(Color::Orange);
				(**it).setForeground(Color::White);
			}
		}
		else if (keyCode == VK_RETURN || keyCode == VK_SPACE) {
			int lock = 0;
			size_t pos = it - _controls.begin();

			Control::getFocus()->setForeground(Color::Black);
			if (_index == pos)
				Control::getFocus()->setBackground(Color::White);
			else {
				_controls[_index]->setBackground(Color::White);
				Control::setFocus(**it);
				//restCursor();
				(**it).setBackground(Color::Green);
				_index = pos;
			}
		}
	}
}

//what to in case selected
void RadioBox::SetSelectedIndex(int index) {
	if (_index != -1) {
		_controls[_index]->setBackground(Color::White);
	}
	this->_index = index;
	_controls[index]->setBackground(Color::Green);
}

void RadioBox::click(int index) {
	SetSelectedIndex(index);
}