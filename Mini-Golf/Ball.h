#ifndef BALL_H
#define BALL_H
#include <iostream>
#include "Direction.h"

class Ball
{
private:
	int x, y;
	int originalX, originalY;
	eDir direction;
public:
	Ball(int posX, int posY);
	void Reset();
	void changeDirection(eDir d);
	inline int getX();
	inline int getY();
	inline eDir getDirection();
	void Move(int force);
	friend std::ostream& operator << (std::ostream& o, Ball ball)
	{
		o << "Ball [" << ball.x << "," << ball.y << "][" << ball.direction << "]";
		return o;
	}
};

#endif
