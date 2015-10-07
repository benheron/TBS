#include "tile.h"

tile::tile() :worldObject()
{
	xPos = 0;
	yPos = 0;
	col = 0;
	row = 0;
	height = TS;
	width = TS;
	occupied = false;
}

tile::tile(int x, int y) :worldObject()
{
	xPos = x;
	yPos = y;
	col = xPos / TS;
	row = yPos / TS;
	height = TS;
	width = TS;
	occupied = false;
	
}

tile::~tile()
{

}


void tile::setMoveCost(int mc)
{
	moveCost = mc;
}

int tile::getMoveCost()
{
	return moveCost;
}

void tile::setCol(int c)
{
	col = c;
}

int tile::getCol()
{
	return col;
}

void tile::setRow(int r)
{
	row = r;
}

int tile::getRow()
{
	return row;
}

void tile::setTileType(int tt)
{
	tileType = tt;
}

int tile::getTileType()
{
	return tileType;
}

void tile::setOccupied(bool o)
{
	occupied = o;
}

bool tile::isOccupied()
{
	return occupied;
}

void tile::setOccUnit(unit *ou)
{
	if (ou == NULL)
	{
		delete unitOcc;
	}
	else {
		unitOcc = new unit();
	}
	unitOcc = ou;
}

unit* tile::getOccUnit()
{
	return unitOcc;
}