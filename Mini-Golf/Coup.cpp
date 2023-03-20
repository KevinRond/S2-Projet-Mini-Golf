#include "Coup.h"
using namespace std;
Coup::Coup()				//Initialisation de l'objet
{
	setDirection(90);
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

void Coup::setDirection(double dir)				//sauvegarde la direction en degre
{
	direction = dir;
}

void Coup::calculVitesseX()
{
	vitesseX = amplitude * cos(direction);
}

void Coup::calculVitesseY()
{
	vitesseY = -(amplitude * sin(direction));
}


void Coup::calculAccelerationY()
{
	accelerationY = (vitesseY / amplitude);
}

void Coup::calculAccelerationX()
{
	accelerationX = (-vitesseX / amplitude);
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
