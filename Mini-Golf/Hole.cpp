#include "Hole.h"
using namespace std;

Hole::Hole(int posX, int posY)
{
	x = posX;
	y = posY;
}

int Hole::getX()
{
	return x;
}

int Hole::getY()
{
	return y;
}

void Hole::setX(int posX)
{
	x = posX;
}

void Hole::setY(int posY)
{
	y = posY;
}
