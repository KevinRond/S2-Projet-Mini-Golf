#ifndef INTERRACTION_Hhttps://app.diagrams.net/
#define INTERRACTION_H
/*
La classe int�raction caract�risera une int�raction entre 2 objets
Ex: Ball avec Mur,Trou,Sable,glace
On est dans un monde de mini-put, on peux faire s'quon veux...
*/

class Interraction
{
private:
	float x, y;
	int Degre; //Angle d'int�raction
	float Module //distance de l'int�raction 
	float Fac = 1; //Facteur d'influence, peux �tre utilis� pour diminu� ou augment� la vitesse suite � une int�raction
	
public:
	Interaction(); //lors de sa construction l'objet doit d�termin� sa location X,Y son angle d'incidence et d�terminer un facteur

	float InteractionX(); //Retourne le lieux X de l'int�raction
	float InteractionY(); //Retourne le lieux Y de l'int�raction
	float InteractionAngle(); //Retourne l'angle d'incidence
	float InteractionFac(); //Retourne le facteur d'influence
	float Module(); //Retour la distance en les 2 objets en int�raction
};

#endif