#include "ingameState.h"



ingameState::ingameState(SDL_Renderer *renderer, stateManager *manageStates, imageManager *im) :state(renderer, manageStates, im)
{
	tileCursor = new selector();
	gameMap = new map();
	currentTile = new tile();
	//holds the tile the unit is selected upon
	selectedTile = new tile();
	//  local variable to hold the currently selected unit
	selectedUnit = new unit();
	//frames start at 0
	frameNumber = 0;

	//first turn
	turn = 1;
	counter = 0;

	//no unit is selected
	unitSelected = false;

	//initial time stamp
	timeThen = SDL_GetTicks();

	//get map dimensions
	mapWidth = gameMap->getWidth();
	mapHeight = gameMap->getHeight();

	//initial selected tile is at 0,0
	currentTile = gameMap->getTile(0, 0);
	tileCursor->setTile(currentTile);

	curTileCol = 0;
	curTileRow = 0;

	//local variable to check if a unit is currently being selected
	unitSelected = false;

	//node graph is cleared
	gameMap->clearNodeGraph();

	//my turn first
	myTurn = true;

	myUnits = gameMap->getMyUnits();
	enemyUnits = gameMap->getEnemyUnits();

	uiElement = new sprite();
	uiElement->loadImgFile("images\\ui.png", renderer);

	zero = new sprite();
	zero->loadImgFile("images\\0.png", renderer);
	one = new sprite();
	one->loadImgFile("images\\1.png", renderer);
	two = new sprite();
	two->loadImgFile("images\\2.png", renderer);
}

ingameState::~ingameState()
{
	delete tileCursor;
	delete gameMap;
	delete currentTile;
	delete selectedTile;
	delete selectedUnit;

	delete zero;
	delete one;
	delete two;
	delete uiElement;
}

bool ingameState::handleEvents()
{
	currentTile = tileCursor->getTile();
	curTileCol = currentTile->getCol();
	curTileRow = currentTile->getRow();
	int x, y;
	SDL_GetMouseState(&x, &y);
	int mouseCol = x/TS;
	int mouseRow = y/TS;

	SDL_Event events;
	while (SDL_PollEvent(&events))
	{
		switch (events.type)
		{
		case SDL_QUIT:
			return false;
			break;
		case SDL_MOUSEMOTION:
			if (mouseCol > -1 && mouseCol < mapWidth &&
				mouseRow > -1 && mouseRow < mapHeight)
			{
				curTileCol = mouseCol;
				curTileRow = mouseRow;
			}
			break;
		case SDL_MOUSEBUTTONDOWN:
			switch (events.button.button)
			{
			case SDL_BUTTON_LEFT:
				select();
				break;
			}
			break;
		case SDL_KEYDOWN:
			switch (events.key.keysym.sym)
			{
			case SDLK_UP:
				//move selector up
				if (curTileRow > 0)
				{
					curTileRow -= 1;
				}
				break;
			case SDLK_DOWN:
				//move selector down
				if (curTileRow < (mapHeight - 1))
				{
					curTileRow += 1;
				}
				break;
			case SDLK_RIGHT:
				//move selector right
				if (curTileCol < (mapWidth -1) ) 
				{
					curTileCol += 1;
				}
				break;
			case SDLK_LEFT:
				//move selector left
				if (curTileCol > 0) 
				{
					curTileCol -= 1;
				}
				break;
			case SDLK_ESCAPE:
				//pause state
				manageStates->addState(new pauseState(rdr, manageStates, imgMan));
				break;
			case SDLK_RETURN:
				myTurn = false;
				break;
			case SDLK_SPACE:
				//check if occupied
				
				select();
				
				std::cout << unitSelected << "\n";



				//std::cout << "X: " << currentTile->getCol() + 1 << " " << "Y: " << currentTile->getRow() + 1 << "\n";
				break;
			}
		}
	}
	return true;
}

void ingameState::update(float dt)
{
	//update curose position
	tileCursor->setCol(curTileCol);
	tileCursor->setRow(curTileRow);
	tileCursor->setTile(gameMap->getTile(curTileCol, curTileRow));

	//if not my turn, it's enemy's turn
	if (!myTurn)
	{
		enemyTurn();
	}

	unsigned int timeNow = SDL_GetTicks();
	int timeSince = timeNow - timeThen;
	
	if (timeSince > 800) 
	{
		frameNumber++;
		timeThen = timeNow;
		if (frameNumber > 9) {
			frameNumber = 0;
		}
	}

	//if out of units, go to main menu
	if (!myUnits.size())
	{
		manageStates->setState(new mainMenuState(rdr, manageStates, imgMan));
	}

	//if enemy is destroyed, go to win state
	if (!enemyUnits.size())
	{
		manageStates->setState(new winstate(rdr, manageStates, imgMan));
	}

}

