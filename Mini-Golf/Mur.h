#ifndef MUR_H
#define MUR_H
#include <iostream>
#include <string>

class Mur
{
private:
	double* points = new double[4];

public:
	Mur();
	Mur(double AX, double AY, double BX, double BY);
	void Set(double AX, double AY, double BX, double BY);
	~Mur();
	//Interraction *VerrifierColision(Ball balle); //Recoit l'objet ball et determine s'il y a une interaction si non retour nul
	Mur* Get();
	double Get(int x);
	void Display();
	
};

#endif