#include "Coup.h"
using namespace std;


Coup::Coup(double dir, double ampli)				//Initialisation de l'objet
{
	direction = dir;
	amplitude = ampli;
	calculVitesseX();
	calculVitesseY();
	calculAccelerationY();
	calculAccelerationX();
}

Coup::~Coup()
{
}


void Coup::initcoup(double dir, double ampli)	//Lorsque les parametre d'un coup arrivent, ils update tout les attribues de la balle
{
	direction = dir;
	amplitude = ampli;
	calculVitesseX();
	calculVitesseY();
	calculAccelerationY();
	calculAccelerationX();
}

void Coup::setDirection(double dir)				//sauvegarde la direction en degre
{
	direction = dir;
}

void Coup::setAmplitude(double ampli)
{
	amplitude = ampli;
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
