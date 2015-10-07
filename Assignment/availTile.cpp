#include "availTile.h"

availTile::availTile() :tile()
{
}

availTile::availTile(int x, int y) :tile(x, y)
{
	objectFileName = "images\\availmove.png";
	imgNum = 0;
}