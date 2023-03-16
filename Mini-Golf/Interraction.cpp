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
}

Interraction::~Interraction()
{
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

void Interraction::angleReflexion(Ball* balle, Mur* mur)
{

	//trouver l'angle de reflexion de la balle
	double oldangle = balle->Get_direction();
	balle->Set_direction(2 * atan(penteMur(mur) - oldangle));
}

double* Interraction::intersection(Ball* balle, Mur* mur)
{
	double pointIntersection[2];
	//equation de la trajectoire de la balle y = mx + b
	double m = tan(balle->Get_direction()* PI/180 );
	double b = balle->Get_Oy() - m * balle->Get_Ox();

	//equation de la droite du mur y = mx + c
	double m_wall = (mur->GetTy() - mur->GetHy()) / (mur->GetTx() - mur->GetHx());
	double c_wall = mur->GetTy() - m_wall * mur->GetTx();

	//calcul de l'intersection entre les deux droites
	pointIntersection[0] = (c_wall - b) / (m - m_wall);
	pointIntersection[1] = (m * pointIntersection[0] + b);

	return pointIntersection;
}

double Interraction::penteMur(Mur* mur)
{
	double m_wall = (mur->GetTy() - mur->GetHy()) / (mur->GetTx() - mur->GetHx());
	return m_wall;
}

void Interraction::verifVxVy(double verifVx, double verifVy, Ball* balle) //fonction pour pas que la balle bouge a linfini
{
	if (verifVx > 0 && verifVy > 0)
	{
		if (balle->Get_Vx() < 0)
		{
			balle->Set_Vx(0);
		}

		if (balle->Get_Vy() < 0)
		{
			balle->Set_Vy(0);
		}
	}
	else if (verifVx > 0 && verifVy < 0)
	{
		if (balle->Get_Vx() < 0)
		{
			balle->Set_Vx(0);
		}

		if (balle->Get_Vy() > 0)
		{
			balle->Set_Vy(0);
		}
	}

	else if (verifVx < 0 && verifVy > 0)
	{
		if (balle->Get_Vx() > 0)
		{
			balle->Set_Vx(0);
		}

		if (balle->Get_Vy() < 0)
		{
			balle->Set_Vy(0);
		}
	}
	else if (verifVx < 0 && verifVy < 0)
	{
		if (balle->Get_Vx() > 0)
		{
			balle->Set_Vx(0);
		}

		if (balle->Get_Vy() > 0)
		{
			balle->Set_Vy(0);
		}
	}
	
}

void Interraction::hitWall(Mur* mur, Ball* balle)
{
	double m = tan(balle->Get_direction() * PI / 180);
	double b = balle->Get_Oy() - m * balle->Get_Ox();
}

void Interraction::vitesseUpdate(Ball* balle)
{
	double Vx = balle->Get_Vx();
	double Vy = balle->Get_Vy();
	double ax = balle->Get_Ax();
	double ay = balle->Get_Ay();
	double dt = 0.01; // 10 ms car on veut le deplacement a chaque delta t = 10 ms

	Vx = Vx + dt * ax;
	Vy = Vy + dt * ay;
	balle->Set_Vxy(Vx, Vy);
}

void Interraction::positionUpdate(Ball* balle)
{
	double Vx = balle->Get_Vx();
	double Vy = balle->Get_Vy();
	double posX = balle->Get_x();
	double posY = balle->Get_y();
	double dt = 0.01; // 10 ms car on veut le deplacement a chaque delta t = 10 ms


	posX = posX + dt * Vx;
	posY = posY + dt * Vy;
	balle->Set_xy(posX, posY);
}

void Interraction::interactionGen(Ball* balle, Mur* mur, Hole* hole)
{
	double posX = balle->Get_x();
	double posY = balle->Get_y();
	if (mur != NULL)
	{
		double* intersectionXY;
		intersectionXY = intersection(balle, mur);
		double murX = intersectionXY[0];
		double murY = intersectionXY[1];
		while ( balle->Get_Vx() == 0 && balle->Get_Vy() == 0)
		{
			double verifVx = balle->Get_Vx();
			double verifVy = balle->Get_Vy();
			if (balle->Get_x() == intersectionXY[0] && balle->Get_y() == intersectionXY[1])
			{
				angleReflexion(balle, mur);
			}
			positionUpdate(balle);
			vitesseUpdate(balle);
			verifVxVy(verifVx, verifVy, balle);
			
		}
		//angleReflexion(balle, mur);
		//trouver si la balle se rend au mur



	}

	if (hole != NULL)
	{

	}


}