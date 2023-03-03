#include "Mur.h"

Mur::Mur(double AX, double AY, double BX, double BY)
{
	pointsA[0] = AX;
	pointsA[1] = AY;
	pointsB[0] = BX;
	pointsB[1] = BY;
}

Mur::~Mur()
{
}

Interraction Mur::VerrifierColision(Ball ball)
{
	return Interraction();
}

void Mur::Display()
{
	cout << "Mur Coor A: " << to_string(pointsA[0]) << "," << to_string(pointsA[1]) << endl;
	cout << "Mur Coor B: " << to_string(pointsB[0]) << "," << to_string(pointsB[1]) << endl;

}

Mur *Mur::Get()
{
	return this;
}
