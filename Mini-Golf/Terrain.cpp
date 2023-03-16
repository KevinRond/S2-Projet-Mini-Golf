#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include "Terrain.h"

/*
LA classe Terrain comporte les ellements suivants:
-Un tableau *pointeur des Mur qui la compose TableauMur[]
-Un objet Trou (hole1) et ball (balle1)
Ses methodes:
-Lire un fichier de terrain
-Verifier la prochaine interaction
-Compiler un parcours de location d'un coup
*/  

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
	ifstream myFile;								//Creation de l'objet fichier
	myFile.open("Terrain1.txt", ios_base::in);		//ouveture du fichier
	bool Coor = false;								//Operateur inverseur qui determinera si 0=X ou 1=Y
	string lineContents;							//Contenu de la ligne lu complete
	char separatorXY = ',';							//separateur d'axe XY (X,Y)
	char separatorCoor = ';';						//separateur de coordonnees (X,Y);(X,Y)
	int i = 0;										//Index de ligne de lecture
	string ptt;										//Pour accumulation des nombres a double digit
	double Coor1[2];								//Premiere coordonnee
	double Coor2[2];								//Deuxiere coordonnee
	Coor2[0]=-1.0;									//initialise a 0 pour savoir si premiere lecture

	if (myFile.is_open())										//Verrifie si l'ouverture est faite
	{
		while (myFile.good())
		{
			getline(myFile, lineContents);						//Lecture de la ligne au complet
			while (lineContents[i] != '\0') {					//Lecture jusqu'a la fin (caractere nul)
				if (lineContents[i] == separatorXY) {			//verifie le separateur de (,)
					Coor1[Coor] = stod(ptt);					//Converti le texte en numerique
					Coor = !Coor;								//Inverse le parametre de coor
					ptt.clear();								//Vide l'accumulateur
				}
				else if (lineContents[i] == separatorCoor)						//verifie le separateur de (;)
				{																//Coordonne est donc complette
					Coor1[Coor] = stod(ptt);									//Converti le texte en numerique
					Coor = !Coor;												//Inverse le parametre de coor
					ptt.clear();												//Vide l'accumulateur
					if (Coor2[0] != -1.0)										//Verifie si c'est la premiere coor (besoin de 2 pour un mur)
					{
						Mur *MurTemp = new Mur;									//Creation d'un objet Mur
						MurTemp->Set(Coor1[0], Coor1[1], Coor2[0], Coor2[1]);	//Attribution de ses 2 coor
						//TableauMur[nbMur] = MurTemp->Get();						//Assignation au TableauMur de notre terrain
						vecteurMur.push_back(MurTemp->Get());
						nbMur++;												//Incremenation du nombre de Murs
						MurTemp->Display();//TO BE DELETE
						cout << "Mur #" << nbMur << " ajoute" << endl;//TO BE DELETE
					}
					Coor2[0] = Coor1[0];						//Continuation de notre ligne de mur, la permutation du point de tete se fait en coor2 (tail)
					Coor2[1] = Coor1[1];						//le prochain point sera en coor1 (tete)
				}
				else if (lineContents[i] == 'B')				//Verification si dernier point est la balle
				{
					Ball* BalleTemp = new Ball;					//Creation d'un objet Ball
					BalleTemp->Set_xy(Coor1[0], Coor1[1]);		//Son emplacement
					balle1 = BalleTemp->Get();					//Assignation du pointeur de l'objet creer a son attribu balle1
					BalleTemp->Display();//TO BE DELETE
					cout << "Depart de balle a " << BalleTemp->Get() << " ajoute" << endl;//TO BE DELETE
				}
				else if (lineContents[i] == 'T')				//Verification si dernier point est un trou
				{
					Hole* HoleTemp = new Hole;					//Creation objet Hole
					HoleTemp->Set_xy(Coor1[0], Coor1[1]);		//Son emplacement
					hole1 = HoleTemp->Get();					//Assignation du pointeur de l'objet creer a son attribu hole1
					HoleTemp->Display();//TO BE DELETE
					cout << "Le trou est a " << HoleTemp->Get() << " ajoute" << endl;//TO BE DELETE
				}
				else
				{
					ptt += lineContents[i];	//Ajout du caractere en lecture a l'accumulateur
				}
				i++;						//Incrementation de l'index de caractere
			}
			i = 0;							//Nouvelle ligne reset l'incrementeur
			Coor2[0] = -1.0;				//Remet la 2e coor NULL en fin de ligne
		}

		myFile.close();						//Ferme le fichier
		return this;						//Retourne le ponteur du terrain
	}
	cout << "File not found" << endl;
	return nullptr;
}



Parcours Terrain::VerifierColision(Ball* ball , Hole*trou, vector<Mur>* vecteur_mur)
{		/******************* ALI *********************/
/*Ici la fonction t'envoie un objet balle avec lequel tu utilisera ses 
attribus trouver la  colision avec un mur ou un trou du terrain. Prendre 
choisir le plus proche et le fournir à l'objet interaction*/
// Recevoir l'objet ball
	 
	double distance_min = INFINITY;
	int index_collision = -1;
	posX = ball->Get_Ox();
	posY = ball->Get_Oy();
	 
	// Verifier collisions avec les mures 
	for (int i = 0; i < vecteurMur.size(); i++)
	{
		
	
	}

	// Verifier collisions avec trous
	for (int i = 0; i < ; i++) {
		if (distance(ball->Get_Ox(), ball->Get_Oy(), trou->Get_x(), trou->Get_y()) <= 5) {// remplacer 5 par le rayon voulu
			distance_min = 0;
			index_collision = i + nombre_murs_;
			break;
		}
	}

	



	// Retourné:
	// Parcours est un tableau de positions:


	//parcourstotal += parcourssection
	return parcourstotal;
}

double Terrain::GetIntersection(double x1 , double x2 ,double y1 ,double y2,double x3 ,double y3){
/*Fonction qui va venir chercher l instersection */
	double  dx, dy;
	double m1,m2;
	double intersection_X, intersection_Y;
	double c1,c2;

   //  trouver la equation de la droite  droite des mures 
	dx = x2 - x1;
	dy = y2 - y1;
	m1 = dx / dy;
	c1 =  y1 - m1 * x1;
  // trouver l'équation de la droite effectuer par la balle 
	m2 = x3 / y3;
	c2 = y3 - m2 * x3;

	if ((m1 - m2) == 0)
        // les droite sont parallles lorsqu'elles ont les meme pentes
		std::cout << " Aucune intersection entre les lignes\n";
	else

	{
		intersection_X = (c2 - c1) / (m1 - m2); //on vient chercher l'intersection en point x

		intersection_Y = m1 * intersection_X + c1;// on vient cherhcer l intersection en pointy

		std::cout << "le point d intersection = ";

		std::cout << intersection_X;
		std::cout << ",";
		std::cout << intersection_Y;
		std::cout << "\n";
	}

}
double Terrain::distance(double x1, double y1, double x2, double y2) { // on vient chercher  la distance entre deux points
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
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

void Terrain::CoupDonne(Coup *coup1)
{	//La methode retourne l'emplacement de la balle pour chaque intervale de temps donne (a ajuster avec un taux de rafraichissement d'affichage)
	//Elle prendre l'objet COUP l'applique a BALL et valide la colision avec l'un de ses objets (MUR ou TROU)

}
