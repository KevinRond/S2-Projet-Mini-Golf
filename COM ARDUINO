/*------------------------------ Librairies ---------------------------------*/
#include <Arduino.h>
#include <ArduinoJson.h>

/*------------------------------ Constantes ---------------------------------*/

#define BAUD 9600        // Frequence de transmission serielle

/*---------------------------- Variables globales ---------------------------*/

volatile bool shouldSend_ = false;  // Drapeau prêt à envoyer un message
volatile bool shouldRead_ = false;  // Drapeau prêt à lire un message

int potJoyY = 0;
int potJoyX = 0;
int potjoy = 0;
int seg1State = 1;
int seg2State = 1;
int seg3State = 1;
int seg4State = 1;
int seg5State = 1;
int seg6State = 1;
int seg7State = 1;
int Xvalue = 0;
int Yvalue = 0;
int Zvalue = 0;
bool Boutstate1 = 0;
bool Boutstate2 = 0;
bool Boutstate3 = 0;
bool Boutstate4 = 0;
int pinBOUT1 = 22;
int pinBOUT2 = 24;
int pinBOUT3 = 26;
int pinBOUT4 = 28;
int pinseg1 = 23;
int pinseg2 = 25;
int pinseg3 = 27;
int pinseg4 = 29;
int pinseg5 = 31;
int pinseg6 = 33;
int pinseg7 = 35;
int pinX = A11;
int pinY = A12;
int pinZ = A13;
int pinJoyY = A15;
int pinJoyX = A14;


/*------------------------- Prototypes de fonctions -------------------------*/
void sendMsg(); 
void readMsg();
void serialEvent();
/*---------------------------- Fonctions "Main" -----------------------------*/

void setup() {
  Serial.begin(BAUD);               // Initialisation de la communication serielle
  pinMode(pinseg1, OUTPUT);
  pinMode(pinseg2, OUTPUT);
  pinMode(pinseg3, OUTPUT);
  pinMode(pinseg4, OUTPUT);
  pinMode(pinseg5, OUTPUT);
  pinMode(pinseg6, OUTPUT);
  pinMode(pinseg7, OUTPUT);
  pinMode(pinBOUT1, INPUT);
  pinMode(pinBOUT2, INPUT);
  pinMode(pinBOUT3, INPUT);
  pinMode(pinBOUT4, INPUT);
}
int joystick(){
  if (analogRead(pinX) < 800 && analogRead(pinX) > 200){
    if (analogRead(pinY) < 200){
      potjoy = 1;
      Serial.println(potjoy);}
    else if (analogRead(pinY) > 800)
      potjoy = 2;
  }
  else if (analogRead(pinY) < 800 && analogRead(pinY) > 200){
    if (analogRead(pinX) < 200)
      potjoy = 3;
    else if (analogRead(pinX) > 800)
      potjoy = 4;
  }
  return potjoy;
}
void bouton(){
  if (digitalRead(pinBOUT1)){
    Boutstate1 = true;
  }
  else{ 
    Boutstate1 = false;
  }
  if (digitalRead(pinBOUT2)){
    Boutstate2 = true;
  }
  else{ 
    Boutstate2 = false;
  }
  if (digitalRead(pinBOUT3)){
    Boutstate3 = true;
  }
  else{ 
    Boutstate3 = false;
  }
  if (digitalRead(pinBOUT4)){
    Boutstate4 = true;
  }
  else{ 
    Boutstate4 = false;
  }
}
/* Boucle principale (infinie) */
void loop() {

  if(shouldRead_){
    readMsg();
    sendMsg();
  }
  potjoy = joystick();
  Xvalue = analogRead(pinX);
  Yvalue = analogRead(pinY);
  Zvalue = analogRead(pinZ);
  bouton();
  digitalWrite(pinseg1, seg1State);
  digitalWrite(pinseg2, seg2State);
  digitalWrite(pinseg3, seg3State);
  digitalWrite(pinseg4, seg4State);
  digitalWrite(pinseg5, seg5State);
  digitalWrite(pinseg6, seg6State);
  digitalWrite(pinseg7, seg7State);
  //Serial.println(potValue);          // debug
  delay(10);  // delais de 10 ms
}

/*---------------------------Definition de fonctions ------------------------*/

void serialEvent() { shouldRead_ = true; }


/*---------------------------Definition de fonctions ------------------------
Fonction d'envoi
Entrée : Aucun
Sortie : Aucun
Traitement : Envoi du message
-----------------------------------------------------------------------------*/
void afficher(int x){
  if (x == 8){
    seg1State = 0;
    seg2State = 0;
    seg3State = 0;
    seg4State = 0;
    seg5State = 0;
    seg6State = 0;
    seg7State = 0;
  }
  else if (x == 7){
    seg1State = 0;
    seg2State = 0;
    seg3State = 0;
    seg4State = 1;
    seg5State = 1;
    seg6State = 1;
    seg7State = 1;

  }
  else if (x == 6){
    seg1State = 0;
    seg2State = 1;
    seg3State = 0;
    seg4State = 0;
    seg5State = 0;
    seg6State = 0;
    seg7State = 0;
  }
  else if (x == 5){
    seg1State = 0;
    seg2State = 1;
    seg3State = 0;
    seg4State = 1;
    seg5State = 0;
    seg6State = 0;
    seg7State = 0;
  }
  else if (x == 4){
    seg1State = 1;
    seg2State = 0;
    seg3State = 0;
    seg4State = 1;
    seg5State = 1;
    seg6State = 0;
    seg7State = 0;
  }
  else if (x == 3){
    seg1State = 0;
    seg2State = 0;
    seg3State = 0;
    seg4State = 0;
    seg5State = 1;
    seg6State = 1;
    seg7State = 0;
  }
  else if (x == 2){
    seg1State = 0;
    seg2State = 0;
    seg3State = 1;
    seg4State = 0;
    seg5State = 0;
    seg6State = 1;
    seg7State = 0;
  }
  else if (x == 1){
    seg1State = 1;
    seg2State = 0;
    seg3State = 0;
    seg4State = 1;
    seg5State = 1;
    seg6State = 1;
    seg7State = 1;
  }
  else if (x == 0){
    seg1State = 0;
    seg2State = 0;
    seg3State = 0;
    seg4State = 0;
    seg5State = 0;
    seg6State = 0;
    seg7State = 1;
  }

}
void sendMsg() {
  StaticJsonDocument<500> doc;
  // Elements du message
  doc["time"] = millis();
  doc["Joy"] = potjoy;
  doc["bouton1"] = Boutstate1;
  doc["bouton2"] = Boutstate2;
  doc["x"] = Xvalue;
  doc["y"] = Yvalue;
  doc["z"] = Zvalue;
  // Serialisation
  serializeJson(doc, Serial);

  // Envoie
  Serial.println();
  shouldSend_ = false;
}

/*---------------------------Definition de fonctions ------------------------
Fonction de reception
Entrée : Aucun
Sortie : Aucun
Traitement : Réception du message
-----------------------------------------------------------------------------*/
void readMsg(){
  // Lecture du message Json
  StaticJsonDocument<500> doc;
  JsonVariant parse_msg;

  // Lecture sur le port Seriel
  DeserializationError error = deserializeJson(doc, Serial);
  shouldRead_ = false;

  // Si erreur dans le message
  if (error) {
    Serial.print("deserialize() failed: ");
    Serial.println(error.c_str());
    return;
  }
  
  // Analyse des éléments du message message
  parse_msg = doc["AFFICHER"];
  afficher(parse_msg);
}
