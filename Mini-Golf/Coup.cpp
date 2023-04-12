#include "Coup.h"

Coup::Coup()				//Initialisation de l'objet
{
	direction = 45;
	amplitude = 0;
}

Coup::Coup(double dir, double amp)
{
	direction = dir;
	amplitude = amp;
}

Coup::~Coup()
{
}

void Coup::setDirection(int lectureJoystick)
{
	direction = direction - lectureJoystick;
}

void Coup::setAmplitude(int lectureAmplitude)
{
	amplitude = lectureAmplitude;
}


double Coup::Get_Direction()
{
	return direction;
}
double Coup::Get_Amplitude()
{
	return amplitude * 0.44704;
}

