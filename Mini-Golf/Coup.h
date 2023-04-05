#ifndef COUP_H
#define COUP_H
#include <iostream>
#include <string>
#include <cmath>
#include "Manette.h"

class Coup
{
private:
	double direction;							//Direction du coup en rad
	double amplitude;							//Amplitude de force (in milles per hours)

	double vitesseX, vitesseY;					//Vitesse en X et Y
	double accelerationX, accelerationY;		//Acceleration en X et Y

public:
	Coup();
	Coup(double dir, double amp);
	~Coup();

	//Setter
	void setDirection(int lectureJoystick);		//Direction choisie + random factor
	void setAmplitude(int lectureAmplitude);

	//Getter
	double Get_Amplitude();
	double Get_Direction();						//Lecture de la direction retour en rad

	double getVitesseX();						//Retourne vitesse en X
	double getVitesseY();						//Retourne vitesse en Y
	double getAccelerationX();					//Retourne acceleration en X
	double getAccelerationY();					//Retourne acceleration en Y
};
#endif