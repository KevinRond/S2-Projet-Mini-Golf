#ifndef BALL_H
#define BALL_H
#include <iostream>
#include <string>

class Ball
{
private:
	double x, y, ball_Strength;
	double originalX, originalY;
	
public:
	Ball();
	Ball(double posX, double posY);
	~Ball();
	Ball* get();
	void setXY(double posX, double posY);
	void Display();
};

#endif