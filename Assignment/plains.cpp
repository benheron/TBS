#include "plains.h"

plains::plains(int x, int y) :tile(x, y)
{
	moveCost = 1;
	objectFileName = "images\\plains.png";
	tileType = GROUND;
	imgNum = 2;
}

plains::~plains()
{

}