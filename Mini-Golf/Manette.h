#pragma once
#ifndef MANETTE_H
#define MANETTE_H
#include <iostream>
#include <string>
#include <thread>
#include <atomic>
#include "Coup.h"


using namespace std;



/*-------------------------- Librairies externes ----------------------------*/
#include "include/serial/SerialPort.hpp"
#include "include/json.hpp"
using json = nlohmann::json;

/*------------------------------ Constantes ---------------------------------*/
#define BAUD 9600           // Frequence de transmission serielle
#define MSG_MAX_SIZE 1024   // Longueur maximale d'un message

/*---------------------------- Variables globales ---------------------------*/
//extern SerialPort* arduino; //doit etre un objet global!
//bool mutex = 0;
/*------------------------------ Constantes ---------------------------------*/
//extern int cas, afficher;
/*----------------------------- Fonction "Main" -----------------------------*/

class Manette {
private:
	SerialPort* arduino;
	bool s_finished;
	std::thread communicationThread;

public:
	Manette(string comport);
	~Manette();
	int communication();
	void demande(int NewCas, int NewAfficher);
	void setup(string usbport);
	bool SendToSerial(SerialPort* arduino, json j_msg);
	bool RcvFromSerial(SerialPort* arduino, string& msg);

	int getCas();
	int getAfficher();
	int getAmplitude();
	bool getButton1();
	bool getButton2();
	bool getButton3();
	bool getButton4();
	int getJoyX();
	int getJoyY();
	int getMumu();
	double GetDirectionElec(class Coup);
	double GetPuissanceElec(class Coup);
	double getMumu(class Coup);
	void SequenceCoup(class Coup);
	void setCas(int nouveauCas);
	void setAfficher(int nouvelAffichage);
	//void startThread();
	friend ostream& operator << (ostream& o,  const Manette& m)
	{
		o << "Valeur Mesuree [" << m.amplitude << "," << m.joyX << "," << m.joyY << "]";
		return o;
	}

	int cas, afficher, amplitude, joyY, joyX, mumu;
	bool button1, button2, button3, button4;
};
#endif