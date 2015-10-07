#pragma once
#include "worldObject.h"
#include "sprite.h"
#include "unit.h"

class tile : public worldObject
{
protected:
	//types of tiles
	const int GROUND = 0;
	const int WATER = 1;

	//tile size
	int TS = 16;
	//How much movement is hindered by this tile
	int moveCost;
	//col value - 1
	int col;
	//the row value -1
	int row;
	//whether an entity resides on this tile
	bool occupied = false;
	//The type of tile
	int tileType;
	//The unit that occupies this tile
	unit *unitOcc;
	

public:
	tile();
	tile(int x, int y);
	~tile();

	void setMoveCost(int mc);
	int getMoveCost();

	void setCol(int c);
	int getCol();

	void setRow(int r);
	int getRow();

	void setTileType(int tt);
	int getTileType();

	void setOccupied(bool o);
	bool isOccupied();

	void setOccUnit(unit *ou);
	unit* getOccUnit();

};