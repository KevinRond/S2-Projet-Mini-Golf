#include "Ball.h"
#include <cmath>
#define PI 3.14159265358979323846
Ball::Ball()
{
    Ox = 0.0;
    Oy = 0.0;
    rayon = 0.5;
    K = 0.1;
}

Ball::~Ball(){}

Ball* Ball::Get()
{
    return this;
}

Ball::Ball(double posX, double posY)
{
    Ox = posX;
    Oy = posY;
}

void Ball::Set_Oxy(double posX, double posY)
{
    Ox = posX;
    Oy = posY;
}

double Ball::Get_Ox()
{
    return Ox;
}
double Ball::Get_Oy()
{
    return Oy;
}
void Ball::Display()
{  
    std::cout << "Balle location : (" << Ox << "," << Oy << ")" << std::endl;
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
    if (newdirection < 0) {
        newdirection = ((2 * PI) + newdirection);
    }
    direction = (newdirection);
}

void Ball::Set_Amplitude(double amp)
{
    amplitude = amp;
}

void Ball::Set_K(double k)
{
    K = k;
}

std::pair<int, int> Ball::QuelCadrant()
{
    int x, y;
    if (direction <= PI / 2 || direction >= PI * 1.5)		//Verifie si l'interaction occur dans les cadrants de droite
    {
        x= 1;
    }
    else if (direction > PI / 2 && direction < PI * 1.5)	//Verifie si l'interaction occur dans les cadrants de gauche
    {
        x= -1;
    }
    if (direction >= 0 && direction <= PI)			        //Verifie si l'interaction occur dans les cadrants du haut
    {
        y= 1;
    }
    else if (direction > PI)		                        //Verifie si l'interaction occur dans les cadrants du bas
    {
        y= -1;
    }
    std::pair<double, double> Cadrant = std::make_pair(x, y);
    return Cadrant;
}