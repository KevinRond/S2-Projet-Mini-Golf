#include "Coup.h"
using namespace std;
Coup::Coup()
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

void Coup::setDirection(double direction)
{
	//Lecture de la direction choisie par le joueur
	//Ajout de l'effet des MUONs sur la direction de la balle
	//Set la direction finale dans l'attribut direction
}

void Coup::setAmplitude(double module)
{
	//Set l'amplitude
}

double Coup::degToRad(double deg)
{
	double rad;
	rad = deg * 3.14159 / 180;
	return rad;
}

void Coup::calculVitesseX()
{
	vitesseX = amplitude * cos(degToRad(direction));
}

void Coup::calculVitesseY()
{
	vitesseY = -(amplitude * sin(degToRad(direction)));
}

void Coup::calculAccelerationY()
{
	accelerationY = K * (vitesseY / amplitude);
}

void Coup::calculAccelerationX()
{
	accelerationX = K * (-vitesseX / amplitude);
}

double Coup::getDirection()
{
	return direction;
}

double Coup::getAmplitude()
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
