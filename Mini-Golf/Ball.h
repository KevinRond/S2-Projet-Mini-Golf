#ifndef BALL_H
#define BALL_H
#include <iostream>
#include <string>
/*
La classe ball comporte les caracteristiques physiques suivantes:
Une position actuel (xy) et d'origine (Oxy)
Une velocitee (Vxy)
Une acceleration (Axy)
*/


class Ball
{
private:
	double x, y;	//Position actuel
	double Ox, Oy;  //Position d'origine
	double Vx, Vy;	//Velocite
	double Ax, Ay;	//acceleration


public:
	Ball();								//Constructeur blank
	Ball(double posX, double posY);		//Constructeur avec parametre de position initiale (utilise lors du setup de terrain)
	~Ball();							//Destructeur
	Ball* Get();						//Retour le pointeur de la balle

	//Setter
	void Set_xy(double posX, double posY);	//Set la position actuel
	void Set_Oxy(double posX, double posY);	//Set la position d'origine
	void Set_Vxy(double posX, double posY);	//Set la velocite
	void Set_Axy(double posX, double posY);	//Set l'acceleration

	//Getter
	double Get_x();		//Set la position actuel X
	double Get_y();		//Set la position actuel Y
	double Get_Ox();	//Set la position d'origine X
	double Get_Oy();	//Set la position d'origine Y
	double Get_Vx();	//Set la velocite X
	double Get_Vy();	//Set la velocite Y
	double Get_Ax();	//Set l'acceleration X
	double Get_Ay();	//Set l'acceleration Y

	//Affichage
	void Display();
};
#endif