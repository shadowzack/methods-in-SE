#ifndef RADIOBOX_H
#define RADIOBOX_H

#pragma once
#include "CheckList.h"

class RadioBox : public CheckList {
	int _index;
public:
	RadioBox(int width, int height, vector<string> entries);
	~RadioBox() {}
	virtual string className() { return "RadioBox"; }
	virtual void click(int index);
	int GetSelectedIndex();
	void SetSelectedIndex(int index);
	virtual void restCursor();
	virtual void keyDown(int keyCode, char charecter);
};

#endif
