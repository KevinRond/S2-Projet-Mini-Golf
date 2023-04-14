#include "Hole.h"
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

void Hole::SetTrouReussi(bool sitrou)
{
	TrouReussi = sitrou;
}

double Hole::Get_x()
{
	return Tx;
}
double Hole::Get_y()
{
	return Ty;
}
double Hole::Get_radius()
{
	return radius;
}
bool Hole::Sitrou()
{
	return TrouReussi;
}
void Hole::Display()
{
	std::cout << "Trou location : (" << Tx << "," << Ty << ")" << std::endl;
}
