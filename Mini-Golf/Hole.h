#ifndef HOLE_H
#define HOLE_H
#include <iostream>
/*
La classe trou comporte les caracteristiques suivantes:
La location du trou (Txy)
Son radius (radius)
*/
class Hole
{
private:						//[0]=X [1]=Y
	double Tx, Ty;				//emplacement du trou
	double radius;				//radius du trou
	bool TrouReussi = false;
public:
	Hole();
	Hole(double posX, double posY);
	~Hole();
	Hole* Get();

	//Setter
	void Set_xy(double posX, double posY);
	void SetTrouReussi(bool sitrou);

	//Getter
	double Get_x()				//retourne la position X du trou
	double Get_y();				//retourne la position Y du trou
	double Get_radius();		//avoir le rayon de la balle
	bool Sitrou();				//verrifie si la balle est dans le trou

	//Affichage
	void Display();
};

#endif