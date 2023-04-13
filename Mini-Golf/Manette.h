
#ifndef MANETTE_H
#define MANETTE_H
#include <iostream>
#include <string>
#include <thread>
#include <atomic>
#include "Coup.h"


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
	Manette(std::string comport);
	~Manette();
	int communication();
	void demande(int NewCas, int NewAfficher);
	void setup(std::string usbport);
	bool SendToSerial(SerialPort* arduino, json j_msg);
	bool RcvFromSerial(SerialPort* arduino, std::string& msg);

	int getCas();
	void setBouton();
	int getAfficher();
	int getAmplitude();
	bool getButton1();
	bool getButton2();
	bool getButton3();
	bool getButton4();
	double getJoyX();
	double getJoyY();
	int getMumu();
	double GetDirectionElec(class Coup* coup);
	double GetPuissanceElec(Coup* coup);
	double getMumu(Coup* coup);
	void SequenceCoup(Coup* coup);
	void setCas(int nouveauCas);
	void setAfficher(int nouvelAffichage);
	//void startThread();
	friend std::ostream& operator << (std::ostream& o, const Manette& m)
	{
		o << "Valeur Mesuree [" << m.amplitude << "," << m.joyX << "," << m.joyY << "]";
		return o;
	}

	int cas, afficher, amplitude, mumu;
	double joyX, joyY;
	bool button1, button2, button3, button4;
};
#endif
