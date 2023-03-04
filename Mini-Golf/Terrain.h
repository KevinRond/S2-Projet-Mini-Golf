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
	Mur* TableauMur[50];	//tableau pointeur des murs du terrain
	//Vector<pair<double, double>> parcours;

public:
	Terrain();		//Constructeur
	~Terrain();		//Destructeur

	Terrain *OpenTerrain();				//charge le terrain via fichier
	void CoupDonne(Coup *coup1);			//Lorsqu'un coup est donnee, retournera le parcours (emplacement par laps de temps dt) de la balle

	Interraction VerrifierColision(Ball ball);	//Doit virifie l'interaction avec son trou ou l'un de ses murs.
	void Display();								//affiche le terrain
};

struct Parcours
{
	int dt=10;					//intervale de temps en ms
	double location_dt[2][2];	//Location xy par intervale de temps dt
};

#endif