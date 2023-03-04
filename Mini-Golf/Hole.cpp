#include "Hole.h"
using namespace std;

Hole::Hole()
{
	Txy[0] = 0.0;
	Txy[1] = 0.0;
}

Hole::Hole(double posX, double posY)
{
	Txy[0] = posX;
	Txy[1] = posY;
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
	Txy[0] = posX;
	Txy[1] = posY;
}

void Hole::Get_xy()
{
}

void Hole::Display()
{
	cout << "Trou location : (" << Txy[0] << "," << Txy[1] << ")" << endl;
}
