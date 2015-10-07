#include "sand.h"

sand::sand(int x, int y) :tile(x, y)
{
	moveCost = 2;
	objectFileName = "images\\sand.png";
	tileType = GROUND;
	imgNum = 5;
}

sand::~sand()
{

}