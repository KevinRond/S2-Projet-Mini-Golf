#include "Coup.h"
using namespace std;
Coup::Coup()				//Initialisation de l'objet
{
	setDirection(90);
	setAmplitude();
	calculVitesseX();
	calculVitesseY();
	calculAccelerationX();
	calculAccelerationY();
}

Coup::~Coup()
{
}


void Coup::initball(double dir, double ampli)	//Lorsque les parametre d'un coup arrivent, ils update tout les attribues de la balle
{
	direction = dir;
	amplitude = ampli;
	calculVitesseX();
	calculVitesseY();
	calculAccelerationY();
	calculAccelerationX();
}

void Coup::setDirection(double dir)		//update seulement la direction
{
	direction = dir;
}

double Coup::GetDirection()
{
	return direction;
}

void Coup::calculVitesseX()
{
	vitesseX = amplitude * cos(degToRad(direction * 3.14159265 / 180));
}

void Coup::calculVitesseY()
{
	vitesseY = -(amplitude * sin(degToRad(direction * 3.14159265 / 180)));
}

void Coup::calculAccelerationY(short Kfactor)
{
	accelerationY = Kfactor * (vitesseY / amplitude);
}

void Coup::calculAccelerationX(short Kfactor)
{
	accelerationX = Kfactor * (-vitesseX / amplitude);
}

double Coup::getDirection()
{
	return direction;
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
