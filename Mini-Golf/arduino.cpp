/* 
 * Auteurs: Jean-Samuel Lauzon    
 * Date: Fevrier 2022
 * Modif : Janvier 2023, Compatible VisualStudio, JpGouin
*/

/*------------------------------ Librairies ---------------------------------*/
#include <iostream>
#include <string>
using namespace std;

/*-------------------------- Librairies externes ----------------------------*/
#include "include/serial/SerialPort.hpp"
#include "include/json.hpp"
using json = nlohmann::json;

/*------------------------------ Constantes ---------------------------------*/
#define BAUD 9600           // Frequence de transmission serielle
#define MSG_MAX_SIZE 1024   // Longueur maximale d'un message


/*------------------------- Prototypes de fonctions -------------------------*/
bool SendToSerial(SerialPort *arduino, json j_msg);
bool RcvFromSerial(SerialPort *arduino, string &msg);
//bool RCV = true;

/*---------------------------- Variables globales ---------------------------*/
SerialPort * arduino; //doit etre un objet global!

/*----------------------------- Fonction "Main" -----------------------------*/
int communication(int cas, int afficher){
    string raw_msg;
    // Structure de donnees JSON pour envoie et reception
    json j_msg_send, j_msg_rcv;
    // Boucle pour tester la communication bidirectionnelle Arduino-PC
    for(int i=0; i<1; i++){
        // Envoie message Arduino
        json B1;
        json B2;
        json B3;
        json B4;
        json accelero;
        json joystick;
        j_msg_send["send"] = cas;
        j_msg_send["afficher"] = afficher;
        //j_msg_send["RCV"] = RCV;
        if(!SendToSerial(arduino, j_msg_send)){
        cerr << "Erreur lors de l'envoie du message. " << endl;
        }
        // Reception message Arduino
        if (cas==4)
            Sleep(1000);
        else 
            Sleep(50);
        j_msg_rcv.clear(); // effacer le message precedent
        if(!RcvFromSerial(arduino, raw_msg)){
            cerr << "Erreur lors de la reception du message. " << endl;
        }
        cout << raw_msg << endl;
        // Impression du message de l'Arduino si valide
        if(raw_msg.size()>0){
            //cout << "raw_msg: " << raw_msg << endl;  // debug
            // Transfert du message en json
            j_msg_rcv = json::parse(raw_msg);
            switch(cas){
                case 1:
                    B1 = j_msg_rcv["b1"];
                    if (B1==true)
                        return 1;
                    B2 = j_msg_rcv["b2"];
                    if (B2==true)
                        return 2;
                    B3 = j_msg_rcv["b3"];
                    if (B3==true)
                        return 3;
                    B4 = j_msg_rcv["b4"];
                    if (B4==true)
                        return 4;
                case 2:
                    joystick = j_msg_rcv["poty"];
                    return joystick;
                case 3:
                    joystick = j_msg_rcv["potx"];
                    return joystick;
                case 4:
                    if (j_msg_rcv["acc"]>0)
                        accelero = j_msg_rcv["acc"];
                    return accelero;

            }
        }
    }
    return 10;
}
int main(){
    string com = "COM8";
    arduino = new SerialPort(com.c_str(), BAUD);
    //const char com = "\\\\.\\COM3";
    //SerialPort arduino = SerialPort("\\\\.\\COM3");
    if(!arduino->isConnected()){
        cerr << "Impossible de se connecter au port "<< string(com) <<". Fermeture du programme!" <<endl;
        exit(1);
    }
    for (int i=0;i<50;i++){
    int out = communication(3, 6);
    cout << out << endl;
    Sleep(10);
    }
    return 0;
}
/*---------------------------Definition de fonctions ------------------------*/
bool SendToSerial(SerialPort *arduino, json j_msg){
    // Return 0 if error

    string msg = j_msg.dump();
    //cout << msg << endl;
    bool ret = arduino->writeSerialPort(msg.c_str(), msg.length());
    //if(ret)
    //    RCV = false;
    return ret;
}

bool RcvFromSerial(SerialPort *arduino, string &msg){
    // Return 0 if error
    // Message output in msg
    string str_buffer;
    char char_buffer[MSG_MAX_SIZE];
    int buffer_size;

    msg.clear(); // clear string
    // Read serialport until '\n' character (Blocking)

    // Version fonctionnel dans VScode, mais non fonctionnel avec Visual Studio
/*  
    while(msg.back()!='\n'){
        if(msg.size()>MSG_MAX_SIZE){
            return false;
        }

        buffer_size = arduino->readSerialPort(char_buffer, MSG_MAX_SIZE);
        str_buffer.assign(char_buffer, buffer_size);
        msg.append(str_buffer);
    }
*/

    // Version fonctionnelle dans VScode et Visual Studio
    buffer_size = arduino->readSerialPort(char_buffer, MSG_MAX_SIZE);
    str_buffer.assign(char_buffer, buffer_size);
    msg.append(str_buffer);

    //msg.pop_back(); //remove '/n' from string

    return true;
}
