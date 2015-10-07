#pragma once
#include <vector>
#include "state.h"
//Original state manager provide by Peter Allen, modified by Ben Heron
class stateManager
{
protected:
	std::vector<state*> states;

public:
	stateManager();
	~stateManager();

	void addState(state *s);
	void removeLastState();
	void setState(state *s);
	state* getState(int n);
	bool handleStateEvents();
	void updateState(float dt);
	void drawState(SDL_Renderer *renderer, imageManager *im);
	void clearStates();


};