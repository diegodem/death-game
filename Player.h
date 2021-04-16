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
	SDL_Rect *getBodyRect();
	double getX();
	void update(float deltaTime);
	void jump();
	void setFloor(int y);
	void setWall(int x);
private:
	double x, y, vy, dy;
	SDL_Rect rect;
	SDL_Rect footRect;
	SDL_Rect bodyRect;
	bool isFloor;
};