#include "menu.h"

menu::menu(std::vector<menuButton*> b)
{
	numButtons = b.size();

	for (int i = 0; i < numButtons; i++)
	{
		buttons[i] = b[i];
	}
}

menu::~menu()
{

}

void menu::setButtonSelected(int bs)
{
	buttonSelected = bs;
}

int menu::getButtonSelected()
{
	return buttonSelected;
}