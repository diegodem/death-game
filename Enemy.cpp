#include "Enemy.h"

Enemy::Enemy()
{
	x = 0;
	y = 80;
	rect = { (int)x, (int)y, 16, 32 };
	direction = 1;
}

SDL_Rect *Enemy::getRect()
{
	return &rect;
}

double Enemy::getX()
{
	return x;
}

void Enemy::update(float deltaTime)
{
	if (direction)
	{
		x += 25. * deltaTime;
	}
	else
	{
		x -= 25. * deltaTime;
	}
	rect.x = (int)x;
	rect.y = (int)y;
}

void Enemy::setPosition(int x, int y, int direction)
{
	this->x = (double)x;
	this->y = (double)y;
	this->direction = direction;
}
