#include "Coup.h"
using namespace std;
Coup::Coup()
{
	Direction();
	Amplitude();
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

void Coup::GetDirection()
{
	//Retournera un pointeur vers l'array de direction
}

double Coup::GetAmplitude()
{
	return amplitude;
}