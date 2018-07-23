#pragma once
#ifndef CONTORL_H
#define CONRTOL_H

#include "Graphics.h"
#include "BorderFactory.h"
#include "Focused.h"
#include <vector>

using namespace std;
enum class BorderType { Single, Double, None };

class Control
{
private:
	const BorderStyle *_borderDrawer;
protected:
	int _left,_top;
	int _width,_height;
	int _cursorPositionx,_cursorPositiony;
	bool _visible;
	bool opened;
	size_t _layer;
	Color _forgroundcolor,_backgroundcolor;
public:
	// graphics control setters and getters
	void setVisibility(bool visibility);
	void setForeground(Color color);
	void setBackground(Color color);
	Color getBackground()const;
	Color getForeground()const;
	void setBorder(BorderType border);

	//setters 
	void setLayer(size_t layer);
	void setHeight(int _y);
	virtual void restCursor();
	virtual void setLeft(int left);
	virtual void setTop(int top);
	void setopen(bool open) { opened = open; }
	static void setFocus(Control& control);

	//getters
	size_t getLayer() const;
	int getWidth()const;
	int getHeight()const;
	virtual int getLeft()const;
	virtual int getTop()const;
	bool getVisibilty()const;
	bool isOpened() { return opened; }
	static Control* getFocus();

	/*Abstract class functions for example each component will have different shap*/
	virtual void draw(Graphics& g, int x, int y, size_t z);
	virtual void mousePressed(int x, int y, bool isLeft) {};
	virtual void keyDown(int keyCode, char charecter) {};
	virtual void getAllControls(vector<Control*>* controls) {};
	virtual bool canGetFocus();
	virtual void setBorderDrawer(const BorderStyle &borderDrawer) { _borderDrawer = &borderDrawer; }
	
	//ctor && dtor
	Control();
	virtual ~Control() = default;//makes class pure abstarct

	//class name or object type
	virtual string className() { return "Control"; }
};

/* a singletone one instance fo control*/
class SingletonFocused {
public:
	//global access point
	static SingletonFocused* instance() {
		if (!_instance)
			_instance = new SingletonFocused;
		return _instance;
	}

	//getters
	Control* getfocus() { return _focus; }
	Graphics* getGraph() { return _graph; }
	//setters
	void setFocus(Control& c) { _focus = &c; }
	void setGraph(Graphics& g) { _graph = &g; }

	SingletonFocused(SingletonFocused const&) = delete;
	void operator=(SingletonFocused const&) = delete;
private:
	static SingletonFocused* _instance; //singlton instance
	Control* _focus;
	Graphics* _graph;
	//private ctor
	SingletonFocused() { _focus = NULL; _graph = NULL; }
};

#endif // !CONTORL_H

