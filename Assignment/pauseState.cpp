#include "pauseState.h"

pauseState::pauseState(SDL_Renderer *renderer, stateManager *manageStates, imageManager *im) : state(renderer, manageStates, im)
{
	resumeGame = new menuButton("images\\playgame.png", 46, 30);
	exitGame = new menuButton("images\\quitgame.png", 46, 80);
	bg = new sprite();
	bg->loadImgFile("images\\bg.png", renderer);
	buttons.push_back(resumeGame);
	buttons.push_back(exitGame);
	selected = 0;
}

pauseState::~pauseState()
{
	for (int i = 0; i < buttons.size(); i++)
	{
		delete buttons.at(i);
	}
}

bool pauseState::handleEvents()
{

	SDL_Event events;
	while (SDL_PollEvent(&events))
	{
		switch (events.type)
		{
		case SDL_QUIT:
			return false;
			break;
		case SDL_KEYDOWN:
			switch (events.key.keysym.sym)
			{
			case SDLK_UP:
				//go up pause option list
				selected = (selected - 1) % 2;
				break;
			case SDLK_DOWN:
				//go down pause option list
				selected = (selected + 1) % 2;
				break;
			case SDLK_ESCAPE:
				//remove itself from the stack
				manageStates->removeLastState();
				break;
			case SDLK_SPACE:
				switch (selected)
				{
				case 0:
					manageStates->removeLastState();
					break;
				case 1:
					manageStates->setState(new mainMenuState(rdr, manageStates, imgMan));
					break;
				}
				break;
			}
			break;
		}
	}
	return true;
}

void pauseState::update(float dt)
{
	buttons[selected]->setSelected(true);
	buttons[(selected + 1) % 2]->setSelected(false);
}

void pauseState::draw(SDL_Renderer *renderer, imageManager *im)
{
	bg->Draw(0, 0, renderer);
	for (int i = 0; i < buttons.size(); i++)
	{
		buttons[i]->draw(renderer, buttons[i]->getFrameNumber(), im);
	}
}