void ingameState::draw(SDL_Renderer *renderer, imageManager *im)
{
	gameMap->draw(renderer, frameNumber %2, im);
	

	if (unitSelected)
	{
		//draw available places
		for (int i = 0; i < availSpaces.size(); i++)
		{
			//availSpaces[i]->loadImg(renderer);
			availSpaces[i]->draw(renderer, im);
		}
	}
	//draw selector
	tileCursor->draw(renderer, frameNumber % 2, im);
	//draw ui element
	uiElement->Draw(0, 160, renderer);

	//draw numbers
	switch (enemyUnits.size())
	{
	case 0:
		zero->Draw(200, 180, renderer);
		break;
	case 1:
		one->Draw(200, 180, renderer);
		break;
	case 2:
		two->Draw(200, 180, renderer);
		break;
	}


}

void ingameState::select()
{
	//is a unit currently selected
	if (unitSelected)
	{
		//is the tile occupied
		if (currentTile->isOccupied())
		{
			//deselect
			selectedTile->getOccUnit()->setSelected(false);
			unitSelected = false;
		}
		else {
			//check if an available space
			//loop through available spaces
			for (int i = 0; i < availSpaces.size(); i++)
			{
				//check if where you're trying to move is a space available
				if (currentTile->getCol() == availSpaces[i]->getCol() &&
					currentTile->getRow() == availSpaces[i]->getRow())
				{
					//move to the tile selected
					currentTile->setOccUnit(selectedUnit);
					currentTile->setOccupied(true);
					selectedUnit->setX(curTileCol * TS);
					selectedUnit->setY(curTileRow * TS);

					//unit has move for this turn
					selectedUnit->setMoved(true);



					//deselect
					selectedTile->setOccupied(false);
					selectedTile->getOccUnit()->setSelected(false);

					//deallocate
					//selectedTile->setOccUnit(NULL);
					//unit no longer selected
					unitSelected = false;

					//check if turn should end
					checkTurn();
				}
			}
			
		}
	}
	else {
		//if nothing is selected
		//check if tile is occupied
		if (currentTile->isOccupied())
		{
			//has the unit occupying this tile already moved
			if (!currentTile->getOccUnit()->getMoved())
			{

				//select unit
				currentTile->getOccUnit()->setSelected(true);
				unitSelected = true;
				selectedUnit = currentTile->getOccUnit();
				selectedTile = currentTile;
				findRoute();
				std::cout << "X: " << currentTile->getCol() << " " << "Y: " << currentTile->getRow() << " Occupied\n";
			}
		}
		else {
			//display a little menu allowing end of turn
			std::cout << "X: " << currentTile->getCol() << " " << "Y: " << currentTile->getRow() << " Isn't Occupied\n";
		}
	}

	if (!unitSelected)
	{
		resetNodes();
	}
}

void ingameState::findRoute()
{
	//get original position
	int origCol = selectedUnit->getX() / TS;
	int origRow = selectedUnit->getY() / TS;
	int movSpace = selectedUnit->getTravDist();
	//initials node
	node *startNode = gameMap->getNode(origCol, origRow);
	startNode->setVisited(true);
	//get node graph
	std::vector<std::vector<node*>> nodes = gameMap->getMapNodeGraph();
	//distance the unit can travel
	int unitTravDist = selectedUnit->getTravDist();
	bool findTiles = false;

	//find all tiles available
	while (!findTiles)
	{
		findTiles = tileFinder(startNode, unitTravDist);
	}

	//loop through nodes and add positions visited to available tiles vector
	for (int i = 0; i < mapWidth; i++)
	{
		for (int j = 0; j < mapHeight; j++)
		{
			if (nodes[i][j]->getVisited())
			{
				availTile *t = new availTile(i*TS, j*TS);
				availSpaces.push_back(t);
			}
		}
	}
}


bool ingameState::tileFinder(node *n, int distLeft)
{
	//if distance left is lower than 0
	if (distLeft < 0)
	{
		distLeft = 0;
	}
	//get node position
	int nx = n->getX();
	int ny = n->getY();
	tile *dl = gameMap->getTile(nx, ny);
	int ml = dl->getMoveCost();

	//if move cost is -1, it is impassable
	if ((ml == -1))
	{
		return false;
	}
	//if there is still some distance left to go
	if (distLeft)
	{
		//take away environmental movement cost
		distLeft -= dl->getMoveCost();
		//get connections
		std::vector<node*> cons = n->getConnections();
		//loop through node connections
		for (int i = 0; i < n->getNumConnections(); i++)
		{
			//add nodes to visited if other nodes return true
			cons[i]->setVisited(tileFinder(cons[i], distLeft));
		}
	}
	return true;
}

void ingameState::resetNodes()
{
	//clear the node graph
	gameMap->clearNodeGraph();

	//clear available spaces
	for (int i = availSpaces.size()-1; i > -1; i--)
	{
		delete availSpaces.back();
		availSpaces.pop_back();
	}
}

