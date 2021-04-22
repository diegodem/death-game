#include "Transportation.h"

Transportation::Transportation(SDL_Rect rect, int x, int y, int direction, bool trigger)
{
    this->rect = rect;
    this->x = (double)this->rect.x;
    this->y = (double)this->rect.y;
    this->destX = x;
    this->destY = y;
    this->direction = direction;
    this->trigger = trigger;
}

SDL_Rect *Transportation::getRect()
{
    return &rect;
}

double Transportation::getX()
{
    return x;
}

double Transportation::getY()
{
    return y;
}

int Transportation::getDestX()
{
    return destX;
}

int Transportation::getDestY()
{
    return destY;
}

int Transportation::getDirection()
{
    return direction;
}

bool Transportation::isTrigger()
{
    return trigger;
}
