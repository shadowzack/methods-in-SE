
#include "stdafx.h"
#include "Graphics.h"
#include "TextBox.h"
#include "EventHandler.h"
#include "Panel.h"
#include "Label.h"
#include "Button.h"
#include "BorderFactory.h"
#include "Form.h"


SingletonFocused* SingletonFocused::_instance = 0;
int main()
{
	Form calform;
	calform.start();
	return 0;
}