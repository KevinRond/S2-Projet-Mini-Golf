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
private:			//[0]=X [1]=Y
	double xy[2];	//Position actuel
	double Oxy[2];  //Position d'origine
	double Vxy[2];	//Velocite
	double Axy[2];	//acceleration


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
	double Get_xy();	//Set la position actuel
	double Get_Oxy();	//Set la position d'origine
	double Get_Vxy();	//Set la velocite
	double Get_Axy();	//Set l'acceleration

	//Affichage
	void Display();
};
#endif