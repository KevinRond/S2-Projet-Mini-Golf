#include <iostream>
#include <string>
#include "Parcours.h"
using namespace std;


Parcours::Parcours()
{
	tableau01 = new double* [2];
	tableau01[0] = new double[16];
	tableau01[1] = new double[16];
}

Parcours::~Parcours()
{
}

void Parcours::addCoor(double x, double y)
{
	if (size + 1 > capacity)							//si capacite est atteinte, doubler l'espace
	{
		capacity = capacity * 2;


		double** tableau02 = new double*[2];
		tableau02[0] = new double[capacity];
		tableau02[1] = new double[capacity];

		for (int i = 0; i < size; i++)					//copie des donnees existantes
		{
			tableau02[0][i] = tableau01[0][i];			//deplace les donnes X
			tableau02[1][i] = tableau01[1][i];			//deplace les donnes Y
		}
		delete[] tableau01[0];							//desaloue la memoire
		delete[] tableau01[1];
		delete[] tableau01;
		tableau01 = tableau02;							//reassingne sur le tableau d'origine


	}
	tableau01[0][size] = x;								//ajoute la nouvelle coordonnee
	tableau01[1][size] = y;
	size++;
}

void Parcours::operator+=(Parcours ParscoursAajouter)
{
	for (int i = 0; i < ParscoursAajouter.GetSize(); i++)
	{
		double x = ParscoursAajouter.Getx(i);
		double y = ParscoursAajouter.Gety(i);
		this->addCoor(x,y);
	}
}

int Parcours::GetSize()
{
	return size;
}

double Parcours::Getx(int index)
{
	return tableau01[0][index];
}

double Parcours::Gety(int index)
{
	return tableau01[1][index];
}

void Parcours::Display()
{
	for (int i = 0; i < size; i++)
	{
		cout << "Coor #" << i + 1 << ": " << to_string(tableau01[0][i]) << " " << to_string(tableau01[1][i]) << endl;
	}
}

