#include "Coup.h"
using namespace std;


Coup::Coup()				//Initialisation de l'objet
{
	direction = 90;
	amplitude = 0;
	calculVitesseX();
	calculVitesseY();
	calculAccelerationY();
	calculAccelerationX();
}

Coup::~Coup()
{
}


void Coup::initcoup()	//Lorsque les parametre d'un coup arrivent, ils update tout les attribues de la balle
{
	calculVitesseX();
	calculVitesseY();
	calculAccelerationY();
	calculAccelerationX();
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

void Coup::calculVitesseX()
{
	vitesseX = amplitude * cos(direction * 3.14159265 / 180);
}

void Coup::calculVitesseY()
{
	vitesseY = (amplitude * sin(direction * 3.14159265 / 180));
}


void Coup::calculAccelerationY()
{
	accelerationY = -(vitesseY / amplitude);
}

void Coup::calculAccelerationX()
{
	accelerationX = -(vitesseX / amplitude);
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
