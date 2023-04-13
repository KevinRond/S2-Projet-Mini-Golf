#include "Coup.h"

Coup::Coup()				//Initialisation de l'objet
{
	direction = 45;
	amplitude = 0;
	mumu = 0;
}

Coup::Coup(double dir, double amp)
{
	direction = dir;
	amplitude = amp;
	mumu = 0;
}

Coup::~Coup()
{
}

void Coup::setDirection(double lectureJoystick)
{
	direction = direction - 2*lectureJoystick;
}

void Coup::setAmplitude(double lectureAmplitude)
{
	amplitude = lectureAmplitude;
}


double Coup::Get_Direction()
{
	return -direction;
}
double Coup::Get_Amplitude()
{
	return amplitude * 0.44704;
}


void Coup::setMumu(int lectureMumu)
{
	mumu = lectureMumu;
}

double Coup::Get_Mumu()
{
	return mumu;
}
