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
	double mumu;

public:
	Coup();
	Coup(double dir, double amp);
	~Coup();

	//Setter
	void setDirection(double lectureJoystick);		//Direction choisie + random factor
	void setAmplitude(double lectureAmplitude);
	void setMumu(int lectureMumu);

	//Getter
	double Get_Amplitude();
	double Get_Direction();						//Lecture de la direction retour en rad
	double Get_Mumu();

};
#endif