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

Parcours Interraction::BalleMur(Ball* balle, Mur* mur)
{
	Parcours petitParcour;
	double posX = balle->Get_x();   // position en x et y
	double posY = balle->Get_y();
	timeBall = 0; //reset temps de la balle pour chaque petite partie du parcours
	double* intersectionXY;
	intersectionXY = intersection(balle, mur); //prend l'intersection entre la balle et le mur
	double murX = intersectionXY[0];
	double murY = intersectionXY[1];
	hitWall(mur, balle); //set le temps pour que la balle se rend au mur
	while (balle->Get_Vx() == 0 && balle->Get_Vy() == 0)  //tant que la balle a de la vitesse
		{
			if (timeBall >= timeHitWall)      // regarde si le temp de la balle depasse le temps ou elle touche le mur
			{
				angleReflexion(balle, mur);    //change l'angle de de la balle lorsqu'elle reflette le mur
				balle->Set_xy(intersectionXY[0], intersectionXY[1]); //met la balle au point de rencontre en celle-ci et le mur
				balle->Set_Oxy(balle->Get_x(), balle->Get_y());
				petitParcour.addCoor(balle->Get_x(), balle->Get_y());  //ajout des coordonné dans le parcours
				break;                         // arrete la fonction pour que ali recommence
			}
			positionUpdate(balle);            // change la position de la balle selon sa velocité
			vitesseUpdate(balle);              // diminue la velocité de la balle
			verifVxVy(balle->Get_Vx(), balle->Get_Vy(), balle);   //verifie si la velocité doit etre mis a 0 en raison d'un changement de +/-
			petitParcour.addCoor(balle->Get_x(), balle->Get_y());
		}
	balle->Set_Oxy(balle->Get_x(), balle->Get_y());
	return petitParcour;
}

