#pragma once
#include <vector>
#include "menuButton.h"

class menu
{
protected:
	std::vector<menuButton*> buttons;
	int numButtons;
	int buttonSelected;
public:
	menu(std::vector<menuButton*> b);
	~menu();

	void setButtonSelected(int bs);
	int getButtonSelected();
};