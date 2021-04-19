#include "Player.h"

Player::Player()
{
	x = 16;
	y = 128;
	vy = 0;
	dy = 800;
	rect = { (int)x, (int)y, 16, 32 };
	footRect = { (int)x + 2, (int)y + 16, 12, 16 };
	bodyRect = { (int)x + 1, (int)y, 14, 30 };
	isFloor = false;
}

void Player::moveRight(float pixels)
{
	x += pixels;
}

void Player::moveLeft(float pixels)
{
	x -= pixels;
}

SDL_Rect *Player::getRect()
{
	return &rect;
}

SDL_Rect *Player::getFootRect()
{
	return &footRect;
}

SDL_Rect *Player::getBodyRect()
{
	return &bodyRect;
}

double Player::getX()
{
	return x;
}

double Player::getY()
{
	return y;
}

void Player::update(float deltaTime)
{
	
	y += vy * (double)deltaTime;
	vy += dy * (double)deltaTime;
	/*if (y >= 128.f)
	{
		y = 128.f;
		vy = 0.f;
	}*/

	rect.y = (int)y;
	footRect.y = (int)y + 16;
	bodyRect.y = (int)y;
	if (vy > (double)deltaTime * 10000)
	{
		isFloor = false;
	}
	
}

void Player::jump()
{
	if (isFloor)
	{
		y -= 1;
		vy = -300;
		isFloor = false;
	}
}

void Player::setFloor(int y)
{
	this->y = (double)y - 32.;
	rect.y = (int)this->y;
	footRect.y = (int)this->y + 16;
	bodyRect.y = (int)this->y;
	vy = 0;
	isFloor = true;
}

void Player::setWall(int x, int y)
{
	if (x > this->x + 13)
	{
		this->x = (double)x - 15.;
	}
	else if (x < this->x - 13) {
		this->x = (double)x + 15.;
	}

	else
	{
		vy = 0;
		this->y = y + 16.;
	}
}
