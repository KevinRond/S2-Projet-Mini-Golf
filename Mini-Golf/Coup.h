#ifndef COUP_H
#define COUP_H
#include <iostream>
#include <string>
#include <cmath>
#define K 10						//Constante d'acceleration de la balle

class Coup
{
private:
	double direction;							//Direction mesure par le joystick
	double amplitude;							//Amplitude de force (lecture de l'accelerometre)
	double vitesseX, vitesseY;					//Vitesse en X et Y
	double accelerationX, accelerationY;		//Acceleration en X et Y

public:
	Coup();
	~Coup();

	//Setter
	void setDirection(double direction);		//Direction choisie + random factor
	void setAmplitude(double module);					//Lecture de l'amplitude
	double degToRad(double deg);						//Transforme angle deg en radiant
	void calculVitesseX();								//Calcul la vitesse en x utilisant la direction et l'amplitude
	void calculVitesseY();								//Calcul la vitesse en y utilisant la direction et l'amplitude
	void calculAccelerationX();							//Calcul l'acceleration de la balle en X
	void calculAccelerationY();							//Calcul l'acceleration de la balle en Y

	//Getter
	double getDirection();		//Lecture de la direction
	double getAmplitude();		//Lecture de l'amplitude
	double getVitesseX();		//Retourne vitesse en X
	double getVitesseY();		//Retourne vitesse en Y
	double getAccelerationX();	//Retourne acceleration en X
	double getAccelerationY();	//Retourne acceleration en Y
};
#endif