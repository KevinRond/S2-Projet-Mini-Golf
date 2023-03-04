#ifndef MUR_H
#define MUR_H
#include <iostream>
#include <string>

class Mur
{
private:
	double* points = new double[4];	//Head_X[0]Y[1] Tail_X[2]Y[3]

public:
	Mur();												//Constructeur
	Mur(double AX, double AY, double BX, double BY);	//Constructeur avec parametre
	~Mur();												//Destructeur

	//setter
	void Set(double AX, double AY, double BX, double BY);

	//Getter
	double Get(int index);		//
	Mur* Get();		//Retourne le pointeur du Mur
		
	//Affichage
	void Display();
};

#endif