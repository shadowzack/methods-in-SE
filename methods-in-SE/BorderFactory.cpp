#include "stdafx.h"
#include "BorderFactory.h"

/* Drawer Functions */
void SingleBorderDrawer::draw(Graphics &g, int left, int top, int width, int height) const {
	char box[6] = { '\xDA','\xC4', '\xBF','\xB3','\xc0','\xd9' };
	string s;
	s.push_back(box[0]);
	g.write(left, top, s);
	int i;
	s.pop_back();
	s.push_back(box[1]);
	for (i = 1; i <= width; i++) {
		g.write(left + i, top, s);
	}
	s.pop_back();
	s.push_back(box[2]);
	g.write(left + i, top, s);
	s.pop_back();
	s.push_back(box[3]);
	for (i = 1; i < height; i++) {
		g.write(left, top + i, s);
		g.write(left + width + 1, top + i, s);
	}
	s.pop_back();
	s.push_back(box[4]);
	g.write(left, top + i, s);
	s.pop_back();
	s.push_back(box[1]);
	for (i = 1; i <= width; i++) {
		g.write(left + i, top + height, s);
	}
	s.pop_back();
	s.push_back(box[5]);
	g.write(left + i, top + height, s);
}

// borderFactory draw function 
void DoubleBorderDrawer::draw(Graphics &g, int left, int top, int width, int height) const {
	char box[6] = { '\xC9','\xCD', '\xBB','\xBA','\xC8','\xBC' };
	string s;
	s.push_back(box[0]);
	g.write(left, top, s);
	int i;
	s.pop_back();
	s.push_back(box[1]);
	for (i = 1; i <= width; i++) {
		g.write(left + i, top, s);
	}
	s.pop_back();
	s.push_back(box[2]);
	g.write(left + i, top, s);
	s.pop_back();
	s.push_back(box[3]);
	for (i = 1; i < height; i++) {
		g.write(left, top + i, s);
		g.write(left + width + 1, top + i, s);
	}
	s.pop_back();
	s.push_back(box[4]);
	g.write(left, top + i, s);
	s.pop_back();
	s.push_back(box[1]);
	for (i = 1; i <= width; i++) {
		g.write(left + i, top + height, s);
	}
	s.pop_back();
	s.push_back(box[5]);
	g.write(left + i, top + height, s);

}

//simple border
BorderFactory::BorderFactory() {

}

BorderFactory& BorderFactory::instance() {

	static BorderFactory instance;
	return instance;
}