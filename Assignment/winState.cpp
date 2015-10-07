#include "winstate.h"

winstate::winstate(SDL_Renderer *renderer, stateManager *manageStates, imageManager *im) : state(renderer, manageStates, im)
{
	youwon = new sprite();
	youwon->loadImgFile("images\\youwon.png", renderer);
}

winstate::~winstate()
{
	
}

bool winstate::handleEvents()
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
//				
				break;
			case SDLK_DOWN:
				//go down pause option list
				
				break;
			case SDLK_ESCAPE:
				//remove itself from the stack
				manageStates->setState(new mainMenuState(rdr, manageStates, imgMan));
				break;
			case SDLK_SPACE:
				break;
			}
			break;
		}
	}
	return true;
}

void winstate::update(float dt)
{
	
}

void winstate::draw(SDL_Renderer *renderer, imageManager *im)
{
	youwon->Draw(0, 0, renderer);
}