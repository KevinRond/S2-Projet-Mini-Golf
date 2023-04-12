
#include "Interraction.h"
#include<cmath>
/*
La classe interaction caracterisera une interaction entre 2 objets
Ex: Ball avec Mur,Trou,Sable,glace
On est dans un monde de mini-put, on peux faire s'quon veux...
*/

Interraction::Interraction()
{
	x = 0.0;
	y = 0.0;
	module = 0.0;
	Degre = 0.0;
}

Interraction::~Interraction()
{
}

Parcours Interraction::BalleMur(Ball* balle, Mur* mur, std::pair<double, double> inters)
{
	Parcours petitParcour;
	int i = 1;
	double distancetoHit, distanceItCanTravel, distanceItTraveled;
	double Ox, Oy, Vxy, x, y, K, T, D, Dir;												//Definition des coor de balle et d'interaction
	Ox = balle->Get_Ox();
	Oy = balle->Get_Oy();
	Vxy = balle->Get_Amplitude();												//converti la vitesse de balle de mph to m/s
	Dir = balle->Get_Direction();
	K = balle->Get_K();
	distancetoHit = (sqrt(pow(inters.first - Ox, 2) + pow(inters.second - Oy, 2)));	//distance entre la balle et sa prochaine interraction
	distanceItCanTravel = ((pow(Vxy, 2)) / (19.62 * K));
	T = Vxy / (K * 9.81);
	D = (Vxy / 2) * T;
	distanceItTraveled = 0;

	while (distanceItTraveled < distancetoHit && Vxy > 0.01)
	{
		D = (Vxy / 2) * T * i * 0.01;
		distanceItTraveled += D;

		Vxy = Vxy - (K * 9.81 * T * i * 0.01);
		x = (cos(Dir) * distanceItTraveled) + Ox;
		y = (sin(Dir) * distanceItTraveled) + Oy;
		petitParcour.addCoor(x, y);
		i++;
	}
	if (distanceItTraveled >= distancetoHit)
	{
		std::cout << "touche mur" << std::endl;
		petitParcour.removelast();
		x = (cos(Dir) * distancetoHit * 0.99) + Ox;
		y = (sin(Dir) * distancetoHit * 0.99) + Oy;
		petitParcour.addCoor(x, y);
		balle->Set_Amplitude(Vxy);
		angleReflexion(balle, mur);								//change l'angle de de la balle lorsqu'elle reflette le mur			
		balle->Set_Oxy(x, y);
	}
	else if (Vxy <= 0.01)
	{
		balle->Set_Amplitude(0);
		x = (cos(Dir) * distanceItTraveled) + Ox;
		y = (sin(Dir) * distanceItTraveled) + Oy;
		balle->Set_Oxy(x, y);
		std::cout << "Balle en position (" << x << "," << y << ")." << std::endl;
	}
	return petitParcour;
}

Parcours Interraction::BalleTrou(Ball* balle, Hole* trou, std::pair<double, double> inters)
{
	Parcours petitParcour;
	int i = 1;
	double distancetoHit, distanceItCanTravel, distanceItTraveled;
	double Ox, Oy, Vxy, x, y, K, T, D, Dir;													//Definition des coor de balle et d'interaction
	Ox = balle->Get_Ox();
	Oy = balle->Get_Oy();
	Vxy = balle->Get_Amplitude();													//converti la vitesse de balle de mph to m/s
	Dir = balle->Get_Direction();
	K = balle->Get_K();
	distancetoHit = (sqrt(pow(inters.first - Ox, 2) + pow(inters.second - Oy, 2)));	//distance entre la balle et sa prochaine interraction
	distanceItCanTravel = ((pow(Vxy, 2)) / (19.62 * K));
	T = Vxy / (K * 9.81);
	D = (Vxy / 2) * T;
	distanceItTraveled = 0;

	while (distanceItTraveled < distancetoHit && Vxy > 0.01)
	{
		D = (Vxy / 2) * T * i * 0.01;
		distanceItTraveled += D;
		Vxy = Vxy - (K * 9.81 * T * i * 0.01);
		x = (cos(Dir) * distanceItTraveled) + Ox;
		y = (sin(Dir) * distanceItTraveled) + Oy;
		petitParcour.addCoor(x, y);
		i++;
	}

	if (distanceItTraveled >= distancetoHit)
	{
		if (Vxy < 3) {
			trou->SetTrouReussi(1);
		}
		else {
			balle->Set_Amplitude(Vxy);
			angleReflexion(balle, trou, inters);				//change l'angle de de la balle lorsqu'elle passe trop vite sur le trou		
			balle->Set_Oxy(x, y);
		}
	}
	else if (Vxy <= 0.01)
	{
		balle->Set_Amplitude(0);
		x = (cos(Dir) * distanceItTraveled) + Ox;
		y = (sin(Dir) * distanceItTraveled) + Oy;
		balle->Set_Oxy(x, y);
		std::cout << "Balle en position (" << x << "," << y << ")." << std::endl;
	}

	return petitParcour;
}

