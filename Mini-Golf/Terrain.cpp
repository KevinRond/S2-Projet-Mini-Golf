#include <iostream>
#include <fstream>
#include <string>
#include "Terrain.h"
#include "Parcours.h"
#include <cmath>
#include "Interraction.h"


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
}

Terrain::~Terrain()
{
}

Parcours Terrain::CoupDonne(Coup coup1)
{
	int indexColision = -2;																		//-1 pour un trou, et le reste pour l'index du mur
	Parcours ParcoursSection;
	Interraction Interaction1;
	balle1->Set_Vxy(coup1.getVitesseX(), coup1.getVitesseY());								//Determine la vitesse de la balle
	balle1->Set_Axy(coup1.getAccelerationX(), coup1.getAccelerationY());					//Determine l'acceleration de la balle
	balle1->Set_direction(coup1.getDirection());												//attribut la direction de balle
	
	while ((balle1->Get_Vx() != 0 && balle1->Get_Vy() != 0) || hole1->Sitrou() == true)
	{
		indexColision = VerifierColision();													//Rapporte l'index de colision
		if (indexColision == -1)															//Si interraction avec un trou (-1)
		{
			ParcoursSection = Interaction1.BalleTrou(balle1, hole1);						//Retourne le parcours jusqua la prochaine interaction
		}
		else if (indexColision >= 0)														//Si interraction avec un Mur (0 et +)
		{
			ParcoursSection = Interaction1.BalleMur(balle1, vecteurMur1.at(indexColision));	//Retourne le parcours jusqu'a la prochaine interaction
		}
		ParcoursTotal += ParcoursSection;													//Cumule les parcours de section
		cout << balle1->Get_Vx() << "  " << balle1->Get_Vy() << endl;
		
	}
	return ParcoursTotal;
}


