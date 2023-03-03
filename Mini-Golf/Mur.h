#ifndef MUR_H
#define MUR_H


class Mur
{
private:
	double* points = new double[4];

public:
	Mur();
	Mur(double AX, double AY, double BX, double BY);
	void Set(double AX, double AY, double BX, double BY);
	~Mur();
	//Interraction *VerrifierColision(Ball balle); //Recoit l'objet ball et d�termine s'il y a une int�raction si non retour nul
	Mur* Get();
	void Display();
};

#endif