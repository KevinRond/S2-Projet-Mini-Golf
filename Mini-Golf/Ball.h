#ifndef BALL_H
#define BALL_H
#include <iostream>
#include <cmath>
//#include "Direction.h"

class Ball
{
private:
	int x, y;
	int originalX, originalY;
	double direction, strength; // direction in degree
public:
	Ball(int posX, int posY);
	void Reset();
	void setDirection(double new_angle);
	int getX();
	int getY();
	double getStrength();
	void setStrength(double newStrength);
	double radToDeg(double rad);
	double degToRad(double deg);
	double getDirection();
	void Move();
	friend std::ostream& operator << (std::ostream& o, Ball ball)
	{
		o << "Ball [" << ball.x << "," << ball.y << "][" << ball.direction << "]";
		return o;
	}
};

#endif
