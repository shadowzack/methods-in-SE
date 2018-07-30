#pragma once
#ifndef LISTENERS_H
#define LISTENERS_H
#include "MouseListener.h"
#include "NumericBox.h"
#include "CheckList.h"
#include "RadioBox.h"
#include "ComboBox.h"
#include "MessageBox.h"


Panel* MainPanel = NULL;
vector<wstring>str;
class SubmitListener :public MouseListener {
private:
public:
	virtual void MousePressed(Control &control, int x, int y, bool isLeft) {
		vector<Control*> myvec;
		control.getAllControls(&myvec);
		wstring answer = L"name: ";
		for (int i = 0; i < 2; i++) {
			TextBox *tmp = static_cast<Button*>(myvec[i]);
			answer += tmp->getText() + L" ";
		}
		NumericBox *tmp = static_cast<NumericBox*>(myvec[2]);
		answer += (L"|age: " + to_wstring(tmp->getValue()) + L"\n");
		answer += L"Hobby: ";

		CheckList* temp = static_cast<CheckList*>(myvec[3]);
		vector<string> en = temp->Getallentries();
		vector<size_t> in = temp->GetallIndex();
		for (int i = 0; i < in.size(); i++) {
			answer += temp->s2ws(en[in[i]]);
			if (i != in.size() - 1)
				answer += L", ";
		}
		answer += L"\n";
		answer += L"Gender: ";
		RadioBox *ttmp = static_cast<RadioBox*>(myvec[4]);
		en = ttmp->Getallentries();
		size_t sein = ttmp->GetSelectedIndex();
		if (sein != -1)
			answer += (ttmp->s2ws(en[sein]));

		answer += L"\nEducation: ";

		ComboBox* tempo = static_cast<ComboBox*>(myvec[5]);
		sein = tempo->GetSelectedIndex();
		vector<Control*>child;
		tempo->getAllControls(&child);

		if (sein != -1) {
			Button* bb = static_cast<Button*>(child[sein]);
			answer += bb->getText();
		}

		Messagebox *tt = static_cast<Messagebox*> (myvec[myvec.size() - 1]);
		answer += L"\nDo you want to Save?";
		tt->setText(answer);
		myvec[myvec.size() - 1]->setVisibility(true);
	}
};


class messageBoxListener : public MouseListener {
public:
	virtual void MousePressed(Control &control, int x, int y, bool isLeft) {
		control.setVisibility(false);
		Messagebox* tmp = static_cast<Messagebox*>(&control);
		if (tmp->isOK()) {
			vector<Control*> vec;
			MainPanel->getAllControls(&vec);

			TextBox *tmp = static_cast<TextBox*>(vec[0]);
			tmp->setText(str[0]);
			tmp->restCursor();
			Control::setFocus(*tmp);
			tmp = static_cast<TextBox*>(vec[1]);
			tmp->setText(str[1]);
			tmp->restCursor();

			CheckList* temp = static_cast<CheckList*>(vec[3]);
			vector <size_t> *out = &temp->GetallIndex();
			out->clear();
			temp->restCursor();

		}
	}
};

#endif // !LISTENERS_H