#include "worldObject.h"
#include <iostream>
worldObject::worldObject()
{
	xPos = 0;
	yPos = 0;
	width = 0;
	height = 0;

	//object = new sprite();


}

worldObject::~worldObject()
{
	//delete object;
}

/*
virtual void worldObject::update(float dt)
{
	
}*/

void worldObject::setX(int x)
{
	xPos = x;
}

int worldObject::getX()
{
	return xPos;
}

void worldObject::setY(int y)
{
	yPos = y;
}

int worldObject::getY()
{
	return yPos;
}

void worldObject::setHeight(int h)
{
	height = h;
}

int worldObject::getHeight()
{
	return height;
}

void worldObject::setWidth(int w)
{
	width = w;
}

int worldObject::getWidth()
{
	return width;
}

void worldObject::loadImg(SDL_Renderer *renderer)
{
	object->loadImgFile(objectFileName, renderer);
}

void worldObject::draw(SDL_Renderer *renderer, imageManager *im)
{
	object = im->getSprite(imgNum);
	object->Draw(xPos, yPos, renderer);
}

void worldObject::draw(SDL_Renderer *renderer, int frameNumber, imageManager *im)
{
	object = im->getSprite(imgNum);
	object->Draw(xPos, yPos, renderer, frameNumber, width, height);
}