#ifndef COUP_H
#define COUP_H
#include <iostream>
#include <string>
#include <cmath>
#define K 10

class Coup
{
private:
	double direction;	
	double amplitude;				//Amplitude de force (lecture de l'accelerometre)
	double vitesseX, vitesseY;
	double acceleration;

public:
	Coup();
	~Coup();

	//Setter
	void setDirection(double DirX, double DirY);		//Direction choisie + random factor
	void setAmplitude(double module);		//Lecture de l'amplitude
	double degToRad(double deg);
	void calculVitesseX();
	void calculVitesseY();
	void calculAcceleration();

	//Getter
	double getDirection();	//Lecture de la direction
	double getAmplitude();	//Lecture de l'amplitude
};
#endif