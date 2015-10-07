#pragma once
#include "state.h"
#include "menuButton.h"
#include <vector>
#include <SDL.h>
#include "ingameState.h"

class mainMenuState : public state{
protected:
	const int PLAY = 0;
	const int QUIT = 1;

	std::vector <menuButton*> buttons;
	menuButton *playGame;
	menuButton *quitGame;
	unsigned int selected;
	bool onButton;

	bool select();
public:
	mainMenuState(SDL_Renderer *renderer, stateManager *manageStates, imageManager *im);
	~mainMenuState();

	bool handleEvents();
	void update(float dt);
	void draw(SDL_Renderer *renderer, imageManager *im);
};