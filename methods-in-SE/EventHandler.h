#pragma once
#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H
#include "Control.h"
#include <Windows.h>
#include "Graphics.h"

class EventHandler
{
public:
	EventHandler(DWORD input = STD_INPUT_HANDLE, DWORD output = STD_OUTPUT_HANDLE);
	void run(Control &c);
	virtual ~EventHandler();
private:
	Graphics _graphics;
	HANDLE _console;
	DWORD _consoleMode;
	void moveFocus(Control &main, Control *focused);
	void deepFocus(Control &main, Control *focused);
};

#endif // !EVENTHANDLER_H