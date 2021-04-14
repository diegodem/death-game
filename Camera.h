#pragma once
#include <math.h>

class Camera
{
public:
	Camera();
	void moveRight(float pixels);
	void moveLeft(float pixels);
	double getX();
private:
	double x, y;
};