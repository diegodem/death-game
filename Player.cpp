#include "Player.h"

Player::Player()
{
	x = 16;
	y = 128;
	vy = 0;
	dy = 800;
	rect = { (int)x, (int)y, 16, 32 };
	footRect = { (int)x + 2, (int)y + 16, 12, 16 };
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
	isFloor = false;
}

void Player::jump()
{
	y -= 1;
	vy = -300;
}

void Player::setFloor()
{
	isFloor = true;
}
