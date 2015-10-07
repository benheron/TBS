#include "moutain.h"

mountain::mountain(int x, int y) :tile(x, y)
{
	moveCost = -1;
	imgNum = 8;
}

mountain::~mountain()
{

}