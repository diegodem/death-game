#pragma once
#include <SDL.h>

class Block
{
public:
	Block(int x, int y);
	SDL_Rect *getRect();
	double getX();
	double getY();
private:
	double x, y;
	SDL_Rect rect;
};