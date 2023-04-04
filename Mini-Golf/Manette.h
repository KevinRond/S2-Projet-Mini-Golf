#pragma once
#ifndef MANETTE_H
#define MANETTE_H
#include <iostream>
#include <string>
#include <thread>
#include <atomic>

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
	atomic<bool> s_finished;
	std::thread communicationThread;
	int _cas, _afficher, _amplitude, _joyY, _joyX;

public:
	Manette(string comport);
	~Manette();
	void communication();
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

	void setCas(int nouveauCas);
	void setAfficher(int nouvelAffichage);
	//void startThread();
	friend ostream& operator << (ostream& o,  const Manette& m)
	{
		o << "Valeur Mesuree [" << m.amplitude << "," << m.joyX << "," << m.joyY << "]";
		return o;
	}

	atomic<int> cas, afficher, amplitude, joyY, joyX;
	atomic<bool> button1, button2, button3, button4;
};
#endif