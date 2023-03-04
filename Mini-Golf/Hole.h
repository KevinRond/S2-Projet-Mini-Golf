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
private:			//[0]=X [1]=Y
	double Tx, Ty;	//emplacement du trou
	double radius;	//radius du trou
public:
	Hole();
	Hole(double posX, double posY);
	~Hole();
	Hole* Get();

	//Setter
	void Set_xy(double posX, double posY);

	//Getter
	double Get_x();
	double Get_y();

	//Affichage
	void Display();
};

#endif