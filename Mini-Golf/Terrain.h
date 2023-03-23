
#ifndef TERRAIN_H
#define TERRAIN_H
#include <iostream>
#include <fstream>
#include "Mur.h"
#include "Ball.h"
#include "Hole.h"
#include "Coup.h"
#include <vector>
#include <cmath>
#include "Parcours.h"
#include <utility>

/*
LA classe Terrain comporte les ellements suivants:
-Un tableau *pointeur des Mur qui la compose TableauMur[]
-Un objet Trou (hole1) et ball (balle1)
Ses methodes:
-Lire un fichier de terrain
-Verifier la prochaine interaction
-Compiler un parcours de location d'un coup
*/

class Terrain
{
private:
	int nbMur;
	Hole* hole1;					//Trou du terrain
	Ball* balle1;					//Depart de la balle
	std::vector<Mur*> vecteurMur1;	//tableau pointeur des murs du terrain
	Parcours ParcoursTotal;
	std::pair<double, double> pointIntersection;
	int prevIndex = -2;
	double K = 1;					//Facteur de friction	
	int nbCoup = 0;
public:
	Terrain();		
	~Terrain();		

	Terrain *OpenTerrain(std::string terrain);				//charge le terrain via fichier
	Parcours CoupDonne(Coup coup1);		//Fonction principale, resoura le coup et retournera le parcours au GM
	int VerifierColision();				//Doit virifie l'interaction avec son trou ou l'un de ses murs.
	bool isBetween(double value, double bound1, double bound2);
	bool isOnLine(double x0, double y0, double m, double b);
	void Display();
};
#endif