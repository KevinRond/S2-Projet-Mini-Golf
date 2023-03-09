#include "Coup.h"
using namespace std;
Coup::Coup()
{
	Direction(0,0);
	Amplitude(0);
}

Coup::~Coup()
{
}

void Coup::Direction(double DirX, double DirY)
{
	//Lecture de la direction choisie par le joueur
	//Ajout de l'effet des MUONs sur la direction de la balle
	//Set la direction finale dans l'attribut direction
}

void Coup::Amplitude(double module)
{
	//Set l'amplitude
}

double Coup::GetDirection()
{
	//Retournera un pointeur vers l'array de direction
	return 0.0;
}

double Coup::GetAmplitude()
{
	return 0.0;
}