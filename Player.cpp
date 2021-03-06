#include "Player.h"

Player::Player()
{
	x = 64;
	y = 96;
	vy = 0;
	dy = 800;
	rect = { (int)x, (int)y, 13, 16 };
	footRect = { (int)x + 3, (int)y + 8, 7, 8 };
	bodyRect = { (int)x + 1, (int)y, 11, 14 };
	isFloor = false;
	currentFrame = 0;
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
	footRect.y = (int)y + 8;
	bodyRect.y = (int)y;
	if (vy > (double)deltaTime * 10000)
	{
		isFloor = false;

	}

	if (!isFloor)
	{
		if (getCurrentFrame() == 2 || getCurrentFrame() == 3)
		{
			setCurrentFrame(3);
		}
		else
		{
			setCurrentFrame(1);
		}
		frameTimer.start();
	}
	
}

bool Player::jump()
{
	if (isFloor)
	{
		y -= 1;
		vy = -200;
		isFloor = false;
		return true;
	}

	return false;
}

void Player::setFloor(int y)
{
	this->y = (double)y - 16.;
	rect.y = (int)this->y;
	footRect.y = (int)this->y + 8;
	bodyRect.y = (int)this->y;
	vy = 0;
	isFloor = true;
}

bool Player::setWall(int x, int y)
{
	if (x > this->x + 10)
	{
		this->x = (double)x - 12.;
		setCurrentFrame(0);
		frameTimer.start();
	}
	else if (x < this->x - 12) {
		this->x = (double)x + 15.;
		setCurrentFrame(2);
		frameTimer.start();
	}
	else
	{
		vy = 0;
		this->y = y + 16.;
		return true;
	}

	return false;
}

int Player::getCurrentFrame()
{
	return currentFrame;
}

void Player::setCurrentFrame(int currentFrame)
{
	this->currentFrame = currentFrame;
}

Timer *Player::getFrameTimer()
{
	return &frameTimer;
}
