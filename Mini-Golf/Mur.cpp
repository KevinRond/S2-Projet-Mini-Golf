#include "Mur.h"
using namespace std;
Mur::Mur()
{
}

Mur::Mur(double AX, double AY, double BX, double BY)
{
	points[0] = AX;
	points[1] = AY;
	points[2] = BX;
	points[3] = BY;
}

void Mur::Set(double AX, double AY, double BX, double BY)
{
	points[0] = AX;
	points[1] = AY;
	points[2] = BX;
	points[3] = BY;
}

Mur::~Mur()
{
}

/*Interraction* Mur::VerrifierColision(Ball balle)
{
	return NULL;//Interraction();
}*/

void Mur::Display()
{
	cout << "Mur Coor A: " << this->Get(0) << "," << this->Get(1) << endl;
	cout << "Mur Coor B: " << this->Get(2) << "," << this->Get(3) << endl;
}

Mur *Mur::Get()
{
	return this;
}

double Mur::Get(int x)
{
	return points[x];
}
