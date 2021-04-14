#include "Block.h"

Block::Block(int x, int y)
{
	this->x = x;
	this->y = y;
	rect = { x, y, 16, 16 };
}

SDL_Rect *Block::getRect()
{
	return &rect;
}

double Block::getX()
{
	return x;
}

