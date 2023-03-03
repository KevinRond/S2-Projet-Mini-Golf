#include <iostream>
#include <fstream>
#include <string>
#include "Terrain.h"
using namespace std;
/*
LA classe Terrain possede un tableau qui contiendra les elements du terrain comme les murs, les trous, le point de depart.
Elle cherche dans un fichier txt les composantes qui constituront le terrain.
Lors que la balle est en mouvement, cette classe ira trouver avec laquel de ses composantes (trou, mur) elle interagit
Celle-ci retourne un objet Interraction qui seront les nouvelles "instructions" que la la balle devra suivre.
La classe retournera toujours un objet Interaction avec une coordonnee X,Y
La classe Ball sera responsable de de savoir si elle atteint cette position dependament de sa velossite
*/

//	int nbMur = 0;
//	Hole hole;				//Trou du terrain
//	Mur* TableauMur[];	//tableau pointeur des murs du terrain
using namespace std;

Terrain::Terrain()
{
	nbMur = 0;
	cout << "creation du terrain" << endl;
}

Terrain::~Terrain()
{
}


Terrain *Terrain::OpenTerrain()
{
	/* POUR VOIR OU CA LECRIT (REPERTOIRE DE TRAVAIL)
	ofstream outFile;
	outFile.open("Terrain3.txt", ios_base::out);
	if (outFile.is_open()) // check if open() succeeded
	{
		cout << "opened" << endl;
		outFile.close();
	}*/


	ifstream myFile;
	myFile.open("Terrain1.txt", ios_base::in);
	bool Coor = false; //Operateur qui determine si X ou Y, si false c'est un X, si true c'est Y
	string lineContents; //contenu de la ligne complete
	char separatorXY = ','; //separateur XY (X,Y)
	char separatorCoor = ';'; //separateur de point (X,Y);(X,Y)
	int i = 0;
	string ptt; //pour accumulation de carractere
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
						Mur *MurTemp = new Mur;
						MurTemp->Set(Coor1[0], Coor1[1], Coor2[0], Coor2[1]);
						TableauMur[nbMur] = MurTemp->Get();	//creation d'objet mur
						nbMur++;
						MurTemp->Display();
						cout << "Mur #" << nbMur << " ajoute" << endl;
					}
					Coor2[0] = Coor1[0];
					Coor2[1] = Coor1[1];
				}
				else if (lineContents[i] == 'B')
				{
					Ball* BalleTemp = new Ball;
					BalleTemp->setXY(Coor1[0], Coor1[1]);
					balle1 = BalleTemp->get();
					BalleTemp->Display();
					cout << "Depart de balle a " << BalleTemp->get() << " ajoute" << endl;
				}
				else if (lineContents[i] == 'T')
				{
					Hole* HoleTemp = new Hole;
					HoleTemp->setXY(Coor1[0], Coor1[1]);
					hole1 = HoleTemp->get();
					HoleTemp->Display();
					cout << "Le trou du parcours est a " << HoleTemp->get() << " ajoute" << endl;
				}
				else
				{
					ptt += lineContents[i];
				}
				i++;

				cout << ptt << endl;
				
			}
			i = 0;
			Coor2[0] = -1.0;
		}

		myFile.close();
		return this;
	}

	return this;
}


Interraction Terrain::VerrifierColision(Ball ball)
{
	return Interraction();
}

void Terrain::Display()
{
	for (int i = 0; i < nbMur; i++) {
		cout << "Mur # " << i+1 << "/" << nbMur << endl;
		TableauMur[i]->Display();
	}
	balle1->Display();
	hole1->Display();
}