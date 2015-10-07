#include "map.h"
#include <iostream>

map::map()
{
	fog = false;
	buildMap();
	addUnits();
	createNodeGraph();
}

map::~map()
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			delete tileMap[i][j];
			//delete tileMap[i].at(j);
		}
	}
	delete testUnit;
}


void map::buildMap()
{

	//test data
	width = 17;
	height = 10;


	int testData[17][10] = { 
			{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 },
			{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 },
			{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
			{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
			{ 2, 0, 1, 0, 1, 1, 1, 0, 0, 2 },
			{ 2, 2, 0, 4, 1, 1, 4, 0, 2, 2 },
			{ 2, 2, 0, 4, 0, 0, 4, 0, 2, 2 },
			{ 2, 2, 0, 4, 0, 0, 4, 0, 2, 2 },
			{ 2, 2, 1, 4, 0, 0, 4, 0, 2, 2 },
			{ 2, 0, 0, 0, 0, 0, 0, 0, 2, 2 },
			{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
			{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
			{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
			{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
			{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
			{ 2, 0, 0, 0, 0, 0, 0, 0, 0, 2 },
			{ 2, 2, 2, 2, 0, 0, 2, 2, 2, 2 }
	
	};

	for (int i = 0; i < width; i++)
	{
		std::vector<tile*> tmp;
		tileMap.push_back(tmp);
		for (int j = 0; j < height; j++)
		{
			tile *t;
			switch (testData[i][j])
			{
			case 0:
				//plains
				t = new plains(i*TS, j*TS);
				break;
			case 1:
				//forest
				t = new forest(i*TS, j*TS);
				break;
			case 2:
				//mountain
				t = new mountain(i*TS, j*TS);
				break;
			case 3:
				//hills
				t = new tile(i*TS, j*TS);
				break;
			case 4:
				//water
				t = new water(i*TS, j*TS);
				break;
			case 5:
				//sand
				t = new sand(i*TS, j*TS);
				break;
			default:
				//use default tile image
				t = new tile(i*TS, j*TS);
				break;
				
			}
			//tile *t = new tile(i*TS, j*TS);

			tileMap[i].push_back(t);
		}
	}

	

	//read map data
	//create tilemap
}

void map::addUnits()
{
	testUnit = new infantry(3, 3);
	tileMap[3][3]->setOccUnit(testUnit);
	tileMap[3][3]->setOccupied(true);


	testUnit2 = new infantry(2, 6);
	tileMap[2][6]->setOccUnit(testUnit2);
	tileMap[2][6]->setOccupied(true);

	myUnits.push_back(testUnit);
	myUnits.push_back(testUnit2);


	testUnit3 = new enemyInfantry(9, 6);
	tileMap[9][6]->setOccUnit(testUnit3);
	tileMap[9][6]->setOccupied(true);
	enemyUnits.push_back(testUnit3);


	testUnit4 = new enemyInfantry(9, 7);
	tileMap[9][7]->setOccUnit(testUnit4);
	tileMap[9][7]->setOccupied(true);
	enemyUnits.push_back(testUnit4);

}

void map::createNodeGraph()
{
	//nodeGraph *nGraph = new nodeGraph(width, height);
	
	for (int i = 0; i < width; i++)
	{
		std::vector<node*> tmp;
		nGraph.push_back(tmp);
		for (int j = 0; j < height; j++)
		{
			node *tileNode = new node(i, j);
			nGraph[i].push_back(tileNode);
		}
	}

	//create connections
	int c = 0;
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			if (i < width - 1) nGraph[i][j]->addConnection(nGraph[i + 1][j]);
			if (i > 0) nGraph[i][j]->addConnection(nGraph[i - 1][j]);
			if (j < height - 1) nGraph[i][j]->addConnection(nGraph[i][j + 1]);
			if (j > 0) nGraph[i][j]->addConnection(nGraph[i][j - 1]);
		}
	}
}

int map::getNumTiles()
{
	return width*height;
}

void map::setWidth(int w)
{
	width = w;
}

int map::getWidth()
{
	return width;
}

void map::setHeight(int h)
{
	height = h;
}

int map::getHeight()
{
	return height;
}

void map::setCols(int c)
{
	cols = c;
}

int map::getCols()
{
	return cols;
}

void map::setRows(int r)
{
	rows = r;
}

int map::getRows()
{
	return rows;
}

void map::setFog(bool f)
{
	fog = f;
}

bool map::hasFog()
{
	return fog;
}

void map::loadImg(SDL_Renderer *renderer)
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			tileMap[i][j]->loadImg(renderer);
		}
	}
	testUnit->loadImg(renderer);
	testUnit2->loadImg(renderer);
}

void map::draw(SDL_Renderer *renderer, imageManager *im)
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			tileMap[i][j]->draw(renderer, im);
		}
	}

	for (int i = 0; i < myUnits.size(); i++)
	{
		myUnits[i]->draw(renderer, im);
	}

	for (int i = 0; i < enemyUnits.size(); i++)
	{
		enemyUnits[i]->draw(renderer, im);
	}
	/*testUnit->draw(renderer, im);
	testUnit2->draw(renderer, im);
	testUnit3->draw(renderer, im);*/
}

void map::draw(SDL_Renderer *renderer, int fn, imageManager *im)
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			if (tileMap[i][j]->getTileType() == 1)
			{
				tileMap[i][j]->draw(renderer, fn, im);
			}
			else {
				tileMap[i][j]->draw(renderer, im);
			}
		}
	}

	for (int i = 0; i < myUnits.size(); i++)
	{
		myUnits[i]->draw(renderer, im);
	}

	for (int i = 0; i < enemyUnits.size(); i++)
	{
		enemyUnits[i]->draw(renderer, im);
	}
}

tile* map::getTile(int col, int row)
{
	return tileMap[col][row];
}

node* map::getNode(int x, int y)
{
	return nGraph[x][y];
}

std::vector<std::vector<node*>> map::getMapNodeGraph()
{
	return nGraph;
}

void map::clearNodeGraph()
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			nGraph[i][j]->setVisited(false);
		}
	}
}

void map::setMyUnits(std::vector<unit*> myU)
{
	myUnits = myU;
}

std::vector<unit*> map::getMyUnits()
{
	return myUnits;
}

void map::setEnemyUnits(std::vector<unit*> enU)
{
	enemyUnits = enU;
}

std::vector<unit*> map::getEnemyUnits()
{
	return enemyUnits;
}