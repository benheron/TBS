#include "enemyInfantry.h"

enemyInfantry::enemyInfantry() :unit()
{
	travDist = 3;
}

enemyInfantry::enemyInfantry(int col, int row) : unit(col, row)
{
	travDist = 3;
	imgNum = 9;
}

enemyInfantry::~enemyInfantry()
{

}
