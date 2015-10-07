#pragma once
#include "worldObject.h"


class menuButton : public worldObject
{
protected:
	int frameNumber;
	bool selected;

public:
	menuButton(std::string fn, int x, int y);
	~menuButton();
	void onHover();
	int getFrameNumber();
	void setSelected(bool s);
	bool isSelected();
	bool mouseCollide(int mouseX, int mouseY);
};