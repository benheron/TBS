#include "mainMenuState.h"
#include <iostream>


mainMenuState::mainMenuState(SDL_Renderer *renderer, stateManager *manageStates, imageManager *im) : state(renderer, manageStates, im)
{
	//create two buttons - play, quit
	playGame = new menuButton("images\\playgame.png", 46, 30);
	quitGame = new menuButton("images\\quitgame.png", 46, 80);
	buttons.push_back(playGame);
	buttons.push_back(quitGame);
	for (int i = 0; i < buttons.size(); i++)
	{
//		buttons[i]->loadImg(renderer);
	}
	selected = 0;
	onButton = false;

}

mainMenuState::~mainMenuState()
{
	for (int i = 0; i < buttons.size(); i++)
	{
		delete buttons.at(i);
	}
}

bool mainMenuState::handleEvents()
{
	int mouseX, mouseY;
	SDL_GetMouseState(&mouseX, &mouseY);
	int c = 0;

	SDL_Event events;
	while (SDL_PollEvent(&events))
	{
		switch (events.type)
		{
		case SDL_MOUSEMOTION:
			do 
			{
				if (buttons[c%2]->mouseCollide(mouseX, mouseY))
				{
					selected = c%2;
					onButton = true;
				}
				else {
					onButton = false;
				}
				c++;
			} while ((c < buttons.size()) && (onButton == false));
			break;
		case SDL_QUIT:
			return false;
			break;

		case SDL_MOUSEBUTTONDOWN:
			switch (events.button.button)
			{
			case SDL_BUTTON_LEFT:
				if (onButton)
				{
					bool tmp = select();
					if (!tmp)
					{
						return false;
					}
					return true;
				}
				std::cout << onButton << "\n";
				break;
			}
			break;
		case SDL_KEYDOWN:
			switch (events.key.keysym.sym)
			{
			case SDLK_UP:
				//go up menu option list
				selected = (selected - 1) % 2;
				break;
			case SDLK_DOWN:
				//go down menu option list
				selected = (selected + 1) % 2;

				break;
			case SDLK_ESCAPE:
				//do same as quit
				return false;
				break;
			case SDLK_SPACE:
				bool quit = select();
				if (!quit)
				{
					return false;
				}
				return true;
				break;
			}
			break;
		}
	}
	return true;
}

void mainMenuState::update(float dt)
{
	buttons[selected]->setSelected(true);
	buttons[(selected + 1) % 2]->setSelected(false);
}

void mainMenuState::draw(SDL_Renderer *renderer, imageManager *im)
{
	for (int i = 0; i < buttons.size(); i++)
	{
		buttons[i]->draw(renderer, buttons[i]->getFrameNumber(), im);
	}
}

bool mainMenuState::select()
{
	switch (selected)
	{
	case 0:
		manageStates->setState(new ingameState(rdr, manageStates, imgMan));
		break;
	case 1:
		//manageStates->clearStates();
		return false;
		break;
	}
	return true;
}