Parcours Interraction::BalleTrou(Ball* balle, Hole* trou)
{
	double posX = balle->Get_x();   // position en x et y
	double posY = balle->Get_y();
	Parcours petitParcour;
	while (balle->Get_Vx() == 0 && balle->Get_Vy() == 0) //tant que la balle na pas une velocite de 0
	{
		if (hitHole(balle, trou))
		{
			trou->SetTrouReussi(true);
			break;                                       //arrete la boucle while
		}
		positionUpdate(balle);                          //update la position de la balle
		vitesseUpdate(balle);							//diminue la velocité de la balle
		verifVxVy(balle->Get_Vx(), balle->Get_Vy(), balle);  //verifie si la velocité doit etre mis a 0 en raison d'un changement de +/-
		petitParcour.addCoor(balle->Get_x(), balle->Get_y());

	}
	balle->Set_Oxy(balle->Get_x(), balle->Get_y());
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
	if (verifVx > 0 && verifVy > 0)  //si deviens négatif, deviens 0, pour pas que ca aille par en arriere a l'infini
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
	else if (verifVx > 0 && verifVy < 0) //regarde si la velocité change de sens pour eviter cela
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

	else if (verifVx < 0 && verifVy > 0) //idem que précédemment
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
	else if (verifVx < 0 && verifVy < 0) //si deviens positif, deviens 0...
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

void Interraction::hitWall(Mur* mur, Ball* balle) //temps pour que la balle touche le mur
{
	double * intersectionmur = intersection(balle, mur); //trouve le point d'intersection entre la balle et le mur
	double distanceToWall = sqrt(pow(intersectionmur[0] - balle->Get_Ox(), 2) + pow(intersectionmur[1] - balle->Get_Oy(), 2)); //trouve la distance entre la balle et le mur
	timeHitWall = distanceToWall / (sqrt(pow(balle->Get_Vx(), 2) + pow(balle->Get_Vy(), 2))); // trouve le temps nécessaire a la balle pour atteindre le mur
	
}

double* Interraction::intersectionTrou(Ball* balle, Hole* hole) //trouver l'intersection du trou(coordonnée de sont centre)
{
	double pointIntersectionHole[2];
	pointIntersectionHole[0] = hole->Get_x();
	pointIntersectionHole[1] = hole->Get_y();
	return pointIntersectionHole;
}


bool Interraction::hitHole(Ball* balle, Hole* hole)  // regarder si la balle est au moins a la moitier dans le trou
{
	double* intersectionHoleXY = intersectionTrou(balle, hole);
	double distance = sqrt(pow(intersectionHoleXY[0] - balle->Get_x(), 2) + pow(intersectionHoleXY[1] - balle->Get_y(), 2));
	return distance <= balle->Get_rayon() - hole->Get_radius() && balle->Get_Vx() > 0.5 && balle->Get_Vy() > 0.5;
}

void Interraction::vitesseUpdate(Ball* balle)
{
	double Vx = balle->Get_Vx();			//avoir les info sur la velocité et la decceleration
	double Vy = balle->Get_Vy();
	double ax = balle->Get_Ax();
	double ay = balle->Get_Ay();
	double dt = 0.01; // 10 ms car on veut le deplacement a chaque delta t = 10 ms

	Vx = Vx + dt * ax; //formule changer la velocité de la balle a chaque 10 ms
	Vy = Vy + dt * ay;
	balle->Set_Vxy(Vx, Vy);  //changer la velocité de la balle
}

void Interraction::positionUpdate(Ball* balle)
{
	double Vx = balle->Get_Vx();
	double Vy = balle->Get_Vy();
	double posX = balle->Get_x();
	double posY = balle->Get_y();
	double dt = 0.01; // 10 ms car on veut le deplacement a chaque delta t = 10 ms


	posX = posX + dt * Vx; // formule pour changer la position de x a chaque 10 ms
	posY = posY + dt * Vy;
	balle->Set_xy(posX, posY); //changer la position
	timeBall = timeBall + 0.01; //augmenter le temps parcourue ar la balle
}



void Interraction::interactionGen(Ball* balle, Mur* mur, Hole* hole) //faire le parcours jusqua ce que v = 0 ou que la balle touche un object
{
	double posX = balle->Get_x();   // position en x et y
	double posY = balle->Get_y();
	timeBall = 0; //reset temps de la balle pour chaque petite partie du parcours
	if (mur != NULL)  //si cest objet mur
	{
		double* intersectionXY; 
		intersectionXY = intersection(balle, mur); //prend l'intersection entre la balle et le mur
		double murX = intersectionXY[0];   
		double murY = intersectionXY[1];
		hitWall(mur , balle); //set le temps pour que la balle se rend au mur
		while ( balle->Get_Vx() == 0 && balle->Get_Vy() == 0)  //tant que la balle a de la vitesse
		{
			if (timeBall >= timeHitWall)      // regarde si le temp de la balle depasse le temps ou elle touche le mur
			{
				angleReflexion(balle, mur);    //change l'angle de de la balle lorsqu'elle reflette le mur
				balle->Set_xy(intersectionXY[0], intersectionXY[1]); //met la balle au point de rencontre en celle-ci et le mur
				balle->Set_Oxy(balle->Get_x(), balle->Get_y());
				break;                         // arrete la fonction pour que ali recommence
			}     
			positionUpdate(balle);            // change la position de la balle selon sa velocité
			vitesseUpdate(balle);              // diminue la velocité de la balle
			verifVxVy(balle->Get_Vx(), balle->Get_Vy(), balle);   //verifie si la velocité doit etre mis a 0 en raison d'un changement de +/-
			
		}
		balle->Set_Oxy(balle->Get_x(), balle->Get_y());
	}

	else if (hole != NULL) //si cest le trou le plus proche
	{
		while (balle->Get_Vx() == 0 && balle->Get_Vy() == 0) //tant que la balle na pas une velocite de 0
		{
			if (hitHole(balle, hole))
			{
				cout << "la balle est rentrer dans le trou"; //je ne savais pas quoi mettre, A CHANGER
				break;                                       //arrete la boucle while
			}
			positionUpdate(balle);                          //update la position de la balle
			vitesseUpdate(balle);							//diminue la velocité de la balle
			verifVxVy(balle->Get_Vx(), balle->Get_Vy(), balle);  //verifie si la velocité doit etre mis a 0 en raison d'un changement de +/-

		}
		balle->Set_Oxy(balle->Get_x(), balle->Get_y());
	}


}