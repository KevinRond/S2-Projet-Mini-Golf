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

void Hole::printHole()
{
	for (int i = x; i <= x + 3; i++)
	{
		for (int j = y; j <= y + 3; j++)
		{
			if (j == y || j == y + 3)
			{
				if (i == x + 1 || i == x + 2)
				{
					cout << "#";
				}
				else
				{
					cout << " ";
				}
			}
			else
			{
				if (i == x || i == x + 3)
				{
					cout << "#";
				}
				else
				{
					cout << " ";
				}
			}
		}
		cout << endl;
	}
}
