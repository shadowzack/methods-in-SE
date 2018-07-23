#pragma once
#include "stdafx.h"
#include "Graphics.h"
#include "TextBox.h"
#include "EventHandler.h"
#include "Panel.h"
#include "Label.h"
#include"Button.h"
#include "BorderFactory.h"


Panel* maincopy = NULL;
vector<wstring>str;



class Form {

public:
	Form() {}
	~Form() {}
	void start() {
		//the main panel
		Panel main(29, 70);
		main.setBackground(Color::Black);
		main.setForeground(Color::White);
		main.setBorder(BorderType::Double);

		maincopy = &main;
		//box exampales
		TextBox str1(10);
		str1.setText(L"first");
		str1.setBorder(BorderType::Single);
		main.AddControl(str1, 5, 7);
		str.push_back(str1.getText());

		TextBox str2(10);
		str2.setText(L"last");
		str2.setBorder(BorderType::Single);
		main.AddControl(str2, 20, 7);
		str.push_back(str2.getText());


		//titles
		Label title(12);
		title.setText(L"   survey");
		title.setBackground(Color::White);
		title.setForeground(Color::Black);
		main.AddControl(title, 27, 1);

		Label name(15);
		name.setText(L"full name");
		name.setBackground(Color::Black);
		name.setForeground(Color::Orange);
		main.AddControl(name, 13, 5);


		Label agetest(15);
		agetest.setText(L"age(0-18)");
		agetest.setBackground(Color::Black);
		agetest.setForeground(Color::Orange);
		main.AddControl(agetest, 5, 12);

		Label educattest(15);
		educattest.setText(L"education");
		educattest.setBackground(Color::Black);
		educattest.setForeground(Color::Orange);
		main.AddControl(educattest, 25, 12);

		Label hobbytest(15);
		hobbytest.setText(L"hobby");
		hobbytest.setBackground(Color::Black);
		hobbytest.setForeground(Color::Orange);
		main.AddControl(hobbytest, 52, 12);

		Label gendertest(15);
		gendertest.setText(L"gender");
		gendertest.setBackground(Color::Black);
		gendertest.setForeground(Color::Orange);
		main.AddControl(gendertest, 50, 3);


		Button click(10);
		click.setText(L" submit!");
		click.setBorder(BorderType::Single);
		click.setBackground(Color::White);
		click.setForeground(Color::Green);
		main.AddControl(click, 30, 25);



		/*End of the Form */

		Control::setFocus(str1);
		EventHandler engine;
		engine.run(main);
	}
};



