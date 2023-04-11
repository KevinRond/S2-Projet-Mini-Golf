
#include "Interraction.h"
#include<cmath>
using namespace std;
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
	Vxy = balle->Get_Amplitude() * 0.44704;												//converti la vitesse de balle de mph to m/s
	Dir = balle->Get_Direction();
	K = balle->Get_K();
	distancetoHit = (sqrt(pow(inters.first - Ox, 2) + pow(inters.second - Oy, 2))) / 10;	//distance entre la balle et sa prochaine interraction
	distanceItCanTravel = ((pow(Vxy, 2)) / (19.62 * K));
	T = Vxy / (K * 9.81);
	D = (Vxy / 2) * T;
	distanceItTraveled = 0;

	while (distanceItTraveled < distancetoHit && Vxy > 0.01)
	{
		D = (Vxy / 2) * T * i * 0.001;
		distanceItTraveled += D;

		Vxy = Vxy - (K * 9.81 * T * i * 0.001);
		x = (cos(Dir) * distanceItTraveled) * 10 + Ox;
		y = (sin(Dir) * distanceItTraveled) * 10 + Oy;
		petitParcour.addCoor(x, y);
		i++;
	}
	if (distanceItTraveled >= distancetoHit)
	{
		cout << "touche mur" << endl;
		petitParcour.removelast();
		x = (cos(Dir) * distancetoHit * 0.99) * 10 + Ox;
		y = (sin(Dir) * distancetoHit * 0.99) * 10 + Oy;
		petitParcour.addCoor(x, y);
		balle->Set_Amplitude(Vxy/ 0.44704);
		angleReflexion(balle, mur);								//change l'angle de de la balle lorsqu'elle reflette le mur		
		balle->Set_Amplitude(Vxy / 0.44704);
		angleReflexion(balle, mur);								//change l'angle de de la balle lorsqu'elle reflette le mur		
		balle->Set_Oxy(x, y);
	}
	else if (Vxy <= 0.01)
	{
		balle->Set_Amplitude(0);
		x = (cos(Dir) * distanceItTraveled) * 10 + Ox;
		y = (sin(Dir) * distanceItTraveled) * 10 + Oy;
		balle->Set_Oxy(x, y);
		cout << "Balle en position (" << x << "," << 720-y << ")." << endl;
		cout << "Balle en position (" << x << "," << 720 - y << ")." << endl;
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
	Vxy = balle->Get_Amplitude() * 0.44704;													//converti la vitesse de balle de mph to m/s
	Dir = balle->Get_Direction();
	K = balle->Get_K();
	distancetoHit = (sqrt(pow(inters.first - Ox, 2) + pow(inters.second - Oy, 2))) / 10;	//distance entre la balle et sa prochaine interraction
	distanceItCanTravel = ((pow(Vxy, 2)) / (19.62 * K));
	T = Vxy / (K * 9.81);
	D = (Vxy / 2) * T;
	distanceItTraveled = 0;

	while (distanceItTraveled < distancetoHit && Vxy > 0.01)
	{
		D = (Vxy / 2) * T * i * 0.001;
		distanceItTraveled += D;
		Vxy = Vxy - (K * 9.81 * T * i * 0.001);
		x = (cos(Dir) * distanceItTraveled) * 10 + Ox;
		y = (sin(Dir) * distanceItTraveled) * 10 + Oy;
		petitParcour.addCoor(x, y);
		i++;
	}

	if (distanceItTraveled >= distancetoHit)
	{
		if (Vxy < 3) {
			trou->SetTrouReussi(1);
		}
		else {
			balle->Set_Amplitude(Vxy / 0.44704);
			angleReflexion(balle, trou, inters);				//change l'angle de de la balle lorsqu'elle passe trop vite sur le trou		
			balle->Set_Oxy(x, y);
		}
	}
	else if (Vxy <= 0.01)
	{
		balle->Set_Amplitude(0);
		x = (cos(Dir) * distanceItTraveled) * 10 + Ox;
		y = (sin(Dir) * distanceItTraveled) * 10 + Oy;
		balle->Set_Oxy(x, y);
		cout << "Balle en position (" << x << "," << y << ")." << endl;
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
	cout << "transfert de velocite de " << change / PI * 180 << " Deg." << endl;
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
			if (oldangle1 >= PI)
			{
				oldangle1 = oldangle1 - PI;
			}
			if (oldangle1 > PI / 2)
			{
				oldangle1 = PI - oldangle1;
			}
			facteurVelocity =PI/2 - ((PI/2 - oldangle1)/2);
			
			angleReflechis = oldangle - PI;
			if (angleReflechis < 0)
			{
				angleReflechis = -angleReflechis;
			}
			else
			{
				angleReflechis = 2*PI - angleReflechis;
			}
			balle->Set_Direction(angleReflechis);
			oldangle1 = oldangle1 - PI;
		}
		if (oldangle1 > PI / 2)
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
			facteurVelocity = PI / 2 - (oldangle1/2);
		}
		facteurVelocity = PI / 2 - ((PI / 2 - oldangle1) / 2);

		angleReflechis = oldangle - PI;
		if (angleReflechis < 0)
		{
			angleReflechis = -angleReflechis;
		}
		else
		{
			angleMur = atan2(mur->GetTy() - mur->GetHy(), mur->GetTx() - mur->GetHx());
			cout << "ANGLE MUR: " << angleMur*180/PI << endl;
			angleIncident = fmod(oldangle - angleMur + 2 * PI, 2 * PI);
			angleReflechis = fmod(angleMur - angleIncident + 2 *PI, 2 * PI);
			balle->Set_Direction(angleReflechis);
			cout << "ANGLE INCIDENT: "<< angleIncident*180/PI << endl;
			cout << "ANGLE REFLECHI: " << angleReflechis*180/PI << endl;
			while (angleReflechis < 0)
			{
				cout << "changement angle reflechis: " << angleReflechis * 180 / PI << endl;
				angleReflechis = angleReflechis + PI;
			}
			if (angleIncident >= PI)
			{
				angleIncident = angleIncident - PI;
			}
			if (angleIncident > PI / 2)
			{
				angleIncident = angleIncident - PI/2;
			}
			facteurVelocity = PI / 2 - ((PI / 2 - angleIncident) / 2);
		}
		facteurVelocity = facteurVelocity * 180/(PI * 100);				//Ici on veux reduire la velocite par rapport a l'angle d'incidence
		balle->Set_Amplitude(Vxy * facteurVelocity);
		cout << "FACteur velocity: " << facteurVelocity << endl;
}

pair<double, double> Interraction::intersection(Ball* balle, Mur* mur)							//equation de la trajectoire de la balle y = mx + b
{
	pair<double, double> pointIntersection;
	double m = tan(balle->Get_Direction());
	double b = balle->Get_Oy() - m * balle->Get_Ox();
	double m_wall, c_wall;
	if (mur->GetHx() == mur->GetTx())
	{
		m_wall = INFINITY;
		c_wall = mur->GetHx();
	}
	else
	{
		m_wall = (mur->GetTy() - mur->GetHy()) / (mur->GetTx() - mur->GetHx());	//equation de la droite du mur y = mx + c
		c_wall = mur->GetTy() - m_wall * mur->GetTx();
	}
	pointIntersection = make_pair((c_wall - b) / (m - m_wall), (m * ((c_wall - b) / (m - m_wall)) + b));								//calcul de l'intersection entre les deux droites
	return pointIntersection;
}

double Interraction::penteMur(Mur* mur)
{
	double m_wall = (mur->GetTy() - mur->GetHy()) / (mur->GetTx() - mur->GetHx());
	return m_wall;
}