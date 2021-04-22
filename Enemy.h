#pragma once
#include <SDL.h>

class Enemy
{
public:
	Enemy();
	SDL_Rect *getRect();
	double getX();
	void update(float deltaTime);
	void setPosition(int x, int y, int direction);
private:
	double x, y;
	int direction;
	SDL_Rect rect;
};