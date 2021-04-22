#include "Enemy.h"

Enemy::Enemy()
{
	x = 16;
	y = 80;
	rect = { (int)x, (int)y, 16, 32 };
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
	x += 25 * deltaTime;
	rect.x = (int)x;
}
