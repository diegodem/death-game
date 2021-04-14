#pragma once
#include <SDL.h>
#include <stdio.h>

class Player
{
public:
	Player();
	void moveRight(float pixels);
	SDL_Rect *getRect();
	SDL_Rect *getFootRect();
	double getX();
	void update(float deltaTime);
	void jump();
	void setFloor();
private:
	double x, y, vy, dy;
	SDL_Rect rect;
	SDL_Rect footRect;
	bool isFloor;
};