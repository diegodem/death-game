#pragma once
#include <SDL.h>

class Transportation
{
public:
	Transportation(SDL_Rect rect, int x, int y, int direction, bool trigger);
	SDL_Rect *getRect();
	double getX();
	double getY();
	int getDestX();
	int getDestY();
	int getDirection();
	bool isTrigger();
private:
	double x, y;
	int destX, destY, direction;
	SDL_Rect rect;
	bool trigger;

};