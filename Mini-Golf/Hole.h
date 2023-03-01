#ifndef HOLE_H
#define HOLE_H
#include <iostream>
#include "Coordinates.h"

class Hole
{
private: 
	Coordinates position;
public:
	Hole(int posX, int posY);
	int getX();
	int getY();
	void setX(int posX);
	void setY(int posY);
};

#endif