#include "Manette.h"


/*------------------------------ Constantes ---------------------------------*/
//int cas, afficher;

Manette::Manette(string comport)
{
    //cout << "nouvelle manette" << endl;
    setup(comport);
}

Manette::~Manette()
{
    delete arduino;
}

/*----------------------------- Fonction "Main" -----------------------------*/
int Manette::communication() {
    string raw_msg;
    // Structure de donnees JSON pour envoie et reception
    json j_msg_send, j_msg_rcv;
    // Boucle pour tester la communication bidirectionnelle Arduino-PC
        for (int i = 0; i < 1; i++) {
            // Envoie message Arduino
            json mumuJson;
            json B1;
            json B2;
            json B3;
            json B4;
            json accelero;
            json joystick;
            j_msg_send["send"] = cas;
            j_msg_send["afficher"] = afficher;
            //j_msg_send["RCV"] = RCV;
            if (!SendToSerial(arduino, j_msg_send)) {
                cerr << "Erreur lors de l'envoie du message. " << endl;
            }
            // Reception message Arduino
            if (cas == 3)
                Sleep(1000);
            else
                Sleep(50);
            j_msg_rcv.clear(); // effacer le message precedent
            if (!RcvFromSerial(arduino, raw_msg)) {
                cerr << "Erreur lors de la reception du message. " << endl;
            }
            //cout << raw_msg << endl;
            // Impression du message de l'Arduino si valide
            if (raw_msg.size() > 0) {
                //cout << "raw_msg: " << raw_msg << endl;  // debug
                // Transfert du message en json
                j_msg_rcv = json::parse(raw_msg);
                switch (cas) {
                case 1:
                    mumuJson = j_msg_rcv["m"];
                    mumu = mumuJson;
                    B1 = j_msg_rcv["b1"];
                    if (B1 == true)
                    {
                        button1 = true;
                    }
                    else
                    {
                        button1 = false;
                    }
                    B2 = j_msg_rcv["b2"];
                    if (B2 == true)
                    {
                        button2 = true;
                    }
                    else
                    {
                        button2 = false;
                    }
                    B3 = j_msg_rcv["b3"];
                    if (B3 == true)
                    {
                        button3 = true;
                    }
                    else
                    {
                        button3 = false;
                    }

                    B4 = j_msg_rcv["b4"];
                    if (B4 == true)
                    {
                        button4 = true;
                    }
                    else
                    {
                        button4 = false;
                    }
                    joystick = j_msg_rcv["poty"];
                    joyY = joystick;
                    break;

                case 2:
                    mumu = j_msg_rcv["m"];
                    B1 = j_msg_rcv["b1"];
                    if (B1 == true)
                    {
                        button1 = true;
                        //cout << "button1 true" << endl;
                    }
                    else
                    {
                        button1 = false;
                        //cout << "button1 false" << endl;
                    }
                    B2 = j_msg_rcv["b2"];
                    if (B2 == true)
                    {
                        button2 = true;
                    }
                    else
                    {
                        button2 = false;
                    }
                    B3 = j_msg_rcv["b3"];
                    if (B3 == true)
                    {
                        button3 = true;
                    }
                    else
                    {
                        button3 = false;
                    }

                    B4 = j_msg_rcv["b4"];
                    if (B4 == true)
                    {
                        button4 = true;
                    }
                    else
                    {
                        button4 = false;
                    }
                    joystick = j_msg_rcv["potx"];
                    joyX = joystick;
                    break;
                case 3:
                    if (j_msg_rcv["acc"] > 0) {
                        accelero = j_msg_rcv["acc"];
                        amplitude = accelero;
                        cout << "amplitude = " << amplitude << endl;
                    }
                    else {
                        amplitude = 0;
                    }
                    break;
                }
                return 0;
        }
        return 0;
    }
}
void Manette::setup(string usbport) {
    string com = usbport;
    arduino = new SerialPort(com.c_str(), BAUD);
    //const char com = "\\\\.\\COM3";
    //SerialPort arduino = SerialPort("\\\\.\\COM3");
    if (!arduino->isConnected()) {
        cerr << "Impossible de se connecter au port " << string(com) << ". Fermeture du programme!" << endl;
        exit(1);
    }
}
bool Manette::SendToSerial(SerialPort* arduino, json j_msg) {
    // Return 0 if error

    string msg = j_msg.dump();
    //cout << msg << endl;
    bool ret = arduino->writeSerialPort(msg.c_str(), msg.length());
    //if(ret)
    //    RCV = false;
    return ret;
}
bool Manette::RcvFromSerial(SerialPort* arduino, string& msg) {
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
int Manette::getCas()
{
    return cas;
}
int Manette::getAfficher()
{
    return afficher;
}
int Manette::getAmplitude()
{
    return amplitude;
}
int Manette::getMumu(){
    return mumu;
}
bool Manette::getButton1()
{

    return button1;
}
bool Manette::getButton2()
{
    return button2;
}
bool Manette::getButton3()
{
    return button3;
}
bool Manette::getButton4()
{
    return button4;
}
int Manette::getJoyX()
{
    return joyX;
}
int Manette::getJoyY()
{
    return joyY;
}
void Manette::setCas(int nouveauCas)
{
    cas = nouveauCas;
}
void Manette::setAfficher(int nouvelAffichage)
{
    afficher = nouvelAffichage;
}
//void Manette::startThread()
//{
//    std::thread comm(&Manette::communication);
//}
void Manette::demande(int NewCas, int NewAfficher) {
    cas = NewCas;
    afficher = NewAfficher;
    return;
}

double Manette::GetDirectionElec(Coup coup)
{
    button1 = false;
    while (!button1)
    {
        communication();
        coup.setDirection(joyX - 2);
        cout << coup.Get_Direction() << endl;
        Sleep(10);
    }
    return coup.Get_Direction();
}
double  Manette::GetPuissanceElec(Coup coup)
{
    amplitude = 0;
    coup.setAmplitude(0);
    int i = 0;
    while (1)
    {
        communication();
        if (getAmplitude() > coup.Get_Amplitude())
        {
            coup.setAmplitude(getAmplitude());
        }
        cout << coup.Get_Amplitude() << endl;
      
        if (coup.Get_Amplitude() > 3)
            break;
    }
    return coup.Get_Amplitude();
}
double Manette::getMumu(Coup coup) {
    button1 = false;
    while (!button1)
    {
        communication();
        coup.setMumu(mumu);
        cout << coup.Get_Mumu() << endl;
    }
    return coup.Get_Mumu();
}
void Manette::SequenceCoup(Coup coup) {
    demande(2, 9);
    coup.setMumu(getMumu(coup));
    Sleep(100);
    coup.setDirection(GetDirectionElec(coup));
    demande(3, 9);
    coup.setAmplitude(GetPuissanceElec(coup));
    coup.initcoup();
    //terrain->CoupDonne(coup);
}
//int main() {
//    int donnee;
//    demande(4, 9);
//    string com = "COM7";
//    setup(com);
//    for (int i = 0; i < 1000; i++) {
//        //std::thread com(communication());
//        donnee = communication();
//        cout << donnee << endl;
//        Sleep(20);
//    }
//    return donnee;
//}