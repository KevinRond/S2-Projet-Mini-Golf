#include "Mur.h"
using namespace std;
Mur::Mur()
{
}

Mur::Mur(double AX, double AY, double BX, double BY)
{
	CoorXY.first.first = AX;
	CoorXY.first.second = AY;
	CoorXY.second.first = BX;
	CoorXY.second.second = BY;
}

void Mur::Set(double AX, double AY, double BX, double BY)
{
	CoorXY.first.first = AX;
	CoorXY.first.second = AY;
	CoorXY.second.first = BX;
	CoorXY.second.second = BY;
}

double Mur::GetHx()
{
	return CoorXY.first.first;
}

double Mur::GetHy()
{
	return CoorXY.first.second;
}

double Mur::GetTx()
{
	return CoorXY.second.first;
}

double Mur::GetTy()
{
	return CoorXY.second.second;
}

Mur::~Mur()
{
}

void Mur::Display()
{
	cout << "Mur Coor A: " << CoorXY.first.first << "," << CoorXY.first.second << endl;
	cout << "Mur Coor B: " << CoorXY.second.first << "," << CoorXY.second.second << endl;
}

Mur *Mur::Get()
{
	return this;
}
