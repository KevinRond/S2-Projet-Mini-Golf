#ifndef BALL_H
#define BALL_H
#include <iostream>
#include <cmath>
#include "Coordinates.h"

class Ball
{
private:
	Coordinates position;
	int resetX, resetY;
	int initialX, initialY;
	int newX, newY;
	double direction, strength; // direction in degree
public:
	Ball(int posX, int posY);
	void Reset();
	void setDirection(double new_angle);
	int getX();
	int getY();
	void setX(int posX);
	void setY(int posY);
	int getnewX();
	int getnewY();
	void setnewX(int posX);
	void setnewY(int posY);
	double getStrength();
	void setStrength(double newStrength);
	double radToDeg(double rad);
	double degToRad(double deg);
	double calculateAdjacent();
	double calculateOpposite();
	double getDirection();
	void Move();
	friend std::ostream& operator << (std::ostream& o, Ball ball)
	{
		o << "Ball [" << ball.position.x << "," << ball.position.y << "][" << ball.direction << "]";
		return o;
	}
};

#endif
