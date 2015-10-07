#pragma once
#include "worldObject.h"
#include "tile.h"

class selector : public worldObject
{
protected:
	tile *onTile;
	int col;
	int row;
	int TS = 16;

public:
	selector();
	~selector();
	void setTile(tile *t);
	tile* getTile();

	void setCol(int c);
	int getCol();

	void setRow(int r);
	int getRow();

};