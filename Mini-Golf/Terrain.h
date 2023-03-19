#ifndef TERRAIN_H
#define TERRAIN_H
#include <iostream>
#include <fstream>
#include "Mur.h"
#include "Ball.h"
#include "Hole.h"
#include "Interraction.h"
#include "Coup.h"
#include <vector>
#include <cmath>
#include "Parcours.h"


#define PI 3.14159265


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
	Interraction* interraction;
	double K;						//Facteur de friction
	
public:
	Terrain();		
	~Terrain();		

	Terrain *OpenTerrain();				//charge le terrain via fichier
	Parcours CoupDonne(Coup *coup1);	//Fonction principale, resoura le coup et retournera le parcours au GM

	double GetIntersection(double x1, double x2, double y1,double y2, double x3, double y3); //fonction détermine la colision avec un mur
	/*	
		x1 = x tail mur
		x2 = x head mur
		x3 = x balle
		y1 = y tail mur
		y2 = y head mur
		y3 = y balle
	*/
	bool GetIntersectionHole(double x, double y, double xt, double yt, double radius);
	double distance(double x1, double y1, double x2, double y2);
	int VerifierColision();			//Doit virifie l'interaction avec son trou ou l'un de ses murs.
	void Display();																		//affiche le terrain
	void testParcours();
};
#endif