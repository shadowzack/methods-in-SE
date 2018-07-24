#pragma once
#include "Panel.h"
#include "Focuslist.h"
#include <algorithm>

class ComboBox : public Panel {
protected:
	vector<string> _entries;
	int _index;
	wstring _text;

public:
	ComboBox(int width, vector<string> entries);
	~ComboBox() {}
	int GetSelectedIndex();
	void SetSelectedIndex(int index);
	vector<string>& Getallentries();
	virtual bool canGetFocus() { return false; }
	virtual string className() { return "ComboBox"; }
	inline virtual void setLeft(int left);
	inline virtual void setTop(int top);
	inline void setText(wstring text);
	inline wstring getText()const;
	virtual	void keyDown(int keyCode, char charecter);
	virtual void mousePressed(int x, int y, bool isLeft);
	virtual void draw(Graphics& g, int x, int y, size_t z);
	virtual void restCursor();

};

//choising ftom list
class ComboBox_list :public MouseListener {
public:
	ComboBox_list() {}
	virtual void MousePressed(Control &control, int x, int y, bool isLeft) {
		ComboBox * tmp = static_cast<ComboBox*>(&control);
		vector<Control*> myvec;
		tmp->getAllControls(&myvec);
		Button * temp = static_cast<Button*>(myvec[x]);
		tmp->setText(temp->getText());

		for (int i = 0; i < myvec.size() - 1; i++) {
			myvec[i]->setVisibility(false);
		}
		temp = static_cast<Button*>(myvec[myvec.size() - 1]);
		temp->setText(L" +");
	}
};

//more (+) butto and less(-) button
class cbutton : public MouseListener {
public:
	cbutton() { }

	virtual void MousePressed(Control &control, int x, int y, bool isLeft) {
		ComboBox * tmp = static_cast<ComboBox*>(&control);
		vector<Control*> myvec;
		tmp->getAllControls(&myvec);
		Button * temp = static_cast<Button*>(myvec[myvec.size() - 1]);
		temp->setText(L" +");
		for (int i = 0; i < myvec.size() - 1; i++) {
			myvec[i]->setVisibility(false);
		}
	}
};

/*
* Inline Methods
*/

void ComboBox::setText(wstring text) {
	_text = text;
}
wstring ComboBox::getText()const {
	return _text;
}
void ComboBox::setLeft(int left) {
	_left = left;
	for (int i = 0; i < _controls.size() - 1; i++) {
		_controls[i]->setLeft(0);
	}

}
void ComboBox::setTop(int top) {
	_top = top;
	for (int i = 0; i < _controls.size() - 1; i++) {
		if (i == 0) {
			_controls[i]->setTop(2);
		}
		else {
			_controls[i]->setTop(_controls[i - 1]->getHeight() + _controls[i - 1]->getTop());
		}
	}

}
