#ifndef INTERRACTION_H
#define INTERRACTION_H
/*
La classe interaction caracterisera une interaction entre 2 objets
Ex: Ball avec Mur,Trou,Sable,glace
On est dans un monde de mini-put, on peux faire s'quon veux...
*/

class Interraction
{
private:
	double x, y;
	int Degre; //Angle ou direction de l'interaction
	double module; //distance de l'interaction 
	double Fac = 1; //Facteur d'influence, peux etre utilise pour diminue ou augmente la vitesse suite a une interaction
	
public:
	Interraction(); //lors de sa construction l'objet doit determine sa location X,Y son angle d'incidence et determiner un facteur
	~Interraction();
	double InterractionX(); //Retourne le lieux X de l'interaction
	double InterractionY(); //Retourne le lieux Y de l'interaction
	double InterractionAngle(); //Retourne l'angle d'incidence
	double InterractionFac(); //Retourne le facteur d'influence
	double Module(); //Retour la distance en les 2 objets en interaction
};

#endif
