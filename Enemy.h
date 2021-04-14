#pragma once
#include <SDL.h>

class Enemy
{
public:
	Enemy();
	SDL_Rect *getRect();
	double getX();
private:
	double x, y;
	SDL_Rect rect;
};