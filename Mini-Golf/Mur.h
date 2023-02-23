#ifndef MUR_H
#define MUR_H
#include "Terrain.h"
#include "Ball.h"
class Mur
{
private:
	float Mur[]; //0:x, 1:y, 2:b, 3:dX, 4:fX, 5:dY, 6:fY
				 //0,1,2`: Y=X+b   avec 3,4 début fin de sa composante X et 5,6 de sa composante Y
public:

	Interraction VerrifierColision(Ball ball) //Recoit l'objet ball et détermine s'il y a une intéraction si non retour nul
};

#endif