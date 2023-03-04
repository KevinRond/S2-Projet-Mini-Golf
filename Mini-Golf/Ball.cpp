#include "Ball.h"
using namespace std;
Ball::Ball()
{
    xy[0] = 0;
    xy[1] = 0;
    Oxy[0] = 0;
    Oxy[1] = 0;
    Vxy[0] = 0;
    Vxy[1] = 0;
    Axy[0] = 0;
    Axy[1] = 0;
}

Ball::~Ball(){}

Ball* Ball::Get()
{
    return this;
}

Ball::Ball(double posX, double posY)
{
    xy[0] = posX;
    xy[1] = posY;
    Oxy[0] = posX;
    Oxy[1] = posY;
    Vxy[0] = 0;
    Vxy[1] = 0;
    Axy[0] = 0;
    Axy[1] = 0;
}

void Ball::Set_xy(double posX, double posY)
{
    xy[0] = posX;
    xy[1] = posY;
}

void Ball::Set_Oxy(double posX, double posY)
{
    Oxy[0] = posX;
    Oxy[1] = posY;
}

void Ball::Set_Vxy(double posX, double posY)
{
    Vxy[0] = posX;
    Vxy[1] = posY;
}

void Ball::Set_Axy(double posX, double posY)
{
    Axy[0] = posX;
    Axy[1] = posY;
}

double Ball::Get_xy()
{
    return 0.0;
}

double Ball::Get_Oxy()
{
    return 0.0;
}

double Ball::Get_Vxy()
{

    return  0.0;
}

double Ball::Get_Axy()
{
    return 0.0;
}

void Ball::Display()
{
    
    cout << "Balle location : (" << xy[0] << "," << xy[1] << ")" << endl;
}