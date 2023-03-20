#ifndef COUP_H
#define COUP_H
#include <iostream>
#include <string>
#include <cmath>

class Coup
{
private:
	double direction;							//Direction du coup en Rad
	double amplitude;							//Amplitude de force (lecture de l'accelerometre)
	double vitesseX, vitesseY;					//Vitesse en X et Y
	double accelerationX, accelerationY;		//Acceleration en X et Y

public:
	Coup();
	~Coup();

	//Setter
	void initball(double dir, double ampli);	//Initialisation des parametres de ball depuis un coup
	void setDirection(double dir);				//Direction choisie + random factor
	void setAmplitude(double ampli);

	//updater
	
	void calculVitesseX();						//Calcul la vitesse en x utilisant la direction et l'amplitude
	void calculVitesseY();						//Calcul la vitesse en y utilisant la direction et l'amplitude
	void calculAccelerationX();	//Calcul l'acceleration de la balle en X
	void calculAccelerationY();	//Calcul l'acceleration de la balle en Y

	//Getter
	double getDirection();						//Lecture de la direction retour en rad
	double getVitesseX();						//Retourne vitesse en X
	double getVitesseY();						//Retourne vitesse en Y
	double getAccelerationX();					//Retourne acceleration en X
	double getAccelerationY();					//Retourne acceleration en Y
};
#endif