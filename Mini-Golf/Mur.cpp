#include "Mur.h"
using namespace std;
Mur::Mur()
{
	Hx = 0.0;
	Hy = 0.0;
	Tx = 0.0;
	Ty = 0.0;
}

Mur::Mur(double AX, double AY, double BX, double BY)
{
	Hx = AX;
	Hy = AY;
	Tx = BX;
	Ty = BY;
}

void Mur::Set(double AX, double AY, double BX, double BY)
{
	Hx = AX;
	Hy = AY;
	Tx = BX;
	Ty = BY;
}

double Mur::GetHx()
{
	return Hx;
}

double Mur::GetHy()
{
	return Hy;
}

double Mur::GetTx()
{
	return Tx;
}

double Mur::GetTy()
{
	return Ty;
}

Mur::~Mur()
{
}

void Mur::Display()
{
	cout << "Mur Coor A: " << Hx << "," << Hy << endl;
	cout << "Mur Coor B: " << Tx << "," << Ty << endl;
}

Mur *Mur::Get()
{
	return this;
}

