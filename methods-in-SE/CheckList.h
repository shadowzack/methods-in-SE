#ifndef CHECKLIST_H
#define CHECKLIST_H

#pragma once
#include "Panel.h"

class CheckList : public Panel {
protected:
	vector<string> _entries;
	vector<size_t> _indexs;

public:
	//ctor && dtor
	CheckList(int width, int height, vector<string> entries);
	~CheckList() {}
	CheckList() {}
	//setters
	void SelectedIndex(size_t index);
	void DeSelectedIndex(size_t index);
	inline virtual void setLeft(int left);
	inline virtual void setTop(int top);
	//getters
	vector<size_t>& GetallIndex();
	vector<string>& Getallentries();
	wstring s2ws(const std::string& s);
	virtual bool canGetFocus() { return false; }
	virtual string className() { return "CheckList"; }

	virtual void mousePressed(int x, int y, bool isLeft);
	virtual void keyDown(int keyCode, char charecter);
	virtual void restCursor();
	virtual void click(int index);
};


// left setting
void CheckList::setLeft(int left) {
	_left = left;
	for (int i = 0; i < _controls.size(); i++) {
		_controls[i]->setLeft(0);
	}

}
// top setting
void CheckList::setTop(int top) {
	_top = top;
	for (int i = 0; i < _controls.size(); i++) {
		if (i == 0) {
			_controls[i]->setTop(0);
		}
		else {
			_controls[i]->setTop(_controls[i - 1]->getHeight() + _controls[i - 1]->getTop());
		}
	}

}

#endif 