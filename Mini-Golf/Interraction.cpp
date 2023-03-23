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
	double verifVx = balle->Get_Vx();
	double verifVy = balle->Get_Vy();
	timeBall = 0;																		//reset temps de la balle pour chaque petite partie du parcours
	//pair<double, double> intersectionXY = intersection(balle, mur);											//prend l'intersection entre la balle et le mur																//set le temps pour que la balle se rend au mur
	//cout << "intersection: " << intersectionXY.first << "; " << intersectionXY.second << endl;
																											//cout << "coordonee angle: " << balle->Get_Ax() << "; " << balle->Get_Ay() << endl;
	while (balle->Get_Vx() != 0 && balle->Get_Vy() != 0)								//tant que la balle a de la vitesse
		{
			double posX = balle->Get_x();														// position en x et y
			double posY = balle->Get_y();
			if (hitWall(mur, balle, inters))												// regarde si le temp de la balle depasse le temps ou elle touche le mur
			{
				cout << "touche mur" << endl;
				//balle->Set_xy(inters.first, inters.second);				//met la balle au point de rencontre en celle-ci et le mur
				//balle->Set_Oxy(inters.first, inters.second);
				angleReflexion(balle, mur, inters);												//change l'angle de de la balle lorsqu'elle reflette le mur		
				cout <<"angle: "<< balle->Get_direction()*180/PI << endl;
				//cout << "coordonee angle: " << balle->Get_Ax() << "; " << balle->Get_Ay() << endl;

				positionUpdate(balle);														//change la position de la balle selon sa velocite
				vitesseUpdate(balle);													//diminue la velocite de la balle
																						//balle->Set_xy(inters.first, inters.second);				//met la balle au point de rencontre en celle-ci et le mur
				balle->Set_Oxy(balle->Get_x(), balle->Get_y());
				//verifVxVy(verifVx, verifVy, balle);
				petitParcour.addCoor(balle->Get_x(), balle->Get_y());						//ajout des coordonne dans le parcours
				break;																	//arrete la fonction pour que ali recommence
			}
			positionUpdate(balle);														//change la position de la balle selon sa velocite
			vitesseUpdate(balle);														//diminue la velocite de la balle
			verifVxVy(verifVx, verifVy, balle);							//verifie si la velocite doit etre mis a 0 en raison d'un changement de +/-
			petitParcour.addCoor(posX, posY);
			cout << balle->Get_Vx() << "  " << balle->Get_Vy() << endl;
			cout <<"["<< balle->Get_x() << "  " << balle->Get_y() << "]"<< endl;
		}
	balle->Set_Oxy(balle->Get_x(), balle->Get_y());
	return petitParcour;
}

