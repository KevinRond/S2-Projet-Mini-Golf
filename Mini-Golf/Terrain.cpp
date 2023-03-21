#include <iostream>
#include <fstream>
#include <string>
#include "Terrain.h"
#include "Parcours.h"
#include <cmath>

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

Parcours Terrain::CoupDonne(Coup* coup1)
{
	int indexColision;															//-1 pour un trou, et le reste pour l'index du mur
	Parcours ParcoursSection;
	balle1->Set_Vxy(coup1->getVitesseX(), coup1->getVitesseY());				//Determine la vitesse de la balle
	balle1->Set_Axy(coup1->getAccelerationX(), coup1->getAccelerationY());		//Determine l'acceleration de la balle
	balle1->Set_direction(coup1->getDirection());							//attribut la direction de balle

	while (balle1->Get_Vx() != 0 && balle1->Get_Vy() != 0 || hole1->Sitrou() == true)
	{
		indexColision = VerifierColision();										//Rapporte l'index de colision
		if (indexColision == -1)												//Si interraction avec un trou (-1)
		{
			ParcoursSection = interraction->BalleTrou(balle1, hole1);							//Retourne le parcours jusqua la prochaine interaction
		}
		else if (indexColision >= 0)											//Si interraction avec un Mur (0 et +)
		{
			ParcoursSection = interraction->BalleMur(balle1, vecteurMur1[indexColision]);		//Retourne le parcours jusqu'a la prochaine interaction
		}
		ParcoursTotal += ParcoursSection;										//Cumule les parcours de section
	}
	return ParcoursTotal;
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
						vecteurMur1.push_back(MurTemp->Get());
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



int Terrain::VerifierColision()
{	//To CHECK utility
	double distance_min = INFINITY;
	int index_collision = -1;
	double posX = balle1->Get_Ox();
	double posY = balle1->Get_Oy();
	double dx = cos(balle1->Get_direction());
	double dy = sin(balle1->Get_direction());
	int trouOuMur;
	double Plusproche = INFINITY;


	double distance;
	double distanceTrou;
	int IndexColision;											//Retourne l'index du mur de 0 à ... et -1 si c'est un trou
	double Mmx, Mb;												//Droite du mur y=mx+b
	double Bmx, Bb;												//Doite de la balle y=mx+b
	double Ox = balle1->Get_Ox();										//Origine de la balle
	double Oy = balle1->Get_Oy();
	double Ix, Iy;											//Point d'intersection
	double Nmx, Nb;												//Pente de la normale
	double Tx = hole1->Get_x();								//Coor du trou
	double Ty = hole1->Get_y();
	for (int i = 0; i < vecteurMur1.size(); i++)				// Verifier collisions avec les mures 
	{																												//Check colision avec Mur
		Mmx = (vecteurMur1[i]->GetHy() - vecteurMur1[i]->GetTy()) / (vecteurMur1[i]->GetHx() - vecteurMur1[i]->GetTx());	//Trouve la pente du mur
		Mb = vecteurMur1[i]->GetHy() / (Mmx * vecteurMur1[i]->GetHx());													//Resout l'equation du mur

		Bmx = asin(balle1->Get_direction());																			//Trouve la pente de balle
		Bb = Oy / (Bmx * Ox);																						//Resout l'equation de balle

		if (Mmx != Bmx)															//Si les droites ne sont pas paralleles
		{
			Ix = (Mb - Bb) / (Bmx - Mmx);										//Resout le point d'intersection
			Iy = Bmx * Ix + Bb;													//Entre la trajectoire de balle et le mur
			if (Ix > Tx && Ix < vecteurMur1[i]->GetHx() && Iy > Ty && Iy < vecteurMur1[i]->GetHy())						//Valide si la colisin s'est fait dans les limites du mur
			{																	//Si oui
				distance = sqrt((Ix - Ox) * (Ix - Ox) + (Iy - Oy) * (Iy - Oy));	//Trouve la distance entre les 2 points
				if (distance < Plusproche)										//Si c'est la distance est plus proche retient l'index
				{
					Plusproche = distance;										//Set le nouveau plus proche
					IndexColision = i;											//Memorise d'index du mur
				}
			}
		}
	}																			//Check colision avec Trou
	Nmx = -1 / Bmx;															//Trouve la pente de la normale
	Nb = Ty - Nmx * Tx;														//Resout l'equation de la normale passant par le trou
	Ix = (Mb - Bb) / (Bmx - Mmx);											//Trouve les coordonnes de l'intersection des 2 droites
	Iy = Bmx * Ix + Bb;
	if (Ox != Ix && Oy != Iy)													//Dans le cas que l'interaction est confirme mais que le trou n'est pas reussi la nouvelle
	{																			//position de balle aura donc la meme que l'interaction calcule precedament
		distanceTrou = sqrt((Ix - Tx) * (Ix - Tx) + (Iy - Ty) * (Iy - Ty));		//Calcul la distance du point d'intersection avec le trou
			if (distanceTrou < hole1->Get_radius())									//Si cette distance est sous le radius du trou il y a collision
			{
				distanceTrou = sqrt((Ix - Ox) * (Ix - Ox) + (Iy - Oy) * (Iy - Oy));	//Calcul la distance de la balle du point d'intersection
					if (distance < Plusproche)										//Si c'est la distance est plus proche change l'index
					{
						Plusproche = distance;										//Set le nouveau plus proche
						IndexColision = -1;											//Definit l'index a Trou
					}
			}
	}
	return IndexColision;
}



	//To CHECK utility
	//Mur* mur = vecteurMur[i];								//creation d'un objet mur, pk?
	//double angleEntreVect = acos((dx * nx + dy * ny) / (sqrt(dx * dx + dy * dy) * sqrt(nx * nx + ny * ny)));		//l'angle d'incidence devrais etre calcule plus tard SI il y a collision dans la classe Interaction
	/*
	if (angleEntreVect < PI / 2)							//verif si le mur est dans la direction de la balle
	{	
		double vx = mur->GetHx() - balle1->Get_Ox();			//distance entre la balle et le mur
		double vy = mur->GetHy() - balle1->Get_Oy();
		distance = (vx * dx + vy * dy) / sqrt(dx * dx + dy * dy);

		if (distance < distance_min)
		{
			index_collision = i;
			distance_min = distance;
			trouOuMur = 0;
		}
	}																								//verifier si le trou est le plus proche de la balle
	double anglerad = ball->Get_direction() * PI / 180.0;												//angle en radian
	distance = sqrt(pow(trou->Get_x() - ball->Get_Ox(), 2) + pow(trou->Get_y() - ball->Get_Oy(), 2));	//distance entre ball et troue

	double angleToHole = atan2(trou->Get_y() - ball->Get_Oy(), trou->Get_x() - ball->Get_Ox());

	double anglediff = abs(anglerad - angleToHole);														//difference d'angle

	if (anglediff <= PI / 180.0)
	{
		if (distance < distance_min)
		{
			distance_min = distance;
			trouOuMur = 1;
		}
	}														//verifier c quoi qu'on envoie
	if (trouOuMur == 0)										// si cest un mur qui est le plus proche
	{

	}
	else													// si cest un trou
	{

	}

	*/
	// Verifier collisions avec trous
	/*for (int i = 0; i <; i++) {
		if (distance(ball->Get_Ox(), ball->Get_Oy(), trou->Get_x(), trou->Get_y()) <= 5) {// remplacer 5 par le rayon voulu
			distance_min = 0;
			//index_collision = i + nombre_murs_;
			break;
		}
	}*/

	// Retourne:
	// Parcours est un tableau de positions:


	//parcourstotal += parcourssection
//}
/*
double Terrain::GetIntersection(double x1 , double x2 ,double y1 ,double y2,double x3 ,double y3){
	double  dx, dy;													//Fonction qui va venir chercher l instersection
	double m1,m2;
	double intersection_X, intersection_Y;
	double c1,c2;
	dx = x2 - x1;													//trouver la equation de la droite  droite des mures 
	dy = y2 - y1;
	m1 = dx / dy;
	c1 =  y1 - m1 * x1;
	m2 = x3 / y3;													// trouver l'equation de la droite effectuer par la balle 
	c2 = y3 - m2 * x3;

	if ((m1 - m2) == 0)
	{																// les droite sont parallles lorsqu'elles ont les meme pentes
		std::cout << " Aucune intersection entre les lignes\n";
	}
	else
	{
		intersection_X = (c2 - c1) / (m1 - m2);						//on vient chercher l'intersection en point x
		intersection_Y = m1 * intersection_X + c1;					// on vient cherhcer l intersection en pointy
		std::cout << "le point d intersection = ";
		std::cout << intersection_X;
		std::cout << ",";
		std::cout << intersection_Y;
		std::cout << "\n";
	}

}*/
double Terrain::distance(double x1, double y1, double x2, double y2)
{
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));					// on vient chercher la distance entre deux points
}

void Terrain::Display()
{
	for (int i = 0; i < vecteurMur1.size(); i++) {
		cout << "Mur # " << i+1 << "/" << nbMur << endl;
		vecteurMur1[i]->Display();
	}
	balle1->Display();
	hole1->Display();
}

void Terrain::testParcours()
{
	Parcours Complet, segment1, segment2;		//EXEMPLE : Creation de 3 parcours
					
	for (int i = 0;i < 100;i++)					//Load them with dummy values
	{
		segment1.addCoor(i, 100 - i);
	}				

	for (int i = 0;i < 75;i++)
	{
		segment2.addCoor(i + 75, 75 - i);
	}


	Complet += segment1;
	Complet += segment2;
	Complet.Display();

}
