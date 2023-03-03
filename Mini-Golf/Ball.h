#ifndef BALL_H
#define BALL_H
#include <iostream>
#include "Direction.h"

class Ball
{
private:
	double x, y, ball_Strength;
	double originalX, originalY;
	eDir direction;
public:
	Ball();
	Ball(double posX, double posY);
	~Ball();
	
	void Reset();
	//void changeDirection(eDir d);
	void setXY(double posX, double posY);
	//Ball* get();
	double getX();
	double getY();
	double getBallStrength();
	void setBallStrength(int newStrength);
	eDir getDirection();
	void Move();
	void Display();
	//friend std::ostream& operator << (std::ostream& o, Ball ball);
	/* {
		o << "Ball [" << ball.x << "," << ball.y << "][" << ball.direction << "]";
		return o;
	}*/
};

#endif