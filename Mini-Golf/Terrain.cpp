#include <iostream>
#include <fstream>
#include "Terrain.h"

/*
LA classe Terrain poss�de un tableau qui contiendra les �l�ments du terrain comme les murs, les trous, le point de d�part.
Elle cherche dans un fichier txt les composantes qui constituront le terrain.
Lors que la balle est en mouvement, cette classe ira trouver avec laquel de ses composantes (trou, mur) elle int�ragit
Celle-ci retourne un objet Interraction qui seront les nouvelles "instructions" que la la balle devra suivre.
La classe retournera toujours un objet Interaction avec une coordonn�e X,Y
La classe Ball sera responsable de de savoir si elle atteint cette position d�pendament de sa velossit�
*/

//	int nbMur = 0;
//	Hole hole;				//Trou du terrain
//	Mur* TableauMur[];	//tableau pointeur des murs du terrain
using namespace std;

Terrain::Terrain()
{
	nbMur = 0;
	//Terrain::OpenTerrain();
	cout << "etape 2" << endl;
}

Terrain::~Terrain()
{
}


bool Terrain::OpenTerrain()
{
	ifstream myFile;
	myFile.open("Terrain1.txt", ios_base::in);
	bool Coor = false; //Op�rateur qui d�termine si X ou Y, si false c'est un X, si true c'est Y
	string lineContents; //contenu de la ligne compl�te
	char separatorXY = ','; //s�parateur XY (X,Y)
	char separatorCoor = ';'; //s�parateur de point (X,Y);(X,Y)
	int i = 0;
	string ptt; //pour accumulation de carract�re
	double Coor1[2];
	double Coor2[2];
	Coor2[0]=-1.0;
	if (myFile.is_open()) // check if open() succeeded
	{
		while (myFile.good())
		{
			getline(myFile, lineContents);
			cout << lineContents << endl;
			while (lineContents[i] != '\0') {
				if (lineContents[i] == separatorXY) {
					Coor1[Coor] = stod(ptt);
					Coor = !Coor;
					ptt.clear();
				}
				else if (lineContents[i] == separatorCoor)
				{
					Coor1[Coor] = stod(ptt);
					ptt.clear();
					Coor = !Coor;
						if (Coor2[0] != -1.0)
						{
							Mur MurTemp(Coor1[0], Coor1[1], Coor2[0], Coor2[1]);
							TableauMur[nbMur] = MurTemp.Get();	//cr�ation d'objet mur
							nbMur++;
							MurTemp.Display();
						}
					Coor2[0] = Coor1[0];
					Coor2[1] = Coor1[1];
				}
				else if (lineContents[i] == 'B') {}
				else if (lineContents[i] == 'T') {}
				else {
					ptt += lineContents[i];
				}
				i++;

				cout << ptt << endl;
				
			}
			i = 0;
			Coor2[0] = -1.0;
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