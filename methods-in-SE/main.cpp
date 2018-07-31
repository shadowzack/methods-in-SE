
#include "stdafx.h"
#include "Graphics.h"
#include "TextBox.h"
#include "EventHandler.h"
#include "Panel.h"
#include "Label.h"
#include "Button.h"
#include "BorderFactory.h"
#include "Listeners.h"



SingletonFocused* SingletonFocused::_instance = 0;

messageBoxListener messagebox_listener;
SubmitListener submit_listener;
int main()
{

	//panel contanier
	Panel panel(50, 36);
	panel.setBackground(Color::Black);
	panel.setForeground(Color::White);
	panel.setBorder(BorderType::Double);
	MainPanel = &panel;

	Label title(12);
	title.setText(L"register");
	title.setBackground(Color::White);
	title.setForeground(Color::Black);
	panel.AddControl(title, 12, 2);

	Label name(15);
	name.setText(L"full name");
	name.setBackground(Color::Black);
	name.setForeground(Color::White);
	panel.AddControl(name, 12, 7);

	//text boxes
	TextBox textbx1(10);
	textbx1.setText(L"first");
	textbx1.setBorder(BorderType::Single);
	panel.AddControl(textbx1, 6, 10);
	str.push_back(textbx1.getText());

	TextBox textbx2(10);
	textbx2.setText(L"last");
	textbx2.setBorder(BorderType::Single);
	panel.AddControl(textbx2, 19, 10);
	str.push_back(textbx2.getText());

	Label agetest(15);
	agetest.setText(L"age(0-18)");
	agetest.setBackground(Color::Black);
	agetest.setForeground(Color::White);
	panel.AddControl(agetest, 12, 13);

	NumericBox age(4, 0, 18);
	age.setBorder(BorderType::Single);
	panel.AddControl(age, 12, 17);

	vector<string> movies;
	movies.push_back("Lord of the rings");
	movies.push_back("batman");
	movies.push_back("the avengers");
	movies.push_back("mia khalaifa");

	Label moviestest(15);
	moviestest.setText(L"movies");
	moviestest.setBackground(Color::Black);
	moviestest.setForeground(Color::White);
	panel.AddControl(moviestest, 12, 20);

	/*CheckList mvs(10, 2, movies);
	mvs.setBorder(BorderType::Single);
	panel.AddControl(mvs, 12, 40);*/


	Label gendertest(15);
	gendertest.setText(L"gender");
	gendertest.setBackground(Color::Black);
	gendertest.setForeground(Color::White);
	panel.AddControl(gendertest, 12, 30);

	vector<string> genders;
	genders.push_back("male");
	genders.push_back("female");

	
	RadioBox gender(7, 2, genders);
	gender.setBorder(BorderType::Single);
	panel.AddControl(gender, 12, 33);


	Label JobTitleTest_header(15);
	JobTitleTest_header.setText(L"job Title");
	JobTitleTest_header.setBackground(Color::Black);
	JobTitleTest_header.setForeground(Color::White);
	panel.AddControl(JobTitleTest_header, 12, 38);

	vector<string> JobTitle;
	JobTitle.push_back("software engineer");
	JobTitle.push_back("designer");
	JobTitle.push_back("civil engineer");

	ComboBox JobTitleTest(10, JobTitle);
	JobTitleTest.setBorder(BorderType::Single);
	panel.AddControl(JobTitleTest, 12, 41);

	//submit button
	Button click(10);
	click.setText(L" submit");
	click.setBorder(BorderType::Double);
	click.setBackground(Color::White);
	click.setForeground(Color::Blue);
	panel.AddControl(click, 12, 45);

	//event handling and starting object
	Control::setFocus(textbx1);
	EventHandler handler;
	handler.run(panel);

	return 0;
}