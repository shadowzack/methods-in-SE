#pragma once

#include "Graphics.h"
#include "BorderFactory.h"
#include "Focused.h"
#include <vector>

using namespace std;
enum class BorderType { Single, Double, None };

class Control
{
protected:
	int _left,_top;
	int _width,_height;
	int _cursorPositionx,_cursorPositiony;
	bool _visible;
	bool opened;
	size_t _layer;
	Color _forgroundcolor,_backgroundcolor;
private:
	const BorderStyle *_borderDrawer;
public:
	/* main methods for the graphic */
	void setVisibility(bool visibility);
	void setForeground(Color color);
	void setBackground(Color color);
	inline Color getBackground()const;
	inline Color getForeground()const;
	void setBorder(BorderType border);

	/* setters and getters */
	inline size_t getLayer() const;
	inline void setLayer(size_t layer);
	inline int getWidth()const;
	inline int getHeight()const;
	inline void setHeight(int _y);
	inline virtual void restCursor();
	inline virtual void setLeft(int left);
	inline virtual void setTop(int top);
	inline virtual int getLeft()const;
	inline virtual int getTop()const;
	inline bool getVisibilty()const;
	bool isOpened() { return opened; }
	void setopen(bool open) { opened = open; }
	/**/
	Control();
	static Control* getFocus();
	static void setFocus(Control& control);
	virtual void draw(Graphics& g, int x, int y, size_t z);
	virtual void mousePressed(int x, int y, bool isLeft) {};
	virtual void keyDown(int keyCode, char charecter) {};
	virtual void getAllControls(vector<Control*>* controls) {};
	virtual bool canGetFocus();
	virtual void setBorderDrawer(const BorderStyle &borderDrawer) { _borderDrawer = &borderDrawer; }
	virtual ~Control() = default;
	virtual string className() { return "Control"; }
};

class Focused {
public:
	 static Focused* instance();
	Control* getfocus() { return _focus; }
	void setFocus(Control& c) { _focus = &c; }
	void setGraph(Graphics& g) { _graph = &g; }
	Graphics* getGraph() { return _graph; }
	Focused(Focused const&) = delete;
	void operator=(Focused const&) = delete;
private:
	static Focused* _instance;
	Control* _focus;
	Graphics* _graph;
	Focused() { _focus = NULL; _graph = NULL; }
};

/*
* Inline Methods
*/

size_t Control::getLayer() const {
	return _layer;
}
void Control::setLayer(size_t layer) {
	this->_layer = layer;
}
int Control::getWidth() const {
	return _width;
}
int Control::getLeft()const {
	return _left;
}
int Control::getTop()const {
	return _top;
}
void Control::setTop(int top) {
	_top = top;
	_cursorPositiony = this->getTop() + this->getHeight() - 1;
}
void Control::setLeft(int left) {
	_left = left;
}
Color Control::getBackground()const {
	return _backgroundcolor;
}
Color Control::getForeground()const {
	return _forgroundcolor;
}
int Control::getHeight()const {
	return _height;
}
void Control::restCursor() {
	_cursorPositionx = 0;
}
void Control::setHeight(int _y) {
	_height = _y;
}
bool Control::getVisibilty()const {
	return _visible;
}


