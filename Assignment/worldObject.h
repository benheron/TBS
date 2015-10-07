#pragma once
#include "sprite.h"
#include <string.h>
#include <SDL.h>
#include "imageManager.h"

class worldObject
{
protected:
	//tile size
	int TS = 16;
	//x position
	int xPos;
	//y position
	int yPos;
	//width
	int width;
	//the height
	int height;
	//the sprite reference this object is using
	sprite *object;
	//the file name
	std::string objectFileName;
	//number of frames in sprite
	int numOfFrames;
	//image number used to grab reference
	int imgNum;



public:
	worldObject();
	~worldObject();

	/**
	Sets x position
	@param int x position
	*/
	void setX(int);
	/**
	Gets x position
	@returns X position
	*/
	int getX();
	/**
	Sets y position
	@param int y position
	*/
	void setY(int);
	/**
	Gets y position
	@returns int y position
	*/
	int getY();
	/**
	Sets height of object
	@param int object height
	*/
	void setHeight(int);
	/**
	Gets the height of the object
	@returns the object height
	*/
	int getHeight();
	/**
	Sets the width of the object
	@param int object width
	*/
	void setWidth(int);
	/**
	Gets the width of the object
	@returns int width of object
	*/
	int getWidth();

	void loadImg(SDL_Renderer *renderer);
	void draw(SDL_Renderer *renderer, imageManager *im);
	/**
	Draws the specific frame of an image
	*/
	void draw(SDL_Renderer *renderer, int frame, imageManager *im);
};