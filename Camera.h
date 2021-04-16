#pragma once
#include <math.h>
#include <algorithm>

class Camera
{
public:
	Camera();
	void moveRight(float pixels);
	void moveLeft(float pixels);
	void setPos(double pixels);
	double getX();
private:
	double x, y;
};