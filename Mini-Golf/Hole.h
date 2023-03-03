#ifndef HOLE_H
#define HOLE_H
#include <iostream>

class Hole
{
private: 
	int x, y;
public:
	Hole();
	Hole(int posX, int posY);
	~Hole();
	int getX();
	int getY();
	void setXY(double posX, double posY);
	Hole* get();
	void Display();
};

#endif