#include "Coup.h"
using namespace std;


Coup::Coup()				//Initialisation de l'objet
{
	direction = 90;
	amplitude = 0;
}

Coup::Coup(double dir, double amp)
{
	direction = dir;
	amplitude = amp;
}

Coup::~Coup()
{
}

void Coup::setDirection(int lectureJoystick)
{
	direction = direction - lectureJoystick;
}

void Coup::setAmplitude(int lectureAmplitude)
{
	amplitude = lectureAmplitude;
}


double Coup::Get_Direction()
{
	return direction;
}
double Coup::Get_Amplitude()
{
	return amplitude;
}

double Coup::getVitesseX()
{
	return vitesseX;
}

double Coup::getVitesseY()
{
	return vitesseY;
}

double Coup::getAccelerationY()
{
	return accelerationY;
}

double Coup::getAccelerationX()
{
	return accelerationX;
}
