#pragma once
#include "state.h"
#include "tile.h"
#include "map.h"
#include "selector.h"
#include <SDL.h>
#include <iostream>
#include "stateManager.h"
#include "pauseState.h"
#include "availTile.h"
#include <cmath>
#include "mainMenuState.h"
#include "winState.h"

/**
@brief The in game state class. This is where the main game happens.
*/

class ingameState :public state
{
protected:
	//the tile cursor
	selector *tileCursor;
	//the ingame tile map
	map *gameMap;
	//current tile on
	tile *currentTile;
	//the tile you've selected
	tile *selectedTile;
	//the unit you've selected
	unit *selectedUnit;
	//the available spaces you can move to
	std::vector<tile*> availSpaces;
	//vector of all your units
	std::vector<unit*> myUnits;
	//vector of all the enemy units
	std::vector<unit*> enemyUnits;

	//sprites for ui elemnts
	sprite *uiElement;
	//0
	sprite *zero;
	//1
	sprite *one;
	//2
	sprite *two;

	//current tile column
	int curTileCol;
	//current tile row
	int curTileRow;
	//tilesize
	int TS = 16;
	//counter
	float counter = 0;
	//framenumber for animations
	unsigned int frameNumber;
	//og time
	unsigned int timeThen;
	//seconds since
	int seconds;
	//is a unit selected
	bool unitSelected;
	//is it my turn
	bool myTurn;

	//the game map width
	int mapWidth;

	//the game map height
	int mapHeight;
	//counter for selecting
	int selectCounter = 0;
	//which turn it is
	int turn;

	/**
	Select the current tile
	*/
	void select();
	/**
	Find the available routes
	*/
	void findRoute();
	/**
	Find the actual tiles

	@param node node looking at
	@param int The distance left
	@returns if the node can be used
	*/
	bool tileFinder(node *n, int distLeft);
	/**
	Reset the nodes
	*/
	void resetNodes();
	/**
	Check who's turn it should be
	*/
	void checkTurn();
	/**
	check if should battle
	*/
	void checkBattle();

	/**
	The enemy's turn phase
	*/
	void enemyTurn();

	

public:
	ingameState(SDL_Renderer *renderer, stateManager *manageStates, imageManager *im);
	~ingameState();

	bool handleEvents();
	void draw(SDL_Renderer *renderer, imageManager *im);
	void update(float dt);

};