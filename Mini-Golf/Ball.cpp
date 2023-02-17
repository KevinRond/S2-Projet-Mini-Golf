#include "Ball.h"

Ball::Ball(int posX, int posY)
{
	originalX = posX;
	originalY = posY;
	x = posX;
	y = posY;
    ball_Strength = 0;
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
int Ball::getBallStrength()
{
    return ball_Strength;
}
void Ball::setBallStrength(int newStrength)
{
    ball_Strength = newStrength;
}
eDir Ball::getDirection()
{
	return direction;
}
void Ball::Move()
{
	switch (direction)
	{
    case STOP:
        break;
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UPLEFT:
        x--; 
        y--;
        break;
    case DOWNLEFT:
        x--; 
        y++;
        break;
    case UPRIGHT:
        x++; 
        y--;
        break;
    case DOWNRIGHT:
        x++; 
        y++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
	}
}
