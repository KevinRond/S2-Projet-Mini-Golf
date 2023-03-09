#include "Hole.h"
using namespace std;

Hole::Hole()
{
	Tx = 0.0;
	Ty = 0.0;
}

Hole::Hole(double posX, double posY)
{
	Tx = posX;
	Ty = posY;
}
Hole::~Hole()
{
}

Hole* Hole::Get()
{
	return this;
}

void Hole::Set_xy(double posX, double posY)
{
	Tx = posX;
	Ty = posY;
}

double Hole::Get_x()
{
	return Tx;
}
double Hole::Get_y()
{
	return Ty;
}
void Hole::Display()
{
	cout << "Trou location : (" << Tx << "," << Ty << ")" << endl;
}
