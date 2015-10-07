#pragma once
#include <SDL.h>
#include <vector>
#include "tile.h"
#include "forest.h"
#include "sand.h"
#include "water.h"
#include "plains.h"
#include "unit.h"
#include "infantry.h"
#include "tank.h"
#include "nodeGraph.h"
#include "moutain.h"
#include "enemyInfantry.h"

class map
{
protected:
	//if the map has fog
	bool fog;
	//the height
	int height;
	//the width
	int width;
	//columns
	int cols;
	//rows
	int rows;
	//tile size
	int TS = 16;
	//2d vector of tiles
	std::vector<std::vector<tile*>> tileMap;
	//2d vector of nodes
	std::vector<std::vector<node*>> nGraph;
	//all of my units
	std::vector<unit*> myUnits;
	//all of the enemy units
	std::vector<unit*> enemyUnits;
	//std::vector<unit*> mapUnits;

	//infantry 1
	infantry *testUnit;
	//infantry 2
	infantry *testUnit2;
	//Enemy infantry 1
	enemyInfantry *testUnit3;
	//Enemy infantry 2
	enemyInfantry *testUnit4;

	/**
	builds the mpa
	*/
	void buildMap();
	/**
	Adds the units
	*/
	void addUnits();
	/**
	creates the basic node graph for the specific map
	*/
	void createNodeGraph();


public:
	map();
	~map();
	/**
	Gets number of tiles
	@returns int Number of tiles
	*/
	int getNumTiles();

	/**
	Sets the width of the map
	@param int map width
	*/
	void setWidth(int w);
	/**
	Gets the width of the map
	@returns int map width
	*/
	int getWidth();
	/**
	Sets the map height
	@param int map height
	*/
	void setHeight(int h);
	/**
	Gets the map height
	@returns the map height
	*/
	int getHeight();

	/**
	Sets the number of columns
	@param int number of columns
	*/
	void setCols(int c);
	/**
	Gets the number of columns
	@returns int number of columns
	*/
	int getCols();
	/**
	sets the number of rows
	@param int the number of rows
	*/
	void setRows(int r);
	/**
	Gets the number of rows
	@returns the number of rows
	*/
	int getRows();

	/**
	Sets if fog
	@param bool fog value
	*/
	void setFog(bool f);
	/**
	Gets if fog
	~returns fog value
	*/
	bool hasFog();

	void loadImg(SDL_Renderer *renderer);
	void draw(SDL_Renderer *renderer, imageManager *im);
	void draw(SDL_Renderer *renderer, int fn, imageManager *im);


	tile* getTile(int col, int row);
	node* getNode(int x, int y);

	std::vector<std::vector<node*>> getMapNodeGraph();
	void clearNodeGraph();
	void setMyUnits(std::vector<unit*> myU);
	std::vector<unit*> getMyUnits();
	void setEnemyUnits(std::vector<unit*> enU);
	std::vector<unit*> getEnemyUnits();
};