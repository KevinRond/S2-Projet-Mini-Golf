#include "Ball.h"
using namespace std;
Ball::Ball()
{
    originalX = 0;
    originalY = 0;
    x = 0;
    y = 0;
    ball_Strength = 0;

}
Ball::~Ball(){}
Ball* Ball::get()
{
    return this;
}
Ball::Ball(double posX, double posY)
{
	originalX = posX;
	originalY = posY;
	x = posX;
	y = posY;
    ball_Strength = 0;

}


void Ball::setXY(double posX, double posY)
{
    originalX = posX;
    originalY = posY;
    x = posX;
    y = posY;
    ball_Strength = 0;

}

void Ball::Display()
{
    
    cout << "Balle location : (" << x << "," << y << ")" << endl;
}