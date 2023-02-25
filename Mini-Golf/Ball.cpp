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
{	// Valeurs x, y du vecteur de frappe selon sa force et son angle
	double hitX, hitY; 
	hitX = strength * cos(degToRad(direction));
	hitY = -(strength * sin(degToRad(direction)));

	// Valeurs x, y futur de la balle selon sa position initiale et le coup frappe
	double newX = originalX + round(hitX);
	double newY = originalY + round(hitY);

	while (x != newX || y != newY)
	{
		if (x < newX)
		{
			x++;
		}
		else if (x > newX)
		{
			x--;
		}
		if (y < newY)
		{
			y++;
		}
		else if (y > newY)
		{
			y--;
		}
	}

	originalX = x;
	originalY = y;
}
