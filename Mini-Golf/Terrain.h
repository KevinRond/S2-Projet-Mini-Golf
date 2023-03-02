#ifndef TERRAIN_H
#define TERRAIN_H
#include <iostream>
#include <fstream>
#include "Hole.h"
#include "Interraction.h"
#include "Mur.h"
/*
LA classe Terrain possède un tableau qui contiendra les éléments du terrain comme les murs, les trous, le point de départ.
Elle cherche dans un fichier txt les composantes qui constituront le terrain.
Lors que la balle est en mouvement, cette classe ira trouver avec laquel de ses composantes (trou, mur) elle intéragit
Celle-ci retourne un objet Interraction qui seront les nouvelles "instructions" que la la balle devra suivre.
La classe retournera toujours un objet Interaction avec une coordonnée X,Y
La classe Ball sera responsable de de savoir si elle atteint cette position dépendament de sa velossité
*/
using namespace std;
class Terrain
{
private:
	int nbMur = 0;
	Hole hole;				//Trou du terrain
	Mur TableauMur;	//tableau pointeur des murs du terrain

public:
	Terrain();
	bool OpenTerrain(); //charge le terrain via fichier
	Interraction VerrifierColision(Ball ball); //Doit virifié l'intéraction avec son trou ou l'un de ses murs.
	void Display(); //affiche le terrain
	

};

#endif