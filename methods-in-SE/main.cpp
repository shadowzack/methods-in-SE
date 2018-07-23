
#include "stdafx.h"
#include "Graphics.h"
#include "TextBox.h"
#include "EventHandler.h"
#include "Panel.h"
#include "Label.h"
#include "Button.h"
#include "BorderFactory.h"


Panel* MainPanel = NULL;
vector<wstring>str;
SingletonFocused* SingletonFocused::_instance = 0;

int main()
{

	//panel contanier
	Panel panel(45, 36);
	panel.setBackground(Color::Black);
	panel.setForeground(Color::White);
	panel.setBorder(BorderType::Double);
	MainPanel = &panel;

	//text boxes
	TextBox textbx1(10);
	textbx1.setText(L"first");
	textbx1.setBorder(BorderType::Single);
	panel.AddControl(textbx1, 6, 7);
	str.push_back(textbx1.getText());

	TextBox textbx2(10);
	textbx2.setText(L"last");
	textbx2.setBorder(BorderType::Single);
	panel.AddControl(textbx2, 19, 7);
	str.push_back(textbx2.getText());


	//titles
	Label title(12);
	title.setText(L"register");
	title.setBackground(Color::White);
	title.setForeground(Color::Black);
	panel.AddControl(title, 12, 2);

	Label name(15);
	name.setText(L"full name");
	name.setBackground(Color::Black);
	name.setForeground(Color::White);
	panel.AddControl(name, 12, 10);

	Label agetest(15);
	agetest.setText(L"age(0-18)");
	agetest.setBackground(Color::Black);
	agetest.setForeground(Color::White);
	panel.AddControl(agetest, 12, 18);

	Label educattest(15);
	educattest.setText(L"education");
	educattest.setBackground(Color::Black);
	educattest.setForeground(Color::White);
	panel.AddControl(educattest, 12, 24);

	Label hobbytest(15);
	hobbytest.setText(L"hobby");
	hobbytest.setBackground(Color::Black);
	hobbytest.setForeground(Color::White);
	panel.AddControl(hobbytest, 12, 30);

	Label gendertest(15);
	gendertest.setText(L"gender");
	gendertest.setBackground(Color::Black);
	gendertest.setForeground(Color::White);
	panel.AddControl(gendertest, 12, 36);

	//submit button
	Button click(10);
	click.setText(L" submit");
	click.setBorder(BorderType::Double);
	click.setBackground(Color::White);
	click.setForeground(Color::Blue);
	panel.AddControl(click, 12, 42);

	//event handling and starting object
	Control::setFocus(textbx1);
	EventHandler handler;
	handler.run(panel);

	return 0;
}