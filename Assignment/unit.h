#pragma once
#include "worldObject.h"
#include <string.h>

class unit:public worldObject {
protected:
	int health;
	bool moved;
	int power;
	int defense;
	bool selected;
	int travDist;
	bool destroyed;
	//tile *unitTile;
	//int col;
	//int row;
	

public:
	unit();
	unit(int col, int row);
	~unit();

	void moveUnit(int x, int y);
	void setHealth(int h);
	int getHealth();
	void setPower(int p);
	int getPower();
	void setDefense(int d);
	int getDefense();
	void setSelected(bool s);
	bool isSelected();
	void setTravDist(int td);
	int getTravDist();
	void setCol(int col);
	int getCol();
	void setRow(int row);
	int getRow();
	void setMoved(bool m);
	bool getMoved();
	void setDestroyed(bool d);
	bool isDestroyed();

	void setImage(std::string fn);
	std::string getImage();

	void select();

};