#pragma once
#ifndef BORDERFACTORY_H
#define BORDERFACTORY_H
#include "Graphics.h"
#include <string>
using namespace std;

struct BorderStyle {
	virtual void draw(Graphics &g, int left, int top, int width, int height) const = 0;
};
class SingleBorderDrawer : public BorderStyle {
	virtual void draw(Graphics &g, int left, int top, int width, int height) const;
};
class NullBorderDrawer : public BorderStyle {
	virtual void draw(Graphics &g, int left, int top, int width, int height) const {/*no border*/ }
};
class DoubleBorderDrawer : public BorderStyle {
	virtual void draw(Graphics &g, int left, int top, int width, int height) const;
};


class BorderFactory {
public:
	const BorderStyle& getNull() { return _null; }
	const BorderStyle& getSingle() { return _single; }
	const BorderStyle& getDouble() { return _double; }
	static BorderFactory& instance();
	BorderFactory(BorderFactory const&) = delete;
	void operator=(BorderFactory const&) = delete;
private:
	BorderFactory();
	NullBorderDrawer _null;
	SingleBorderDrawer _single;
	DoubleBorderDrawer _double;

};

#endif // !BORDERFACTORY_H