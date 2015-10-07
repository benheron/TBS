#pragma once
#include "sprite.h"
#include <vector>

class imageManager
{
protected:
	sprite *availableTile;
	sprite *waterTile;
	sprite *plainsTile;
	sprite *forestTile;
	sprite *infantryUnit;
	sprite *playButton;
	sprite *quitButton;
	sprite *selectTile;
	
	sprite *moutainTile;
	sprite *enInfan;



//	sprite *tankUnit;
	

	std::vector<sprite*> sprites;


public:
	imageManager(SDL_Renderer *renderer);
	~imageManager();
	sprite* getSprite(int s);


};