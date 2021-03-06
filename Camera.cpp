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

void Camera::setPos(double pixels)
{
	x = std::min(std::max(0, (int)round(pixels) - 96), 3840);
}

double Camera::getX()
{
	return x;
}