void ingameState::checkTurn()
{
	checkBattle();
	int a = 0;
	int b = 0;
	if (myTurn)
	{
		if (myUnits.size())
		{
			//check all of my units
			for (unsigned int i = 0; i < myUnits.size(); i++)
			{
				if (myUnits[i]->getMoved())
				{
					a++;
				}
			}
		}

		if (a == (myUnits.size()))
		{
			myTurn = false;
			//set enemy units as available to move
			for (unsigned int j = 0; j < enemyUnits.size(); j++)
			{
				enemyUnits[j]->setMoved(false);
			}
		}

	}
	else {
		if (enemyUnits.size())
		{
			for (unsigned int i = 0; i < enemyUnits.size(); i++)
			{
				if (enemyUnits[i]->getMoved())
				{
					b++;
				}
			}
		}

		if (b == (enemyUnits.size()))
		{
			myTurn = true;
			for (unsigned int i = 0; i < myUnits.size(); i++)
			{
				myUnits[i]->setMoved(false);
				turn += 1;
			}
		}
	}

	
}

void ingameState::enemyTurn()
{
	for (unsigned int i = 0; i < enemyUnits.size(); i++)
	{
		//closest unit to the one checked
		unit *closTarget;
		tile *closTile;

		//get unit tile
		int ex = enemyUnits[i]->getX() / TS;
		int ey = enemyUnits[i]->getY() / TS;

		//make the selected tile the first enemy unit in the vector
		selectedTile = gameMap->getTile(ex, ey);
		selectedUnit = enemyUnits[i];

		//select it to find available spaces
		findRoute();

		//suitably high number for initial distance between units
		int distU = 999999;
		//loop through my units and find the closest
		for (unsigned int j = 0; j < myUnits.size(); j++)
		{
			//get unit position
			int mx = myUnits[j]->getX() / TS;
			int my = myUnits[j]->getY() / TS;

			//temporary values for distance between units
			int xDist = abs(ex - mx);
			int yDist = abs(ey - my);

			//this distance between the units
			int thisDist = xDist + yDist;

			//if this distance is the lowest, it is the closest unit
			if (thisDist < distU)
			{
				distU = thisDist;
				closTarget = myUnits[j];
			}

		}

		//get position of the unit being targeted
		int ctX = closTarget->getX() / TS;
		int ctY = closTarget->getY() / TS;

		//suitably high number for initial distance between tiles
		int distT = 9999;
		//move as close as it can
		for (unsigned int k = 0; k < availSpaces.size(); k++)
		{
			//get the position of the current searched available tile
			int atX = availSpaces[k]->getCol();
			int atY = availSpaces[k]->getRow();

			//temporary values for distance between units
			int xDist = abs(atX - ctX);
			int yDist = abs(atY - ctY);

			//this distance between the tiles
			int thisDist = xDist + yDist;

			//if this distance is the lowest, it is the closest unit
			if (thisDist < distT && !(thisDist == 0))
			{
				distT = thisDist;
				closTile = availSpaces[k];
			}

		}
		int xx = closTile->getX()/TS;
		int yy = closTile->getY()/TS;

		//make closest tile a tile on the map rather than offset tile
		closTile = gameMap->getTile(xx, yy);

		closTile->setOccUnit(selectedUnit);
		closTile->setOccupied(true);
		selectedUnit->setX(closTile->getX());
		selectedUnit->setY(closTile->getY());

		//unit has move for this turn
		selectedUnit->setMoved(true);

		//deselect
		selectedTile->setOccupied(false);

		resetNodes();

		//if next to unit, fire
	}
	checkBattle();
	checkTurn();
}



void ingameState::checkBattle()
{
	//initialise
	int mx = 0;
	int my = 0;
	int ex = 0;
	int ey = 0;
	//loop through my units
	for (int i = 0; i < myUnits.size(); i++)
	{
		//get positions
		mx = myUnits[i]->getX()/TS;
		my = myUnits[i]->getY()/TS;
		//loop through enemy units
		for (int j = 0; j < enemyUnits.size(); j++)
		{
			//get enemy positions
			ex = enemyUnits[j]->getX()/TS;
			ey = enemyUnits[j]->getY()/TS;
			//check if the two units are next to each other
			if (((mx+1) == ex && my == ey)||
				((mx-1) == ex && my == ey)||
				(mx == ex && (my + 1) == ey) ||
				(mx == ex &&( my - 1) == ey))
			{
				//next to another unit
				if (myTurn)
				{
					//if my turn, delete enemy unit
					delete enemyUnits[j];
					enemyUnits.erase(enemyUnits.begin() + j);
					gameMap->setEnemyUnits(enemyUnits);
					tile *tmp = gameMap->getTile(ex, ey);
					tmp->setOccupied(false);
				}
				else {
					//if enemy turn, delete my unit
					delete myUnits[i];
					myUnits.erase(myUnits.begin() + i);
					gameMap->setMyUnits(myUnits);
					tile *tmp = gameMap->getTile(mx, my);
					tmp->setOccupied(false);
				}
			}
		}
	}
}