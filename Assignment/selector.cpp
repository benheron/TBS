#include "selector.h"

selector::selector() :worldObject()
{
	objectFileName = "images\\selector.png";
	xPos = 0;
	yPos = 0;
	col = 0;
	row = 0;
	width = TS;
	height = TS;
	onTile = new tile();
	imgNum = 7;
}

selector::~selector()
{
	delete onTile;
}

void selector::setTile(tile *t)
{
	onTile = t;
}

tile* selector::getTile()
{
	return onTile;
}

void selector::setCol(int c)
{
	col = c;
	xPos = c * TS;
}

int selector::getCol()
{
	return col;
}

void selector::setRow(int r)
{
	row = r;
	yPos = r * TS;
}

int selector::getRow()
{
	return row;
}