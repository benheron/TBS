#pragma once
#include "state.h"
#include "stateManager.h"
#include "menuButton.h"
#include "mainMenuState.h"

class pauseState : public state
{
protected:
	menuButton *resumeGame;
	menuButton *exitGame;
	sprite *bg;
	std::vector<menuButton*> buttons;
	unsigned int selected;
public:
	pauseState(SDL_Renderer *renderer, stateManager *manageStates, imageManager *im);
	~pauseState();

	bool handleEvents();
	void update(float dt);
	void draw(SDL_Renderer *renderer, imageManager *im);

};