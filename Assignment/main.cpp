
// This is the main SDL include file
#include <SDL.h>
// iostream is so we can output error messages to console
#include <SDL_image.h>
#include <iostream>
#include "stateManager.h"
#include "ingameState.h"
#include "sprite.h"
#include "mainMenuState.h"
#include "imageManager.h"

int main(int argc, char *argv[])
{
	// This is our initialisation phase

	// SDL_Init is the main initialisation function for SDL
	// It takes a 'flag' parameter which we use to tell SDL what systems we're going to use
	// Here, we want to use SDL's video system, so we give it the flag for this
	// Incidentally, this also initialises the input event system
	// This function also returns an error value if something goes wrong
	// So we can put this straight in an 'if' statement to check and exit if need be
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		// Something went very wrong in initialisation, all we can do is exit
		std::cout << "Whoops! Something went very wrong, cannot initialise SDL :(" << std::endl;
		return -1;
	}



	// Now we have got SDL initialised, we are ready to create a window!
	// These are some variables to help show you what the parameters are for this function
	// You can experiment with the numbers to see what they do
	int winPosX = 100;
	int winPosY = 100;
	int winWidth = 272;
	int winHeight = 240;
	SDL_Window *window = SDL_CreateWindow("Assignment - Ben Heron",
		winPosX, winPosY,
		winWidth, winHeight,
		SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);


	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);


	unsigned int lastTime = SDL_GetTicks();

	stateManager manageStates;
	imageManager im(renderer);

	manageStates.addState(new mainMenuState(renderer, &manageStates, &im));


	bool go = true;
	while (go)
	{
		unsigned int currentTime = SDL_GetTicks();
		float dt = (currentTime - lastTime) / 1000.0f;
		lastTime = currentTime;

		//handle all events
		go = manageStates.handleStateEvents();


		// update current state
		manageStates.updateState(dt);


		// Start by clearing what was drawn before
		// Set the colour for drawing
		SDL_SetRenderDrawColor(renderer, 0x0, 0x0, 0x0, 0xFF);
		// Clear the entire screen to our selected colour
		SDL_RenderClear(renderer);

		//drawing
		manageStates.drawState(renderer, &im);

		// This tells the renderer to actually show its contents to the screen
		SDL_RenderPresent(renderer);
	}

	// If we get outside the main game loop, it means our user has requested we exit


	// Our cleanup phase, hopefully fairly self-explanatory ;)
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
