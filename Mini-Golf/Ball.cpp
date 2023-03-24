#include "Ball.h"
#include <cmath>

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
    rayon = 0.5; //avoir le rayon de la balle pour le trou
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
    
    cout << "Balle location : (" << Ox << "," << Oy << ")" << endl;
}

double Ball::Get_direction()
{
    return direction;
}

double Ball::Get_rayon()
{
    return rayon;
}

void Ball::Set_direction(double newdirection)
{
    direction = (newdirection * 3.14159265358979323846 / 180);
}

void Ball::Set_Vx(double posX)
{
    Vx = posX;
}

void Ball::Set_Vy(double posY)
{
    Vy = posY;
}
