#include "stateManager.h"


stateManager::stateManager()
{
	
}

stateManager::~stateManager()
{
	for (int i = 0; i < states.size();i++)
	{
		delete states.at(i);
	}
}

void stateManager::addState(state *s)
{
	states.push_back(s);
}

void stateManager::removeLastState()
{
	delete states.back();
	states.pop_back();
}

void stateManager::setState(state *s)
{
	//remove all states on the stack
	for (int i = 0; i < states.size(); i++)
	{
		delete states.at(i);
	}

	states.clear();
	addState(s);
}

state* stateManager::getState(int n)
{
	return states[n];
}

void stateManager::clearStates()
{
	for (int i = 0; i < states.size(); i++)
	{
		delete states.at(i);
	}
	states.clear();
}

bool stateManager::handleStateEvents()
{
	return states.back()->handleEvents();
}

void stateManager::updateState(float dt)
{
	states.back()->update(dt);
}

void stateManager::drawState(SDL_Renderer *renderer, imageManager *im)
{
	for (int i = 0; i < states.size(); i++)
	{
		states[i]->draw(renderer, im);
	}
}
