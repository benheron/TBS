#include "imageManager.h"

imageManager::imageManager(SDL_Renderer *renderer)
{
	//load all the image files
	availableTile = new sprite();
	availableTile->loadImgFile("images\\availmove.png", renderer);
	sprites.push_back(availableTile);

	waterTile = new sprite();
	waterTile->loadImgFile("images\\water.png", renderer);
	sprites.push_back(waterTile);

	plainsTile = new sprite();
	plainsTile->loadImgFile("images\\plains.png", renderer);
	sprites.push_back(plainsTile);

	forestTile = new sprite();
	forestTile->loadImgFile("images\\forest.png", renderer);
	sprites.push_back(forestTile);

	infantryUnit = new sprite();
	infantryUnit->loadImgFile("images\\infantry.png", renderer);
	sprites.push_back(infantryUnit);

	playButton = new sprite();
	playButton->loadImgFile("images\\playgame.png", renderer);
	sprites.push_back(playButton);

	quitButton = new sprite();
	quitButton->loadImgFile("images\\quitgame.png", renderer);
	sprites.push_back(quitButton);

	selectTile = new sprite();
	selectTile->loadImgFile("images\\selector.png", renderer);
	sprites.push_back(selectTile);

	moutainTile = new sprite();
	moutainTile->loadImgFile("images\\moutain.png", renderer);
	sprites.push_back(moutainTile);

	enInfan = new sprite();
	enInfan->loadImgFile("images\\enemyInfantry.png", renderer);
	sprites.push_back(enInfan);


	/*tankUnit = new sprite();
	tankUnit->loadImgFile("images\\tank.png", renderer);
	sprites.push_back(tankUnit);*/

	

	
}

imageManager::~imageManager()
{
	for (unsigned int i = 0; i < sprites.size(); i++)
	{
		delete sprites.at(i);
	}
	sprites.clear();
}

sprite* imageManager::getSprite(int s)
{
	return sprites[s];
}