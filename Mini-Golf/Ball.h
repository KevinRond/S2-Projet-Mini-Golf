#ifndef BALL_H
#define BALL_H
#include <iostream>
#include <string>
#include <math.h>
/*
La classe ball comporte les caracteristiques physiques suivantes:
Une position d'origine (Oxy)
Une velocitee (amplitude)
*/


class Ball
{
private:
	double Ox, Oy;		//Position d'origine
	double direction;	//direction de la balle
	double amplitude;	//velocite XY combinee (in miles per hours)
	double rayon;		//rayon de la balle
	double K;					//Facteur de friction	

public:
	Ball();								//Constructeur blank
	Ball(double posX, double posY);		//Constructeur avec parametre de position initiale (utilise lors du setup de terrain)
	~Ball();							//Destructeur
	Ball* Get();						//Retour le pointeur de la balle

	//Setter
	void Set_Oxy(double posX, double posY);	//Set la position d'origine
	void Set_Direction(double newdirection);
	void Set_Amplitude(double amp);
	void Set_K(double k);

	//Getter
	std::pair<int, int> QuelCadrant();
	double Get_Ox();		//Set la position d'origine X
	double Get_Oy();		//Set la position d'origine Y
	double Get_Direction();	//Retourne la direction en RADIAN
	double Get_rayon();
	double Get_Amplitude();
	double Get_K();

	//Affichage
	void Display();
};
#endif