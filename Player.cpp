#include "Player.h"

Player::Player()
{
	x = 16;
	y = 128;
	vy = 0;
	dy = 800;
	rect = { (int)x, (int)y, 16, 32 };
	footRect = { (int)x + 2, (int)y + 16, 12, 16 };
	bodyRect = { (int)x + 1, (int)y, 14, 24 };
	isFloor = false;
}

void Player::moveRight(float pixels)
{
	x += pixels;
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
	isFloor = false;
}

void Player::jump()
{
	y -= 1;
	vy = -300;
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

void Player::setWall(int x, int cameraX)
{
	if (x > this->x)
	{
		this->x = (double)x - 16.;
	}
	else {
		this->x = (double)x + 16.;
	}

	rect.x = (int)this->x - cameraX;
	footRect.x = (int)this->x + 2 - cameraX;
	bodyRect.x = (int)this->x + 1 - cameraX;
}
