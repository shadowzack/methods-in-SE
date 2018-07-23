#pragma once
#ifndef PANEL_H
#define PANEL_H
#include "Button.h"
#include <vector>

class Panel : public Control {
protected:
	vector<Control*> _controls;

public:
	Panel(int height = 20, int width = 20);
	~Panel() {}
	void AddControl(Control &control, int x, int y);
	/* Control Methods*/
	void draw(Graphics& g, int x, int y, size_t layer);
	virtual void getAllControls(vector<Control*>* controls);
	virtual bool canGetFocus();
	virtual void mousePressed(int x, int y, bool isLeft);

};
#endif // !PANEL_H

