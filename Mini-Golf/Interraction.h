#ifndef INTERRACTION_Hhttps://app.diagrams.net/
#define INTERRACTION_H
/*
La classe intéraction caractérisera une intéraction entre 2 objets
Ex: Ball avec Mur,Trou,Sable,glace
On est dans un monde de mini-put, on peux faire s'quon veux...
*/

class Interraction
{
private:
	float x, y;
	int Degre; //Angle d'intéraction
	float Module //distance de l'intéraction 
	float Fac = 1; //Facteur d'influence, peux être utilisé pour diminué ou augmenté la vitesse suite à une intéraction
	
public:
	Interaction(); //lors de sa construction l'objet doit déterminé sa location X,Y son angle d'incidence et déterminer un facteur

	float InteractionX(); //Retourne le lieux X de l'intéraction
	float InteractionY(); //Retourne le lieux Y de l'intéraction
	float InteractionAngle(); //Retourne l'angle d'incidence
	float InteractionFac(); //Retourne le facteur d'influence
	float Module(); //Retour la distance en les 2 objets en intéraction
};

#endif