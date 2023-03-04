#include "Ball.h"
using namespace std;
Ball::Ball()
{
    x = 0.0;
    y = 0.0;
    Ox = 0.0;
    Oy = 0.0;
    Vx = 0.0;
    Vy = 0.0;
    Ax = 0.0;
    Ay = 0.0;
}

Ball::~Ball(){}

Ball* Ball::Get()
{
    return this;
}

Ball::Ball(double posX, double posY)
{
    x = posX;
    y = posY;
    Ox = posX;
    Oy = posY;
    Vx = 0.0;
    Vy = 0.0;
    Ax = 0.0;
    Ay = 0.0;
}
void Ball::Set_xy(double posX, double posY)
{
    x = posX;
    y = posY;
}

void Ball::Set_Oxy(double posX, double posY)
{
    Ox = posX;
    Oy = posY;
}

void Ball::Set_Vxy(double posX, double posY)
{
    Vx = posX;
    Vy = posY;
}

void Ball::Set_Axy(double posX, double posY)
{
    Ax = posX;
    Ay = posY;
}

double Ball::Get_x()
{
    return x;
}
double Ball::Get_y()
{
    return y;
}
double Ball::Get_Ox()
{
    return Ox;
}
double Ball::Get_Oy()
{
    return Oy;
}
double Ball::Get_Vx()
{

    return  Vx;
}
double Ball::Get_Vy()
{

    return  Vy;
}
double Ball::Get_Ax()
{
    return Ax;
}
double Ball::Get_Ay()
{
    return Ay;
}
void Ball::Display()
{
    
    cout << "Balle location : (" << x << "," << y << ")" << endl;
}