#ifndef INTERRACTION_H
#define INTERRACTION_H
/*
La classe interaction caracterisera une interaction entre 2 objets
Ex: Ball avec Mur,Trou,Sable,glace
On est dans un monde de mini-put, on peux faire s'quon veux...
*/
#include "Terrain.h"
#include <cmath>
#include <vector>
#include <utility>

#define PI 3.14159265359

class Interraction
{
private:
	double x, y;
	int Degre;							//Angle ou direction de l'interaction
	double module;						//distance de l'interaction 
	double Fac = 1;						//Facteur d'influence, peux etre utilise pour diminue ou augmente la vitesse suite a une interaction
	double timeHitWall = 0;
	double timeBall = 0;
	
public:
	Interraction();						//lors de sa construction l'objet doit determine sa location X,Y son angle d'incidence et determiner un facteur
	~Interraction();
	double InterractionX();				//Retourne le lieux X de l'interaction
	double InterractionY();				//Retourne le lieux Y de l'interaction
	double InterractionAngle();			//Retourne l'angle d'incidence
	double InterractionFac();			//Retourne le facteur d'influence
	double Module();					//Retour la distance en les 2 objets en interaction

	void vitesseUpdate(Ball* balle);	//Modification de la velocite et de la position
	void positionUpdate(Ball* balle);

	Parcours BalleMur(Ball* balle, Mur* mur);				//Interraction avec un mur
	Parcours BalleTrou(Ball* balle, Hole* trou);

	void angleReflexion(Ball* balle, Mur *mur);
	std::pair<double, double> intersection(Ball* balle, Mur* mur);
	double penteMur(Mur* mur);
	void verifVxVy(double verifVx, double verifVy, Ball* balle);
	void hitWall(Mur* mur, Ball* balle);

	std::pair<double, double> intersectionTrou(Hole* hole);		//Interraction avec un hole
	bool hitHole(Ball* balle, Hole* hole);

	void interactionGen(Ball* balle, Mur* mur, Hole* hole);	//Interraction principal avec soit un mur, soit un trou
};

#endif
