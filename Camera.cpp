#include "Camera.h"

Camera::Camera()
{
	x = 0;
	y = 0;
}

void Camera::moveRight(float pixels)
{
	x += pixels;
}

void Camera::moveLeft(float pixels)
{
	x -= pixels;
}

double Camera::getX()
{
	return x;
}