#include "Coup.h"
using namespace std;
Coup::Coup()				//Initialisation de l'objet
{
	setDirection(90);
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


void Coup::calculAccelerationY()
{
	accelerationY = (vitesseY / amplitude);
}

void Coup::calculAccelerationX()
{
	accelerationX = (-vitesseX / amplitude);
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
