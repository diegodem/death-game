#pragma once
#include <SDL.h>

class Block
{
public:
	Block(int x, int y);
	SDL_Rect *getRect();
	double getX();
private:
	double x, y;
	SDL_Rect rect;
};