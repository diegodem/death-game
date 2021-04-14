#include "Enemy.h"

Enemy::Enemy()
{
	x = 256;
	y = 128;
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