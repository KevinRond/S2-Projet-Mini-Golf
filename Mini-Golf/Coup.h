#ifndef COUP_H
#define COUP_H
#include <iostream>
#include <string>

class Coup
{
private:
	double directionX, directionY;	//Vecteur de direction unitaire X[0],Y[1] ()
	double amplitude;				//Amplitude de force (lecture de l'accelerometre)

public:
	Coup();
	~Coup();

	//Setter
	void Direction(double DirX, double DirY);		//Direction choisie + random factor
	void Amplitude(double module);		//Lecture de l'amplitude

	//Getter
	double GetDirection();	//Lecture de la direction
	double GetAmplitude();	//Lecture de l'amplitude
};
#endif