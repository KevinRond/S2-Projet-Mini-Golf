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
	Hole* hole1;			//Trou du terrain
	Ball* balle1;			//Depart de la balle
	std::vector<Mur*> vecteurMur;	//tableau pointeur des murs du terrain
	Parcours parcourstotal;
	
	//Vector<pair<double, double>> parcours;

public:
	Terrain();		//Constructeur
	~Terrain();		//Destructeur

	Terrain *OpenTerrain();				//charge le terrain via fichier
	void CoupDonne(Coup *coup1);	
	//Lorsqu'un coup est donnee, retournera le parcours (emplacement par laps de temps dt) de la balle
	//Interraction DirectionTrou;
	//Interraction DirectionMur();
	double GetIntersection(double x1, double x2, double y1,double y2, double x3, double y3); //fonction qui va aller chercher 
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
	void VerifierColision(Ball* ball, Hole* trou, vector<Mur*> vecteur_mur);	//Doit virifie l'interaction avec son trou ou l'un de ses murs.
	void Display();								//affiche le terrain
};

struct Parcours
{
	int dt=10;					//intervale de temps en ms
	double location_dt[2][2];	//Location xy par intervale de temps dt
};

#endif