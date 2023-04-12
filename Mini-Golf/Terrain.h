
#ifndef TERRAIN_H
#define TERRAIN_H
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <utility>
#include <random>

#include "Mur.h"
#include "Ball.h"
#include "Hole.h"
#include "Coup.h"
#include "Parcours.h"
#include "Parcours.h"
#include "Interraction.h"


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
	Hole* hole1;						//Trou du terrain
	Ball* balle1;						//Depart de la balle
	std::vector<Mur*> vecteurMur1;		//tableau pointeur des murs du terrain
	Parcours ParcoursTotal;
	std::pair<double, double> pointIntersection;
	int prevIndex = -2;
	double K = 0.20;					//Facteur de friction	
	int nbCoup = 0;
	int nbRicochet = 0;
	bool terrainreussi = false;

public:
	Terrain();		
	~Terrain();		
	Terrain *OpenTerrain(std::string terrain);		//charge le terrain via fichier
	Parcours CoupDonne(Coup coup1);					//Fonction principale, resoura le coup et retournera le parcours au GM
	int VerifierColision();							//Doit virifie l'interaction avec son trou ou l'un de ses murs.
	bool isBetween(double value, double bound1, double bound2);
	void Display();
	int getCOup();
	int getRicochet();
	bool TerrainReussi();
	double getOx();
	double getOy();
};
#endif