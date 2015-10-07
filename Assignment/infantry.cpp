#include "infantry.h"

infantry::infantry() :unit()
{
	objectFileName = "images\\infantry.png";
	travDist = 3;
}

infantry::infantry(int col, int row) : unit(col, row)
{
	objectFileName = "images\\infantry.png";
	travDist = 3;
	imgNum = 4;
}

infantry::~infantry()
{

}
