
#include "stdafx.h"
#include"Control.h"
#include <iostream>
#include "TextBox.h"

using namespace std;
Focused* Focused::_instance = 0;
int main()
{
	TextBox tmp(10);
	tmp.setText(L"last");
	tmp.setBorder(BorderType::Single);
	cout << " hello world \n";
	return 0;
}