Terrain *Terrain::OpenTerrain(std::string  terrain)
{
	ifstream myFile;								//Creation de l'objet fichier
	myFile.open(terrain, ios_base::in);		//ouveture du fichier
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
						vecteurMur1.push_back(MurTemp->Get());					//Assignation au TableauMur de notre terrain
						nbMur++;												//Incremenation du nombre de Murs
					}
					Coor2[0] = Coor1[0];						//Continuation de notre ligne de mur, la permutation du point de tete se fait en coor2 (tail)
					Coor2[1] = Coor1[1];						//le prochain point sera en coor1 (tete)
				}
				else if (lineContents[i] == 'B')				//Verification si dernier point est la balle
				{
					Ball* BalleTemp = new Ball;					//Creation d'un objet Ball
					BalleTemp->Set_Oxy(Coor1[0], Coor1[1]);		//Son emplacement
					balle1 = BalleTemp->Get();					//Assignation du pointeur de l'objet creer a son attribu balle1
				}
				else if (lineContents[i] == 'T')				//Verification si dernier point est un trou
				{
					Hole* HoleTemp = new Hole;					//Creation objet Hole
					HoleTemp->Set_xy(Coor1[0], Coor1[1]);		//Son emplacement
					hole1 = HoleTemp->Get();					//Assignation du pointeur de l'objet creer a son attribu hole1
				}
				else if (lineContents[i] == 'S')
				{
					K = 0.75;									//Terrain de Sable
				}
				else if (lineContents[i] == 'G')
				{
					K = 1.5;									//Terrain de Glace
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
{
	double distance;
	double distanceTrou;
	double Plusproche = INFINITY;
	int IndexColision = -2;										//Retourne l'index du mur de 0 a... et -1 si c'est un trou
	double Mmx, Mb;												//Droite du mur y=mx+b
	double Bmx, Bb;												//Doite de la balle y=mx+b
	double Ox = balle1->Get_Ox();								//Origine de la balle
	double Oy = balle1->Get_Oy();
	double Ix, Iy;												//Point d'intersection
	double Nmx, Nb;												//Pente de la normale
	double TrouX = hole1->Get_x();								//Coor du trou
	double TrouY = hole1->Get_y();
	double Hx, Hy, Tx, Ty;										//coor d'un mur
	std::vector<Mur>::iterator it;
	int i = 0;
	for (auto it = vecteurMur1.begin();it != vecteurMur1.end(); ++it)	// Verifier collisions avec les mures 
	{
		Hy = (*it)->GetHy();											//coor d'un mur
		Ty = (*it)->GetTy();
		Hx = (*it)->GetHx();
		Tx = (*it)->GetTx();											//Check colision avec Mur
		Mmx = (Hy - Ty) / (Hx - Tx);									//Trouve la pente du mur
		Mb = Hy - Mmx * Hx;												//Resout l'equation du mur
		Bmx = tan(balle1->Get_direction());								//Trouve la pente de balle
		Bb = Oy - Bmx * Ox;												//Resout l'equation de balle

		if (abs(Mmx) > 1000000 && abs(Bmx) > 1000000 || Mmx == 0 && Bmx == 0)		//ligne parallele
		{
			Ix = INFINITY;
			Iy = INFINITY;
			Mb = 0;
			Ix = Hx;
			Iy = Bmx * Ix + Bb;
			Bb = 0;
			Ix = Ox;
			Iy = Mmx * Ix + Mb;
		}
		else if (abs(Mmx) >1000000)													//Si les droites ne sont pas paralleles
		{
			Mb = 0;
			Ix = Hx;
			Iy = Bmx * Ix + Bb;
		}
		else if (abs(Bmx) >1000000)
		{
			Bb = 0;
			Ix = Ox;
			Iy = Mmx * Ix + Mb;
		}
		else if (Mmx != Bmx)
		{
			Ix = (Mb - Bb) / (Bmx - Mmx);											//Resout le point d'intersection
			Iy = Mmx * Ix + Mb;														//Entre la trajectoire de balle et le mur
		}
		else
		{
			Ix = INFINITY;
			Iy = INFINITY;
		}
		if (balle1->Get_direction() < 3.14159265358979323846 / 2 || balle1->Get_direction() > 3.14159265358979323846 * 1.5)			//Verifie si l'interaction occur dans les cadrants de droite
		{
			if (Ix < Ox) {
				Ix = INFINITY;
			}
		}
		else if (balle1->Get_direction() > 3.14159265358979323846/2 && balle1->Get_direction() < 3.14159265358979323846 * 1.5)		//Verifie si l'interaction occur dans les cadrants de gauche
		{
			if (Ix > Ox) {
				Ix = INFINITY;
			}
		}
		if (balle1->Get_direction() > 0 && balle1->Get_direction() < 3.14159265358979323846)			//Verifie si l'interaction occur dans les cadrants du haut
		{
			if (Iy < Oy) {
				Iy = INFINITY;
			}
		}
		else if (balle1->Get_direction() > 3.14159265358979323846)		//Verifie si l'interaction occur dans les cadrants du bas
		{
			if (Iy < Oy) {
				Iy = INFINITY;
			}
		}
		if (isBetween(Ix, Hx, Tx) && isBetween(Iy, Hy, Ty))							//Valide si la colisin s'est fait dans les limites du mur
		{																			//Si oui
			distance = sqrt(pow((Ix - Ox), 2) + pow((Iy - Oy), 2));					//Trouve la distance entre les 2 points
			if (distance < Plusproche)												//Si c'est la distance est plus proche retient l'index
			{
				Plusproche = distance;												//Set le nouveau plus proche
				IndexColision = i;													//Memorise d'index du mur
				//cout << "colision avec l'objet " << IndexColision << " a la coor (" << round(Ix) << "," << round(Iy) << ")" << " a une distance de " << round(distance) << endl;
			}
		}
		i++;
	}																					//Check colision avec Trou
	Nmx = -1 / Bmx;																		//Trouve la pente de la normale
	Nb = TrouY - Nmx * TrouX;															//Resout l'equation de la normale passant par le trou
	Ix = (Nb - Bb) / (Bmx - Nmx);														//Trouve les coordonnes de l'intersection des 2 droites
	Iy = Bmx * Ix + Bb;
	if (isOnLine(TrouX, TrouY, Bmx, Bb))
	{
		Ix = TrouX;
		Iy = TrouY;
	}

	if (balle1->Get_direction() < 3.14159265358979323846 / 2 || balle1->Get_direction() > 3.14159265358979323846 * 1.5)			//Verifie si l'interaction occur dans les cadrants de droite
	{
		if (Ix < Ox) {
			Ix = INFINITY;
		}
	}
	else if (balle1->Get_direction() > 3.14159265358979323846 / 2 && balle1->Get_direction() < 3.14159265358979323846 * 1.5)		//Verifie si l'interaction occur dans les cadrants de gauche
	{
		if (Ix > Ox) {
			Ix = INFINITY;
		}
	}
	if (balle1->Get_direction() > 0 && balle1->Get_direction() < 3.14159265358979323846)			//Verifie si l'interaction occur dans les cadrants du haut
	{
		if (Iy < Oy) {
			Iy = INFINITY;
		}
	}
	else if (balle1->Get_direction() > 3.14159265358979323846)		//Verifie si l'interaction occur dans les cadrants du bas
	{
		if (Iy < Oy) {
			Iy = INFINITY;
		}
	}
	if (Ox != Ix && Oy != Iy)															//Dans le cas que l'interaction est confirme mais que le trou n'est pas reussi la nouvelle
	{																					//position de balle aura donc la meme que l'interaction calcule precedament
		distanceTrou = sqrt(pow((Ix - TrouX),2) + pow((Iy - TrouY),2));	//Calcul la distance du point d'intersection avec le trou
		if (distanceTrou < hole1->Get_radius())											//Si cette distance est sous le radius du trou il y a collision
		{
			distanceTrou = sqrt((Ix - Ox) * (Ix - Ox) + (Iy - Oy) * (Iy - Oy));			//Calcul la distance de la balle du point d'intersection
			if (distanceTrou < Plusproche)													//Si c'est la distance est plus proche change l'index
			{
				IndexColision = -1;														//Definit l'index a Trou
				//cout << "colision avec l'objet " << IndexColision << " a la coor (" << round(Ix) << "," << round(Iy) << ")" << endl;
			}
		}
	}
	cout << IndexColision << endl;
	return IndexColision;
}

void Terrain::Display()
{
	balle1->Display();
	hole1->Display();
	std::vector<Mur>::iterator it;
	for (auto it = vecteurMur1.begin();it != vecteurMur1.end(); ++it)
	{
		(*it)->Display();
	}
}

bool Terrain::isBetween(double value, double bound1, double bound2)
{
	double lower = std::min(bound1, bound2);
	double upper = std::max(bound1, bound2);
	return value >= lower && value <= upper;
}
bool Terrain::isOnLine(double x0, double y0, double m, double b) {
	double y = m * x0 + b;
	return y == y0;
}