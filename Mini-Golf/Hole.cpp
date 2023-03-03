#include "Hole.h"
using namespace std;

Hole::Hole()
{
	x = 0.0;
	y = 0.0;
}

Hole::Hole(int posX, int posY)
{
	x = posX;
	y = posY;
}

Hole::~Hole()
{
}

int Hole::getX()
{
	return x;
}

int Hole::getY()
{
	return y;
}

void Hole::setXY(double posX, double posY)
{
	x = posX;
	y = posY;
}

Hole* Hole::get()
{
	return this;
}

void Hole::Display()
{
	cout << "Trou location : (" << x << "," << y << ")" << endl;
}
