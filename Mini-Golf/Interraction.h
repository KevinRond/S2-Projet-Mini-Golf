#ifndef INTERRACTION_H
#define INTERRACTION_H
/*
La classe int�raction caract�risera une int�raction entre 2 objets
Ex: Ball avec Mur,Trou,Sable,glace
On est dans un monde de mini-put, on peux faire s'quon veux...
*/

class Interraction
{
private:
	double x, y;
	int Degre; //Angle ou direction de l'int�raction
	double module; //distance de l'int�raction 
	double Fac = 1; //Facteur d'influence, peux �tre utilis� pour diminu� ou augment� la vitesse suite � une int�raction
	
public:
	int Interaction(); //lors de sa construction l'objet doit d�termin� sa location X,Y son angle d'incidence et d�terminer un facteur

	double InteractionX(); //Retourne le lieux X de l'int�raction
	double InteractionY(); //Retourne le lieux Y de l'int�raction
	double InteractionAngle(); //Retourne l'angle d'incidence
	double InteractionFac(); //Retourne le facteur d'influence
	double Module(); //Retour la distance en les 2 objets en int�raction
};

#endif