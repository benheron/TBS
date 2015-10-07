#pragma once

#include <SDL.h>
#include "imageManager.h"

//forward declare otherwise endless loop of opening header files
class stateManager;

class state
{
protected:
	//a reference to the state manager
	stateManager *manageStates;
	//the renderer buffer
	SDL_Renderer *rdr;
	//reference to the image manager
	imageManager *imgMan;

public:
	state(SDL_Renderer *renderer, stateManager *sM, imageManager *im);
	~state();

	/**
	Handles events
	@returns Bool to keep playing or not
	*/
	virtual bool handleEvents() = 0;
	/**
	updates
	@param float Delta Time
	*/
	virtual void update(float dt) = 0;
	/**
	Draws images for state
	@param SDL_Renderer buffer
	@param imageManager the class that holds references to all the images
	*/
	virtual void draw(SDL_Renderer *renderer, imageManager *im) = 0;
};