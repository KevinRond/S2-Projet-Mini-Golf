#ifndef MUR_H
#define MUR_H
#include "Terrain.h"
#include "Ball.h"
#include "Interraction.h"
using namespace std;
class Mur
{
private:
	double pointsA[2];
	double pointsB[2];
public:
	Mur(double AX, double AY, double BX, double BY);
	~Mur();
	Interraction VerrifierColision(Ball ball); //Recoit l'objet ball et détermine s'il y a une intéraction si non retour nul
	Mur* Get();
	void Display();
};

#endif