Parcours Interraction::BalleTrou(Ball* balle, Hole* trou, std::pair<double, double> inters)
{
	cout << "rentredans trou" << endl;
	Parcours petitParcour;
	double verifVx = balle->Get_Vx();
	double verifVy = balle->Get_Vy();
	while (balle->Get_Vx() != 0 && balle->Get_Vy() != 0)					//tant que la balle na pas une velocite de 0
	{
		double posX = balle->Get_x();											//position en x et y
		double posY = balle->Get_y();
		if (hitHole(balle, trou))
		{
			trou->SetTrouReussi(true);
			break;															 //arrete la boucle while
		}
		positionUpdate(balle);												//update la position de la balle
		vitesseUpdate(balle);												//diminue la velocite de la balle
		verifVxVy(verifVx, verifVy, balle);						//verifie si la velocite doit etre mis a 0 en raison d'un changement de +/-
		petitParcour.addCoor(posX, posY);
		//cout << balle->Get_Vx() << "  " << balle->Get_Vy() << endl;
		cout << balle->Get_Vx() << "  " << balle->Get_Vy() << endl;
		cout << "[" << balle->Get_x() << "  " << balle->Get_y() << "]" << endl;
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

void Interraction::angleReflexion(Ball* balle, Mur* mur, std::pair<double, double> inters)							//trouver l'angle de reflexion de la balle
{
		double oldangle = balle->Get_direction();
		double angleIncident;
		double angleMur;
		double angleReflechis = 0;
		if (mur->GetHx() == mur->GetTx())
		{
			
			angleReflechis = abs(oldangle - PI);
			balle->Set_direction(angleReflechis * 180 / PI);
			
		}
		else if (mur->GetHy() == mur->GetTy())
		{
			angleReflechis = 2 * PI - oldangle;
			balle->Set_direction(angleReflechis * 180 / PI);
		}
		else
		{
			angleMur = atan2(mur->GetTy() - mur->GetHy(), mur->GetTx() - mur->GetHx());
			angleIncident = fmod(oldangle - angleMur + 2 * PI, 2 * PI);
			angleReflechis = fmod(angleMur - angleIncident + PI, 2 * PI);
			while (angleReflechis < 0)
			{
				angleReflechis = angleReflechis + PI;
			}
			balle->Set_direction(angleReflechis * 180 / PI);
		}
		
		
		double vitesse = sqrt(balle->Get_Vx() * balle->Get_Vx() + balle->Get_Vy() * balle->Get_Vy());

		double newVx = vitesse * cos(angleReflechis);
		double newVy = vitesse * sin(angleReflechis);

		if ((balle->Get_Vx() < 0 && newVx > 0) || (balle->Get_Vx() > 0 && newVx < 0))
		{
			balle->Set_Axy(-balle->Get_Ax(), balle->Get_Ay());
		}
		if ((balle->Get_Vy() < 0 && newVy > 0) || (balle->Get_Vy() > 0 && newVy < 0))
		{
			balle->Set_Axy(balle->Get_Ax(), -balle->Get_Ay());
		}
		balle->Set_Vxy(newVx, newVy);

		
		//balle->Set_direction(angleIncident * 180 / PI);
}

pair<double, double> Interraction::intersection(Ball* balle, Mur* mur)							//equation de la trajectoire de la balle y = mx + b
{
	pair<double, double> pointIntersection;
	double m = tan(balle->Get_direction());
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

void Interraction::verifVxVy(double verifVx, double verifVy, Ball* balle)			//fonction pour pas que la balle bouge a linfini
{
	if (verifVx > 0 && verifVy > 0)													//si deviens negatif, deviens 0, pour pas que ca aille par en arriere a l'infini
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
	else if (verifVx > 0 && verifVy < 0)						//regarde si la velocite change de sens pour eviter cela
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

	else if (verifVx < 0 && verifVy > 0)						//idem que precedemment
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
	else if (verifVx < 0 && verifVy < 0)						//si deviens positif, deviens 0...
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

bool Interraction::hitWall(Mur* mur, Ball* balle, std::pair<double, double> inters)																				//temps pour que la balle touche le mur
{
	//pair<double, double> intersectionmur = intersection(balle, mur);																		//trouve le point d'intersection entre la balle et le mur
	double distanceToWall = sqrt(pow(inters.first - balle->Get_x(), 2) +pow(inters.second - balle->Get_y(), 2));	//trouve la distance entre la balle et le mur
	//timeHitWall = distanceToWall / (sqrt(pow(balle->Get_Vx(), 2) + pow(balle->Get_Vy(), 2)));									// trouve le temps necessaire a la balle pour atteindre le mur
	cout <<"distance: "<< distanceToWall << endl;
	//cout << "{" << inters.first << "," << inters.second << "}" << endl;
	return distanceToWall <= balle->Get_rayon();
}

pair<double, double> Interraction::intersectionTrou(Hole* hole)										//trouver l'intersection du trou(coordonnee de sont centre)
{
	pair<double, double> pointIntersectionHole = make_pair(hole->Get_x(), hole->Get_y());
	return pointIntersectionHole;
}


bool Interraction::hitHole(Ball* balle, Hole* hole)													//regarder si la balle est au moins a la moitier dans le trou
{
	pair<double, double> intersectionHoleXY = intersectionTrou(hole);
	double distance = sqrt(abs(pow(intersectionHoleXY.first - balle->Get_x(), 2)) + abs(pow(intersectionHoleXY.second - balle->Get_y(), 2)));
	cout << "distance trou: " << distance << endl;
	return distance <= hole->Get_radius() - balle->Get_rayon();
}

bool Interraction::perpendiculaire(Ball* balle, Mur* mur)
{
	//Calculer vecteur normal mur
	double normWallx = mur->GetTy() - mur->GetHy();
	double normWally = mur->GetTx() - mur->GetHx();

	//normaliser vecteur normal
	double norm = sqrt(abs(normWallx * normWallx + normWally * normWally));
	normWallx = normWallx / norm;
	normWally = normWally / norm;

	//direction de la balle
	double ball_dirx = cos(balle->Get_direction());
	double ball_diry = sin(balle->Get_direction());
	//produit scalaire

	double produitScalaire = normWallx * ball_dirx + normWally * ball_diry;
	return produitScalaire == 0;
}

void Interraction::vitesseUpdate(Ball* balle)
{
	double Vx = balle->Get_Vx();																	//avoir les info sur la velocite et la decceleration
	double Vy = balle->Get_Vy();
	double ax = balle->Get_Ax();
	double ay = balle->Get_Ay();
	double dt = 0.01;																				//10 ms car on veut le deplacement a chaque delta t = 10 ms

	Vx = Vx + dt * ax;																				//formule changer la velocite de la balle a chaque 10 ms
	Vy = Vy + dt * ay;
	balle->Set_Vxy(Vx, Vy);																			//changer la velocite de la balle
}

void Interraction::positionUpdate(Ball* balle)
{
	double Vx = balle->Get_Vx();
	double Vy = balle->Get_Vy();
	double posX = balle->Get_x();
	double posY = balle->Get_y();
	double dt = 0.01;																				//10 ms car on veut le deplacement a chaque delta t = 10 ms


	posX = posX + dt * Vx;																			//formule pour changer la position de x a chaque 10 ms
	posY = posY + dt * Vy;
	balle->Set_xy(posX, posY);																		//changer la position
	timeBall = timeBall + 0.01;																		//augmenter le temps parcourue ar la balle
}



/*void Interraction::interactionGen(Ball* balle, Mur* mur, Hole* hole)					//faire le parcours jusqua ce que v = 0 ou que la balle touche un object
{
	double posX = balle->Get_x();														//position en x et y
	double posY = balle->Get_y();
	timeBall = 0;																		//reset temps de la balle pour chaque petite partie du parcours
	if (mur != NULL)																	//si cest objet mur
	{
		pair<double, double> intersectionXY;
		intersectionXY = intersection(balle, mur);										//prend l'intersection entre la balle et le mur
		double murX = intersectionXY.first;   
		double murY = intersectionXY.second;
		hitWall(mur , balle);															//set le temps pour que la balle se rend au mur
		while ( balle->Get_Vx() == 0 && balle->Get_Vy() == 0)							//tant que la balle a de la vitesse
		{
			if (timeBall >= timeHitWall)												//regarde si le temp de la balle depasse le temps ou elle touche le mur
			{
				angleReflexion(balle, mur);												//change l'angle de de la balle lorsqu'elle reflette le mur
				balle->Set_xy(murX, murY);												//met la balle au point de rencontre en celle-ci et le mur
				balle->Set_Oxy(posX, posY);
				break;																	//arrete la fonction pour que ali recommence
			}     
			positionUpdate(balle);														//change la position de la balle selon sa velocite
			vitesseUpdate(balle);														//diminue la velocite de la balle
			verifVxVy(balle->Get_Vx(), balle->Get_Vy(), balle);							//verifie si la velocite doit etre mis a 0 en raison d'un changement de +/-
			
		}
		balle->Set_Oxy(posX, posY);
	}

	else if (hole != NULL)																//si cest le trou le plus proche
	{
		while (balle->Get_Vx() == 0 && balle->Get_Vy() == 0)							//tant que la balle na pas une velocite de 0
		{
			if (hitHole(balle, hole))
			{
				cout << "la balle est rentrer dans le trou";							//je ne savais pas quoi mettre, A CHANGER
				break;																	//arrete la boucle while
			}
			positionUpdate(balle);														//update la position de la balle
			vitesseUpdate(balle);														//diminue la velocite de la balle
			verifVxVy(balle->Get_Vx(), balle->Get_Vy(), balle);							//verifie si la velocite doit etre mis a 0 en raison d'un changement de +/-

		}
		balle->Set_Oxy(posX, posY);
	}


}*/