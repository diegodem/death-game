#pragma once
#include <SDL.h>
#include <stdio.h>
#include "Timer.h"

class Player
{
public:
	Player();
	void moveRight(float pixels);
	void moveLeft(float pixels);
	SDL_Rect *getRect();
	SDL_Rect *getFootRect();
	SDL_Rect *getBodyRect();
	double getX();
	double getY();
	void update(float deltaTime);
	bool jump();
	void setFloor(int y);
	bool setWall(int x, int y);
	int getCurrentFrame();
	void setCurrentFrame(int currentFrame);
	Timer *getFrameTimer();
private:
	double x, y, vy, dy;
	SDL_Rect rect;
	SDL_Rect footRect;
	SDL_Rect bodyRect;
	bool isFloor;
	int currentFrame;
	Timer frameTimer;
};