#include "stdafx.h"
#include "EventHandler.h"
#include <vector>

using namespace std;

EventHandler::EventHandler(DWORD input, DWORD output):_console(GetStdHandle(input)),_graphics(output)
{
	GetConsoleMode(_console, &_consoleMode);
	SetConsoleMode(_console, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
	SetConsoleTitle(L"2018 *_* yay");

}

void EventHandler::run(Control &c)
{
	int lock = 0;
	SingletonFocused::instance()->setGraph(_graphics);
	/* checking if the main panel is inside the Console
	* if no- change the console size
	*/
	for (bool redraw = true;;)
	{
		if (redraw)
		{
			_graphics.clearScreen();
			_graphics.setCursorVisibility(false);
			for (size_t p = 0; p < 5; ++p)
				c.draw(_graphics, 0, 0, p);
			redraw = false;
			_graphics.setBackground(Color::Black);
		}
		if (lock == 0 && Control::getFocus()) {
			if (Control::getFocus()->className() == "TextBox") {
				_graphics.setCursorVisibility(true);
				Control::setFocus(*Control::getFocus());
			}
			lock = 1;
		}
		INPUT_RECORD record;
		DWORD count;
		ReadConsoleInput(_console, &record, 1, &count);
		switch (record.EventType)
		{
		case KEY_EVENT:
		{
			auto f = Control::getFocus();
			if (f != nullptr && record.Event.KeyEvent.bKeyDown)
			{
				auto code = record.Event.KeyEvent.wVirtualKeyCode;
				auto chr = record.Event.KeyEvent.uChar.AsciiChar;
				if (code == VK_TAB) {
					f->restCursor();
					moveFocus(c, f);
					redraw = true;
					lock = 0;
				}
				else if (code == VK_RIGHT || code == VK_LEFT) {
					f->keyDown(code, chr);
					redraw = false;
				}
				else if (code == VK_DOWN || code == VK_UP || code == VK_RETURN || code == VK_SPACE) {
					vector <Control*> myvec;
					c.getAllControls(&myvec);
					for (int i = 0; i<myvec.size(); i++) {
						if (myvec[i]->isOpened()) {
							myvec[i]->keyDown(code, chr);
							redraw = true;
							break;
						}
					}
				}
				else {
					f->keyDown(code, chr);
					redraw = true;
					lock = 0;
				}
			}
			break;
		}
		case MOUSE_EVENT:
		{
			auto button = record.Event.MouseEvent.dwButtonState;
			auto coord = record.Event.MouseEvent.dwMousePosition;
			auto x = coord.X - c.getLeft();
			auto y = coord.Y - c.getTop();
			vector<Control*> myvec;
			if (button == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				c.getAllControls(&myvec);
				for (int i = 0; i < myvec.size(); i++) {
					myvec[i]->restCursor();
					myvec[i]->setopen(false);
				}
				c.mousePressed(x, y, button == FROM_LEFT_1ST_BUTTON_PRESSED);
				redraw = true;
				lock = 0;
			}
			break;
		}
		default:
			break;
		}
	}
}

EventHandler::~EventHandler()
{
	SetConsoleMode(_console, _consoleMode);
}

void EventHandler::moveFocus(Control &main, Control *focused)
{
	int exit = 0;
	vector<Control*> controls;
	main.getAllControls(&controls);
	for (int i = 0; i < controls.size(); i++) {
		if (controls[i]->isOpened()) {
			deepFocus(*controls[i], Control::getFocus());
			_graphics.setCursorVisibility(false);
			exit = 1;
			break;
		}
	}
	if (exit == 0) {
		auto it = find(controls.begin(), controls.end(), focused);
		do
			if (++it == controls.end())
				it = controls.begin();
		while (!(*it)->canGetFocus());
		Control::setFocus(**it);
	}
}

void EventHandler::deepFocus(Control &main, Control *focused) {
	vector<Control*> controls;
	main.getAllControls(&controls);
	auto it = find(controls.begin(), controls.end(), focused);
	do
		if (++it == controls.end())
			it = controls.begin();
	while (!((*it)->canGetFocus()));
	Control::setFocus(**it);
	main.restCursor();
	Control::getFocus()->setBackground(Color::Orange);
	Control::getFocus()->setForeground(Color::White);

}