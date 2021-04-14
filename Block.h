#pragma once

class Block
{
public:
	Block(int x, int y);
	int getX();
	int getY();
private:
	int x, y;
};