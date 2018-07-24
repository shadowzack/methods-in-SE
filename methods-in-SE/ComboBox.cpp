#include "stdafx.h"
#include "ComboBox.h"

//convert string to wstring
wstring s2ws(const std::string& s)
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

ComboBox::ComboBox(int width, vector<string> entries) :Panel((2 * entries.size() + 2), width + 3), _entries(entries), _index(-1) {
	wstring stemp;
	MouseListener *lisli = new ComboBox_list;
	MouseListener *b = new cbutton;
	_text = L"none";
	this->setVisibility(true);
	for (int i = 0; i < entries.size(); i++) {
		Focuslist* list = new Focuslist(width + 3);
		list->setHeight(2);
		list->setBackground(Color::White);
		list->setForeground(Color::Black);
		list->setVisibility(false);
		stemp = s2ws(entries[i]);
		list->setText(stemp);
		list->addListener(*lisli);
		this->_controls.push_back(list);
	}
	Button * li = new Button(3);
	li->setText(L" +");
	li->setBackground(Color::Blue);
	li->setForeground(Color::White);
	li->setVisibility("true");
	li->setTop(0);
	li->setLeft(width);
	li->addListener(*b);
	_controls.push_back(li);
	_controls[entries.size()]->setVisibility(true);
}

vector<string>& ComboBox::Getallentries() {
	return _entries;
}

void ComboBox::draw(Graphics& g, int x, int y, size_t z) {
	if (z == getLayer()) {
		if (getVisibilty()) {
			int realy = getHeight();
			_height = 2;
			g.setBackground(getBackground());
			g.setForeground(getForeground());
			Control::draw(g, x, y, z);
			g.write(x + getLeft() + 1, getTop() + y + 1, _text + wstring(getWidth() - _text.size(), ' '));
			_height = realy;
			for (int i = 0; i < _controls.size(); i++) {
				if (_controls[i]->getVisibilty() == true) {
					g.setBackground(_controls[i]->getBackground());
					g.setForeground(_controls[i]->getForeground());
					this->_controls[i]->draw(g, x + getLeft(), y + getTop(), _controls[i]->getLayer());
				}
			}
		}
	}
}

void ComboBox::SetSelectedIndex(int index) {
	this->_index = index - 1;
	wstring stemp;
	stemp = s2ws(_entries[index - 1]);
	Button* tmp = static_cast<Button*>(_controls[index]);
	tmp->setText(stemp);
}

int ComboBox::GetSelectedIndex() {
	return this->_index;
}

//reset background to original after scroling down throuth the list
void ComboBox::restCursor() {
	if (opened) {
		for (int i = 0; i < _controls.size() - 1; i++) {
			_controls[i]->setBackground(Color::White);
			_controls[i]->setForeground(Color::Black);
		}
	}
}

//to mark to orang while scorling through the list
void ComboBox::keyDown(int keyCode, char charecter) {
	if (this->isOpened()) {
		auto f = Control::getFocus();
		auto it = find(_controls.begin(), _controls.end(), f);
		if (keyCode == VK_DOWN) {
			if (++it != _controls.end() - 1) {
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
			Button * b = static_cast<Button*>(_controls[_controls.size() - 1]);
			b->setText(L" +");
			Control::getFocus()->setForeground(Color::Black);
			Control::getFocus()->setBackground(Color::White);
			b = static_cast<Button*>(Control::getFocus());
			_text = b->getText();
			_index = pos;
			opened = false;
			for (int i = 0; i < _controls.size() - 1; i++)
				_controls[i]->setVisibility(false);
		}
	}

}

//what to do id presser event
void ComboBox::mousePressed(int x, int y, bool isLeft) {
	opened = true;
	x -= _left;
	y -= _top;
	Button *tmp = static_cast<Button*>(_controls[_controls.size() - 1]);
	wstring s = tmp->getText();
	string icon(s.length(), ' ');
	std::copy(s.begin(), s.end(), icon.begin());
	if (icon == " +") {
		if (isInside(x, y, tmp->getLeft(), tmp->getTop(), tmp->getWidth(), tmp->getHeight())) {
			for (int i = 0; i < _controls.size(); i++)
				_controls[i]->setVisibility(true);
			tmp->setText(L" -");
			if (_controls.size() > 1) {
				Control::setFocus(*_controls[0]);
				_controls[0]->setBackground(Color::Orange);
				_controls[0]->setForeground(Color::White);
			}
		}
	}
	else if (icon == " -") {
		for (int i = 0; i < _controls.size(); i++) {
			if (isInside(x, y, _controls[i]->getLeft(), _controls[i]->getTop(), _controls[i]->getWidth(), _controls[i]->getHeight())) {
				Button* temp = static_cast<Button*>(_controls[i]);
				temp->getListener().MousePressed(*this, i, y, isLeft);
				_index = i;
				opened = false;
				break;
			}
		}
	}
}