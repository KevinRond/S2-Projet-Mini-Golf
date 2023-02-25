#include "Ball.h"

Ball::Ball(int posX, int posY)
{
	originalX = posX;
	originalY = posY;
	x = posX;
	y = posY;
    strength = 0;
	direction = 90;
}
void Ball::Reset()
{
	x = originalX;
	y = originalY;
	direction = 90;
}
void Ball::setDirection(double new_angle)
{
	direction = new_angle;
}
int Ball::getX()
{
	return x;
}
int Ball::getY()
{
	return y;
}
double Ball::getStrength()
{
    return strength;
}
void Ball::setStrength(double newStrength)
{
    strength = newStrength;
}
double Ball::radToDeg(double rad)
{
    double degree;
    degree = rad * (180 / 3.14159);
    return degree;
}
double Ball::degToRad(double deg)
{
	double rad;
	rad = deg * 3.14159 / 180;
	return rad;
}
double Ball::getDirection()
{
	return direction;
}
void Ball::Move()
{
	double newX, newY;
	newX = strength * cos(degToRad(direction));
	newY = strength * sin(degToRad(direction));

	x = originalX + round(newX);
	y = originalY + round(newY);
	originalX = x;
	originalY = y;
}
