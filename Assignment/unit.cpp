#include "unit.h"


unit::unit() :worldObject()
{
	health = 10;
	selected = false;
}

unit::unit(int col, int row) : worldObject()
{
	xPos = col * TS;
	yPos = row * TS;
	selected = false;
	moved = false;
}

unit::~unit()
{
	
}

void unit::moveUnit(int x, int y)
{
	xPos = x;
	yPos = y;
}


void unit::setHealth(int h)
{
	health = h;
}

int unit::getHealth()
{
	return health;
}

void unit::setPower(int p)
{
	power = p;
}

int unit::getPower()
{
	return power;
}

void unit::setDefense(int d)
{
	defense = d;
}

int unit::getDefense()
{
	return defense;
}

void unit::setSelected(bool s)
{
	selected = s;
}

bool unit::isSelected()
{
	return selected;
}

void unit::setTravDist(int td)
{
	travDist = td;
}

int unit::getTravDist()
{
	return travDist;
}

void unit::setCol(int col)
{
	xPos = col*TS;
}

int unit::getCol()
{
	return xPos*TS;
}


void unit::setMoved(bool m)
{
	moved = m;
}

bool unit::getMoved()
{
	return moved;
}

void unit::setDestroyed(bool d)
{
	destroyed = d;
}

bool unit::isDestroyed()
{
	return destroyed;
}
