#ifndef HOLE_H
#define HOLE_H
#include <iostream>

class Hole
{
private: 
	int x, y;
public:
	Hole(int posX, int posY);
	int getX();
	int getY();
	void setX(int posX);
	void setY(int posY);
};

#endif