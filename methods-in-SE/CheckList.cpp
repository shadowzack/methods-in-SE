#include "stdafx.h"
#include "CheckList.h"
#include "Focuslist.h"
#include <string.h>

//convert string to wstring
wstring CheckList::s2ws(const std::string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	wstring r(buf);
	delete[] buf;
	return r;
}

CheckList::CheckList(int width, int height, vector<string> entries) :Panel((height*entries.size()), width), _entries(entries) {
	wstring stmp;
	for (int i = 0; i < entries.size(); i++) {
		Focuslist* list = new Focuslist(width);
		list->setHeight(height);
		list->setBackground(Color::White);
		list->setForeground(Color::Black);
		stmp = s2ws(entries[i]);
		list->setText(stmp);
		this->_controls.push_back(list);
	}
	_cursorPositiony = _controls[0]->getTop() + 1;


}
vector<size_t>& CheckList::GetallIndex() {
	return _indexs;
}

vector<string>& CheckList::Getallentries() {
	return _entries;
}
void CheckList::SelectedIndex(size_t index) {
	_indexs.push_back(index);
	//turn on background on selected
	_controls[index]->setBackground(Color::Green);

}

void CheckList::DeSelectedIndex(size_t index) {
	
	for (int i = 0; i < _indexs.size();i++) {
		if (_indexs[i] == index) {
			_indexs.erase(_indexs.begin() + i);
			// turn off background
			_controls[index]->setBackground(Color::White);
		}
	}
}

void CheckList::restCursor() {

	for (int i = 0; i < _controls.size(); i++) {
		_controls[i]->setBackground(Color::White);
		_controls[i]->setBackground(Color::Black);
		for (int j = 0; j < _indexs.size(); j++) {
			if (_indexs[j] == i) {
				_controls[i]->setBackground(Color::Green);
				_controls[i]->setBackground(Color::Black);
				break;
			}
		}
	}
}

//to mark to orang while scorling through the list
void CheckList::keyDown(int keyCode, char charecter) {
	if (this->isOpened()) {
		auto f = Control::getFocus();
		auto it = find(_controls.begin(), _controls.end(), f);
		if (keyCode == VK_DOWN) {
			if (it != _controls.end() && ++it != _controls.end()) {
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
			int pos = it - _controls.begin();
			Control::getFocus()->setForeground(Color::Black);
			for (int j = 0; j < _indexs.size(); j++) {
				if (_indexs[j] == pos) {
					f->setBackground(Color::White);
					_indexs.erase(_indexs.begin() + j);
					lock = 1;
					break;
				}
			}
			if (lock == 0) {
				f->setBackground(Color::Green);
				_indexs.push_back(pos);
			}
		}
	}
}

//in case we pressed the mouse
void CheckList::mousePressed(int x, int y, bool isLeft) {
	opened = true;
	x -= _left;
	y -= _top;
	for (int i = 0; i < _controls.size(); i++) {
		int myy = _controls[i]->getTop() + _controls[i]->getHeight();
		int y_l = _controls[i]->getTop();
		if (y >= y_l && y <= myy) {
			_cursorPositiony = _top + _controls[i]->getTop() + 1;
			Focuslist* tmp = static_cast<Focuslist*>(_controls[i]);
			Control::setFocus(*_controls[i]);
			click(i);
			break;
		}
	}
}

//what to do in click case
void CheckList::click(int index) {

	int _lock = 0;
	for (int i = 0; i < _indexs.size(); i++) {
		if (_indexs[i] == index) {
			DeSelectedIndex(index);
			_lock = 1;

		}
	}

	if (_lock == 0)
		SelectedIndex(index);
}
