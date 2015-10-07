#pragma once
#include "state.h"
#include "stateManager.h"
#include "mainMenuState.h"

class winstate : public state
{
protected:
	sprite* youwon;
public:
	winstate(SDL_Renderer *renderer, stateManager *manageStates, imageManager *im);
	~winstate();

	bool handleEvents();
	void update(float dt);
	void draw(SDL_Renderer *renderer, imageManager *im);

};