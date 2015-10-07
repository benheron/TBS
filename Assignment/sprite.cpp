
#include <iostream>

#include "sprite.h"

sprite::sprite()
{
	// This is the constructor
	// Don't forget to initialise those member variables!
	_texture = NULL;
}

sprite::~sprite()
{
	// This is the destructor
	// Use SDL to clean up our texture 
	if (_texture)
	{
		SDL_DestroyTexture(_texture);
	}
}

bool sprite::loadImgFile(std::string filename, SDL_Renderer *renderer)
{
	// Just check we're not being given garbage :P
	if (filename.empty())
	{
		std::cerr << "ERROR: sprite::LoadFromBMP - empty filename given" << std::endl;
		return false;
	}

	// First we load it to what SDL calls a 'surface'
	// This is just a raw collection of pixels
	SDL_Surface *image = IMG_Load(filename.c_str());
	if (!image)
	{
		// We'll do a quick check here because it's easy to get filenames or directories wrong
		std::cerr << "ERROR: sprite::LoadFromBMP - Oh dear, sorry but I can't find your image file. This brings me great sadness :(" << std::endl;
		return false;
	}

	// Next we convert the SDL_Surface into what it calls a 'texture'
	// This is kinda similar, but because it's bound to a renderer, SDL can make some useful optimisations behind the scenes
	// This will make it draw to the screen faster
	_texture = SDL_CreateTextureFromSurface(renderer, image);

	// We've now finished with our raw pixel data, so we can get rid of it
	SDL_FreeSurface(image);

	//query texture for width and height and store them
	SDL_QueryTexture(_texture, NULL, NULL, &width, &height);

	return true;
}

void sprite::Draw(int positionX, int positionY, SDL_Renderer *renderer)
{
	// This will specify where to draw the sprite
	SDL_Rect destRect;
	// SDL has (0,0) at the top left corner - check this by playing about with the numbers!
	destRect.x = positionX;
	destRect.y = positionY;

	// Query the texture to get its original width and height
	SDL_QueryTexture(_texture, NULL, NULL, &destRect.w, &destRect.h);

	// Here we are telling the renderer to copy the texture memory to our screen,
	// at the position of the rectangle we specify
	// The parameter that's currently NULL can be used to specify another rectangle that's a sub-region of the whole image
	// This is for doing sprite animation type effects
	SDL_RenderCopy(renderer, _texture, NULL, &destRect);

}


void sprite::Draw(int positionX, int positionY, SDL_Renderer *renderer, int frameNum, int spriteWidth, int spriteHeight)
{
	// This will specify where to draw the sprite
	SDL_Rect destRect;
	// SDL has (0,0) at the top left corner - check this by playing about with the numbers!
	destRect.x = positionX;
	destRect.y = positionY;
	destRect.w = spriteWidth;
	destRect.h = spriteHeight;

	int col = (spriteWidth * frameNum) % width;
	int row = (spriteWidth * frameNum) / width;

	//where to get the sprite from in the loaded image
	SDL_Rect sourceRect;
	sourceRect.x = col;
	sourceRect.y = row * spriteHeight;
	sourceRect.w = spriteWidth;
	sourceRect.h = spriteHeight;

	// Here we are telling the renderer to copy the texture memory to our screen,
	// at the position of the rectangle we specify
	// This is for doing sprite animation type effects
	SDL_RenderCopy(renderer, _texture, &sourceRect, &destRect);
	//std::cout << "X: " << sourceRect.w << " " << "Y: " << sourceRect.h << "\n";

}
