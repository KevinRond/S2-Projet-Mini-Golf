#include "Parcours.h"

using namespace std;


Parcours::Parcours()
{
}

Parcours::~Parcours()
{
}

void Parcours::addCoor(double x, double y)
{
	pair<double, double> coor = make_pair(x, y);
	CoorXY.push_back(coor);
}

void Parcours::operator+=(Parcours ParscoursAajouter)
{
	std::vector<std::pair<double, double>> coorToAdd = ParscoursAajouter.GetCoorXY();
	for (auto coor : coorToAdd) {
		CoorXY.push_back(coor);
	}
}

int Parcours::GetSize()
{
	return CoorXY.size();
}



void Parcours::removelast()
{
	CoorXY.pop_back();
}

void Parcours::Display()
{

}

