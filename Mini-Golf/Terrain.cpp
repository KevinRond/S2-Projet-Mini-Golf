#ifndef TERRAIN_CPP
#define TERRAIN_CPP
#include <iostream>
#include <fstream>
#include "Terrain.h"

/*
LA classe Terrain possède un tableau qui contiendra les éléments du terrain comme les murs, les trous, le point de départ.
Elle cherche dans un fichier txt les composantes qui constituront le terrain.
Lors que la balle est en mouvement, cette classe ira trouver avec laquel de ses composantes (trou, mur) elle intéragit
Celle-ci retourne un objet Interraction qui seront les nouvelles "instructions" que la la balle devra suivre.
La classe retournera toujours un objet Interaction avec une coordonnée X,Y
La classe Ball sera responsable de de savoir si elle atteint cette position dépendament de sa velossité
*/

//	int nbMur = 0;
//	Hole hole;				//Trou du terrain
//	Mur* TableauMur[];	//tableau pointeur des murs du terrain
usinf namespace std;

Terrain::Terrain()
{
	Terrain1.OpenTerrain();
}


bool Terrain::OpenTerrain()
	{
		fstream myFile;
		myFile.open("Terrain1.txt", ios_base::in);
		if (myFile.is_open()) // check if open() succeeded
		{
			while (myFile.good())
			{
				getline(myFile, fileContents);
				cout << fileContents << enld;
			}

			myFile.close();
		}

		return false;
	}

	Interraction Terrain::VerrifierColision(Ball ball)
	{
		return Interraction();
	}

	void Terrain::Display()
	{
	}

#endif