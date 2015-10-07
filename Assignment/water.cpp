#include "water.h"
#include <iostream>

water::water(int x, int y) : tile(x, y)
{
	imgNum = 1;
	objectFileName = "images\\water.png";
	tileType = WATER;
	moveCost = -1;
}

water::~water()
{

}