double Interraction::InterractionX()
{
	return 0.0;
}

double Interraction::InterractionY()
{
	return 0.0;
}

double Interraction::InterractionAngle()
{
	return 0.0;
}

double Interraction::InterractionFac()
{
	return 0.0;
}

double Interraction::Module()
{
	return 0.0;
}

void Interraction::angleReflexion(Ball* balle, Hole* trou, std::pair<double, double> inters)
{
	std::pair<double, double> cadrant;
	double val1 = atan2(trou->Get_x() - balle->Get_Ox(), trou->Get_y() - balle->Get_Oy());
	double val2 = atan2(inters.first - balle->Get_Ox(), inters.second - balle->Get_Oy());

	double distance = sqrt(pow((inters.first - trou->Get_x()), 2) + pow((inters.second - trou->Get_y()), 2));
	double change = (distance * PI);
	if (val1 > val2)
	{
		change = -change;
	}
	std::cout << "transfert de velocite de " << change / PI * 180 << " Deg." << std::endl;
	balle->Set_Direction(balle->Get_Direction() + change);
}

void Interraction::angleReflexion(Ball* balle, Mur* mur)							//trouver l'angle de reflexion de la balle
{
	double Vxy = balle->Get_Amplitude();
	double oldangle = balle->Get_Direction();
	double oldangle1 = balle->Get_Direction();
	double angleIncident;
	double angleMur;
	double angleReflechis = 0;
	double facteurVelocity = 0;
	if (mur->GetHx() == mur->GetTx())
	{
		if (oldangle1 >= PI)
		{
			oldangle1 = oldangle1 - PI;
		}
		if (oldangle1 > PI / 2)
		{
			oldangle1 = PI - oldangle1;
		}
		angleIncident = PI / 2 - oldangle1;

		angleReflechis = oldangle - PI;
		if (angleReflechis < 0)
		{
			angleReflechis = -angleReflechis;
		}
		else
		{
			angleReflechis = 2 * PI - angleReflechis;
		}
		balle->Set_Direction(angleReflechis);


	}
	else if (mur->GetHy() == mur->GetTy())
	{
		angleReflechis = 2 * PI - oldangle;
		balle->Set_Direction(angleReflechis);
		if (oldangle1 >= PI)
		{
			oldangle1 = oldangle1 - PI;
		}
		if (oldangle1 > PI / 2)
		{
			oldangle1 = PI - oldangle1;
		}
		angleIncident = oldangle1;
	}
	else
	{
		angleMur = atan2(mur->GetTy() - mur->GetHy(), mur->GetTx() - mur->GetHx());
		std::cout << "ANGLE MUR: " << angleMur * 180 / PI << std::endl;
		angleIncident = fmod(oldangle - angleMur + 2 * PI, 2 * PI);
		angleReflechis = fmod(angleMur - angleIncident + 2 * PI, 2 * PI);
		balle->Set_Direction(angleReflechis);
		//cout << "ANGLE INCIDENT: "<< angleIncident*180/PI << endl;
		std::cout << "ANGLE REFLECHI: " << angleReflechis * 180 / PI << std::endl;
		while (angleReflechis < 0)
		{
			std::cout << "changement angle reflechis: " << angleReflechis * 180 / PI << std::endl;
			angleReflechis = angleReflechis + PI;
		}
		if (angleIncident >= PI)
		{
			angleIncident = angleIncident - PI;
		}
		if (angleIncident > PI / 2)
		{
			std::cout << "changement" << std::endl;
			angleIncident = PI - angleIncident;
		}
	}
	facteurVelocity = (100 - (angleIncident * 180) / (8 * PI)) / 100;

	balle->Set_Amplitude(Vxy * facteurVelocity);
	std::cout << "angle INCIDEENT: " << angleIncident * 180 / PI << std::endl;
	std::cout << "FACteur velocity: " << facteurVelocity << std::endl;
}