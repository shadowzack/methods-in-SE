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

ComboBox::ComboBox(int width, vector<string> entries) :Panel((2 * entries.size()+2), width + 3), _entries(entries),_index(-1) {
	wstring stemp;
	MouseListener *lisli= new ComboBox_list;
	MouseListener *b= new cbutton;
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
