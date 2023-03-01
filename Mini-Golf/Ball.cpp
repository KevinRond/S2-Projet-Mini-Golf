#include "Ball.h"

Ball::Ball(int posX, int posY)
{
	initialX = posX;
	initialY = posY;
	resetX = posX;
	resetY = posY;
	position.x = posX;
	position.y = posY;
	newX = 0;
	newY = 0;
    strength = 0;
	direction = 90;
}
void Ball::Reset()
{
	position.x = resetX;
	position.y = resetY;
	direction = 90;
}
void Ball::setDirection(double new_angle)
{
	direction = new_angle;
}
int Ball::getX()
{
	return position.x;
}
int Ball::getY()
{
	return position.y;
}
void Ball::setX(int posX)
{
	position.x = posX;
}
void Ball::setY(int posY)
{
	position.y = posY;
}
int Ball::getnewX()
{
	return newX;
}
int Ball::getnewY()
{
	return newY;
}
void Ball::setnewX(int posX)
{
	newX = posX;
}
void Ball::setnewY(int posY)
{
	newY = posY;
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
double Ball::calculateAdjacent()
{
	return strength * cos(degToRad(direction));
}
double Ball::calculateOpposite()
{
	return -(strength * sin(degToRad(direction)));
}
double Ball::getDirection()
{
	return direction;
}
void Ball::Move()
{	// Valeurs x, y du vecteur de frappe selon sa force et son angle
	double hitX, hitY; 
	hitX = calculateAdjacent();
	hitY = calculateOpposite();

	// Valeurs x, y futur de la balle selon sa position initiale et le coup frappe
	newX = initialX + round(hitX);
	newY = initialY + round(hitY);

	//while (position.x != newX || position.y != newY)
	{
		if (position.x < newX)
		{
			position.x++;
		}
		else if (position.x > newX)
		{
			position.x--;
		}
		if (position.y < newY)
		{
			position.y++;
		}
		else if (position.y > newY)
		{
			position.y--;
		}
	}
	/*La fonction logic call move seulement une fois, donc meme si elle change */

	initialX = position.x;
	initialY = position.y;
}
