#ifndef MUR_H
#define MUR_H
#include <iostream>
#include <string>
#include <utility>

class Mur
{
private:

	std::pair<std::pair<double, double>, std::pair<double, double>> CoorXY;

public:
	Mur();												
	Mur(double AX, double AY, double BX, double BY);
	~Mur();												

	//setter
	void Set(double AX, double AY, double BX, double BY);

	//Getter
	double GetHx();
	double GetHy();
	double GetTx();
	double GetTy();
	Mur* Get();		//Retourne le pointeur du Mur
		
	//Affichage
	void Display();
};

#endif