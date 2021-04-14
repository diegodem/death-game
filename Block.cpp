#include "Block.h"

Block::Block(int x, int y)
{
	this->x = x;
	this->y = y;
}

int Block::getX()
{
	return x;
}

int Block::getY()
{
	return y;
}

