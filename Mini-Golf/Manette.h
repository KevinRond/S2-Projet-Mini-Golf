#ifndef MANETTE_H
#define MANETTE_H
#include <iostream>
#include <string>
#include <thread>
using namespace std;

/*-------------------------- Librairies externes ----------------------------*/
#include "include/serial/SerialPort.hpp"
#include "include/json.hpp"
using json = nlohmann::json;

/*------------------------------ Constantes ---------------------------------*/
#define BAUD 9600           // Frequence de transmission serielle
#define MSG_MAX_SIZE 1024   // Longueur maximale d'un message

/*---------------------------- Variables globales ---------------------------*/
SerialPort * arduino; //doit etre un objet global!

/*----------------------------- Fonction "Main" -----------------------------*/
int communication();
void setup();
bool SendToSerial(SerialPort *arduino, json j_msg);
bool RcvFromSerial(SerialPort *arduino, string &msg);
#endif