#include "Interraction.h"
#include<cmath>
using namespace std;
/*
La classe interaction caracterisera une interaction entre 2 objets
Ex: Ball avec Mur,Trou,Sable,glace
On est dans un monde de mini-put, on peux faire s'quon veux...
*/

Interraction::Interraction()
{
	x = 0.0;
	y = 0.0;
}

Interraction::~Interraction()
{
}


double Interraction::InterractionX()
{
	return 0.0;
}

double Interraction::InterractionY()
{
	return 0.0;
}

double Interraction::InterractionAngle()
{
	return 0.0;
}

double Interraction::InterractionFac()
{
	return 0.0;
}

double Interraction::Module()
{
	return 0.0;
}


void Interraction::InteractionMur(Ball balle, Mur mur)
{
	//eqtaion de la trajectoire de la balle y = mx + b
	double m = tan(balle.Get_direction());
	double b = balle.Get_Oy() - m * balle.Get_Ox();

	//equation du mur 

}