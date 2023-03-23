#ifndef COUP_H
#define COUP_H
#include <iostream>
#include <string>
#include <cmath>
#include "Manette.h"

class Coup
{
private:
	int direction;							//Direction du coup en Rad
	int amplitude;							//Amplitude de force (lecture de l'accelerometre)
	double vitesseX, vitesseY;					//Vitesse en X et Y
	double accelerationX, accelerationY;		//Acceleration en X et Y

public:
	Coup();
	~Coup();

	//Setter
	void initcoup();	//Initialisation des parametres de ball depuis un coup
	void setDirection(int lectureJoystick);				//Direction choisie + random factor
	void setAmplitude(int lectureAmplitude);

	//updater
	
	void calculVitesseX();						//Calcul la vitesse en x utilisant la direction et l'amplitude
	void calculVitesseY();						//Calcul la vitesse en y utilisant la direction et l'amplitude
	void calculAccelerationX();					//Calcul l'acceleration de la balle en X
	void calculAccelerationY();					//Calcul l'acceleration de la balle en Y

	//Getter
	int getAmplitude();
	int getDirection();						//Lecture de la direction retour en rad
	double getVitesseX();						//Retourne vitesse en X
	double getVitesseY();						//Retourne vitesse en Y
	double getAccelerationX();					//Retourne acceleration en X
	double getAccelerationY();					//Retourne acceleration en Y
};
#endif