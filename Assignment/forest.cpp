#include "forest.h"

forest::forest(int x, int y) : tile(x, y)
{
	objectFileName = "images\\forest.png";
	moveCost = 2;
	tileType = GROUND;
	imgNum = 3;
}

forest::~forest()
{

}