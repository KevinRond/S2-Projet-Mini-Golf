#ifndef TERRAIN_H
#define TERRAIN_H
#include <iostream>
#include <fstream>
#include "Mur.h"
#include "Ball.h"
#include "Hole.h"
#include "Interraction.h"

/*
LA classe Terrain poss�de un tableau qui contiendra les �l�ments du terrain comme les murs, les trous, le point de d�part.
Elle cherche dans un fichier txt les composantes qui constituront le terrain.
Lors que la balle est en mouvement, cette classe ira trouver avec laquel de ses composantes (trou, mur) elle int�ragit
Celle-ci retourne un objet Interraction qui seront les nouvelles "instructions" que la la balle devra suivre.
La classe retournera toujours un objet Interaction avec une coordonn�e X,Y
La classe Ball sera responsable de de savoir si elle atteint cette position d�pendament de sa velossit�
*/

class Terrain
{
private:
	int nbMur;
	Hole* hole;				//Trou du terrain
	Ball* balle1;			//D�part de la balle
	Mur* TableauMur[50];	//tableau pointeur des murs du terrain

public:
	Terrain();
	~Terrain();

	bool OpenTerrain(); //charge le terrain via fichier
	Interraction VerrifierColision(Ball ball); //Doit virifi� l'int�raction avec son trou ou l'un de ses murs.
	void Display(); //affiche le terrain


};

#endif