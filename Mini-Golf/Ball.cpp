#include "Ball.h"

Ball::Ball(int posX, int posY)
{
	originalX = posX;
	originalY = posY;
	x = posX;
	y = posY;
	direction = STOP;
}
void Ball::Reset()
{
	x = originalX;
	y = originalY;
	direction = STOP;
}
void Ball::changeDirection(eDir d)
{
	direction = d;
}
int Ball::getX()
{
	return x;
}
int Ball::getY()
{
	return y;
}
inline eDir Ball::getDirection()
{
	return direction;
}
void Ball::Move(int force)
{
	switch (direction)
	{
    case STOP:
        break;
    case LEFT:
        x -= force;
        break;
    case RIGHT:
        x += force;
        break;
    case UPLEFT:
        x -= force; 
        y -= force;
        break;
    case DOWNLEFT:
        x -= force; 
        y += force;
        break;
    case UPRIGHT:
        x += force; 
        y -= force;
        break;
    case DOWNRIGHT:
        x += force; 
        y += force;
        break;
    case UP:
        y -= force;
        break;
    case DOWN:
        y += force;
        break;
    default:
        break;
	}
}
