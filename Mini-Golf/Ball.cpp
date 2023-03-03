#include "Ball.h"
using namespace std;
Ball::Ball()
{
    originalX = 0;
    originalY = 0;
    x = 0;
    y = 0;
    ball_Strength = 0;
    direction = STOP;
}
Ball::~Ball(){}
Ball::Ball(double posX, double posY)
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
void Ball::setXY(double posX, double posY)
{
    originalX = posX;
    originalY = posY;
    x = posX;
    y = posY;
    ball_Strength = 0;
    direction = STOP;
}
void Ball::get()
{
    //return this;
}
double Ball::getX()
{
	return x;
}
double Ball::getY()
{
	return y;
}
double Ball::getBallStrength()
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
{/*
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
	}*/
}

void Ball::Display()
{
    cout << "Balle location : " << to_string(x) << "," << to_string(y) << endl;
    cout << "Velocity : " << to_string(ball_Strength) << endl;

}
