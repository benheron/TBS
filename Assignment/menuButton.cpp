#include "menuButton.h"

menuButton::menuButton(std::string fn, int x, int y)
{
	objectFileName = fn;
	xPos = x;
	yPos = y;
	width = 160;
	height = 40;
	if (y == 30)
	{
		imgNum = 5;
	}
	else {
		imgNum = 6;
	}
}

menuButton::~menuButton()
{

}

void menuButton::onHover()
{
	frameNumber = (frameNumber + 1) % 2;
}

int menuButton::getFrameNumber()
{
	return frameNumber;
}

void menuButton::setSelected(bool s)
{
	selected = s;
	switch (selected)
	{
	case false:
		frameNumber = 0;
		break;
	case true:
		frameNumber = 1;
		break;

	}
}

bool menuButton::isSelected()
{
	return selected;
}

bool menuButton::mouseCollide(int mouseX, int mouseY)
{
	if (mouseX > xPos &&
		mouseX < (xPos + width) &&
		mouseY > yPos &&
		mouseY < (yPos + height))
	{
		return true;
	}
	return false;


}