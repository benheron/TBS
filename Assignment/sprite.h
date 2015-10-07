
#ifndef __SPRITE_H__
#define __SPRITE_H__

#include <string>

#include <SDL.h>

#include <SDL_image.h>

/// This class stores a texture image which you can draw where you want!
class sprite
{
public:

	sprite();
	~sprite();

	/// Loads a .bmp file, returns true on success or false on failure
	bool loadImgFile(std::string filename, SDL_Renderer *renderer);

	/// Specify the position of the top-left corner of the sprite
	/// Width and height are the image's original
	void Draw(int positionX, int positionY, SDL_Renderer *renderer);

	void Draw(int positionX, int positionY, SDL_Renderer *renderer, int frameNum, int spriteWidth, int spriteHeight);

protected:

	/// This variable will be our handle for the texture
	SDL_Texture *_texture;

	int width;
	int height;

};





#endif
