#pragma once
#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <string>
#include <Windows.h>

using namespace std;
enum class Color { Black, Blue, Green, Red, Cyan, Purple, Orange, White };

class Graphics
{
private:
	HANDLE _console;
	Color _background, _foreground;
	void updateConsoleAttributes();

public:
	//ctor && dtor
	Graphics(DWORD stdHandle = STD_OUTPUT_HANDLE);
	~Graphics();

	//setters
	void setBackground(Color color);
	void setForeground(Color color);
	void setCursorVisibility(bool isVisible);
	//getters
	CONSOLE_SCREEN_BUFFER_INFO getInfo();

	void clearScreen();
	void moveTo(int x, int y);
	void write(string s);
	void write(int x, int y, string s);
	void write(wstring s);
	void write(int x, int y, wstring s);

};

bool isInside(int x, int y, int left, int top, int width, int height);

#endif // !GRAPHICS_H