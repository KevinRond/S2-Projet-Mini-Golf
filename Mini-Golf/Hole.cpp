#include "Hole.h"
using namespace std;

Hole::Hole(int posX, int posY)
{
	position.x = posX;
	position.y = posY;
}

int Hole::getX()
{
	return position.x;
}

int Hole::getY()
{
	return position.y;
}

void Hole::setX(int posX)
{
	position.x = posX;
}

void Hole::setY(int posY)
{
	position.y = posY;
}
