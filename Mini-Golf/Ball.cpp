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

double Ball::Get_Direction()
{
    return direction;
}

double Ball::Get_rayon()
{
    return rayon;
}

double Ball::Get_Amplitude()
{
    return amplitude;
}

double Ball::Get_K()
{
    return K;
}

void Ball::Set_Direction(double newdirection)
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

void Ball::Set_Amplitude(double amp)
{
    amplitude = amp;
    Ax = cos(direction) * amp;
    Ay = sin(direction) * amp;

}

void Ball::Set_K(double k)
{
    K = k;
}

std::pair<int, int> Ball::QuelCadrant()
{
    int x, y;
    if (direction < 3.14159265358979323846 / 2 || direction > 3.14159265358979323846 * 1.5)			//Verifie si l'interaction occur dans les cadrants de droite
    {
        x= 1;
    }
    else if (direction > 3.14159265358979323846 / 2 && direction < 3.14159265358979323846 * 1.5)		//Verifie si l'interaction occur dans les cadrants de gauche
    {
        x= -1;
    }
    if (direction > 0 && direction < 3.14159265358979323846)			//Verifie si l'interaction occur dans les cadrants du haut
    {
        y= 1;
    }
    else if (direction > 3.14159265358979323846)		//Verifie si l'interaction occur dans les cadrants du bas
    {
        y= -1;
    }
    pair<double, double> Cadrant = make_pair(x, y);
    return Cadrant;
}