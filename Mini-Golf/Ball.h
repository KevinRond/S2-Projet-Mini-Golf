#ifndef BALL_H
#define BALL_H
#include <iostream>
#include "Direction.h"

class Ball
{
private:
	int x, y, ball_Strength;
	int originalX, originalY;
	eDir direction;
public:
	Ball(int posX, int posY);
	void Reset();
	void changeDirection(eDir d);
	int getX();
	int getY();
	int getBallStrength();
	void setBallStrength(int newStrength);
	inline eDir getDirection();
	void Move();
	friend std::ostream& operator << (std::ostream& o, Ball ball)
	{
		o << "Ball [" << ball.x << "," << ball.y << "][" << ball.direction << "]";
		return o;
	}
};

#endif
