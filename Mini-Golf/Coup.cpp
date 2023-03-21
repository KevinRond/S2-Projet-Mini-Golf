#include "Coup.h"
using namespace std;
Coup::Coup()				//Initialisation de l'objet
{
	direction = 90;
	//setAmplitude();		//JSP QUELLE AMPLITUDE METTRE LOL
	calculVitesseX();
	calculVitesseY();
	//calculAccelerationX();    //ERREUR AVEC LES FONCTIONS EN COMMENTTAIRE
	//calculAccelerationY();
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
	calculAccelerationY(ampli);
	calculAccelerationX(ampli);
}

void Coup::setDirection(double dir)		//update seulement la direction
{
	direction = dir;
}

void Coup::setAmplitude(double ampli)
{
	ampli = amplitude;
}

double Coup::getDirection()
{
	return direction;
}

void Coup::calculVitesseX()
{
	vitesseX = amplitude * cos(direction * 3.14159265 / 180);
}

void Coup::calculVitesseY()
{
	vitesseY = -(amplitude * sin(direction * 3.14159265 / 180));
}

void Coup::calculAccelerationY(short Kfactor)
{
	accelerationY = Kfactor * (vitesseY / amplitude);
}

void Coup::calculAccelerationX(short Kfactor)
{
	accelerationX = Kfactor * (-vitesseX / amplitude);
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
