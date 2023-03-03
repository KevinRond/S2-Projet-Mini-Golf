#ifndef INTERRACTION_H
#define INTERRACTION_H
/*
La classe intéraction caractérisera une intéraction entre 2 objets
Ex: Ball avec Mur,Trou,Sable,glace
On est dans un monde de mini-put, on peux faire s'quon veux...
*/

class Interraction
{
private:
	double x, y;
	int Degre; //Angle ou direction de l'intéraction
	double module; //distance de l'intéraction 
	double Fac = 1; //Facteur d'influence, peux être utilisé pour diminué ou augmenté la vitesse suite à une intéraction
	
public:
	Interraction(); //lors de sa construction l'objet doit déterminé sa location X,Y son angle d'incidence et déterminer un facteur
	~Interraction();
	double InterractionX(); //Retourne le lieux X de l'intéraction
	double InterractionY(); //Retourne le lieux Y de l'intéraction
	double InterractionAngle(); //Retourne l'angle d'incidence
	double InterractionFac(); //Retourne le facteur d'influence
	double Module(); //Retour la distance en les 2 objets en intéraction
};

#endif
