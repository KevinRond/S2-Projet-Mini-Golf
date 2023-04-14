/*****************************************************************************************************************************************

Fichier: MainMenu.cpp
Auteurs:    Samuel Bilodeau � bils2704
            Alexis Gu�rard � guea0902
            Kevin Rondeau � ronk2602
            Ali Sow � sowa0801
Date: 13 Avril 2023

Description: Fichier source de la classe MainMenu. Cette classe affiche l'�cran principal du jeu

Description des fonctions:
action_jouer(): �met le signal b_jouer_appuyer.
action_regle(): �met le signal b_regle_appuyer.
action_scoreboard(): �met le signal b_scoreboard_appuyer.

*****************************************************************************************************************************************/

#include "MainMenu.h"

MainMenu::MainMenu(QWidget* parent)
    : QMainWindow(parent)
{

    this->setFixedSize(1280, 720);
    setStyleSheet("QMainWindow{ background-image: url(../Graphic/BeauFond3.png); }");

    //Texte du titre
    texteTitre = new QTextEdit(this);
    texteTitre->setGeometry(240, 100, 800, 200);
    texteTitre->setPlainText("Menu Principale");
    texteTitre->setReadOnly(true);
    QString style_titre = "QTextEdit {"
        "font-family: Helvetica;"
        "font-size: 60px;"
        "color: white;"
        "background-color: transparent;"
        "border: none;"
        "}";
    texteTitre->setStyleSheet(style_titre);
    texteTitre->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    //Effet du titre
    effectTitre = new QGraphicsDropShadowEffect;
    effectTitre->setBlurRadius(5);
    effectTitre->setColor(Qt::black);
    effectTitre->setOffset(3, 3);
    texteTitre->setGraphicsEffect(effectTitre);

    //Set up des boutons
    b_jouer = new QPushButton("Jouer", this);
    b_regle = new QPushButton("Regles", this);
    b_scoreboard = new QPushButton("Gagnant du prix Carl Carmoni", this);
    b_quit = new QPushButton("Quitter l'application", this);


    b_jouer->setGeometry(475, 200, 300, 150);
    b_jouer->setStyleSheet("QPushButton { border-image: url(../Graphic/BoutonOuvert1.png);"
                                    "font-family: Helvetica; "
                                    "font-weight: bold; "
                                    "font-size: 24px; "
                                    "color: white "
                                    "}"
        "QPushButton:hover { border-image: url(../Graphic/BoutonSelect.png); }"
        "QPushButton:pressed { border-image: url(../Graphic/BoutonFermer1.png); }");
    b_regle->setGeometry(475, 300, 300, 150);
    b_regle->setStyleSheet("QPushButton { border-image: url(../Graphic/BoutonOuvert1.png);"
        "font-family: Helvetica; "
        "font-weight: bold; "
        "font-size: 24px; "
        "color: white "
        "}"
        "QPushButton:hover { border-image: url(../Graphic/BoutonSelect.png); }"
        "QPushButton:pressed { border-image: url(../Graphic/BoutonFermer1.png); }");
    b_scoreboard->setGeometry(475, 400, 300, 150);
    b_scoreboard->setStyleSheet("QPushButton { border-image: url(../Graphic/BoutonOuvert1.png);"
        "font-family: Helvetica; "
        "font-weight: bold; "
        "font-size: 14px; "
        "color: white "
        "}"
        "QPushButton:hover { border-image: url(../Graphic/BoutonSelect.png); }"
        "QPushButton:pressed { border-image: url(../Graphic/BoutonFermer1.png); }");
    b_quit->setGeometry(475, 500, 300, 150);
    b_quit->setStyleSheet("QPushButton { border-image: url(../Graphic/BoutonOuvert1.png);"
        "font-family: Helvetica; "
        "font-weight: bold; "
        "font-size: 20px; "
        "color: white "
        "}"
        "QPushButton:hover { border-image: url(../Graphic/BoutonSelect.png); }"
        "QPushButton:pressed { border-image: url(../Graphic/BoutonFermer1.png); }");


    //Actions des boutons
    connect(b_jouer, &QPushButton::clicked, this, &MainMenu::action_jouer);
    connect(b_regle, &QPushButton::clicked, this, &MainMenu::action_regle);
    connect(b_scoreboard, &QPushButton::clicked, this, &MainMenu::action_scoreboard);

    boutonSon = new QMediaPlayer;
    QString boutonfile = "../Son/BoutonNormal.mp3";
    boutonSon->setMedia(QUrl::fromLocalFile(boutonfile));

    QMediaPlayer* byeSon = new QMediaPlayer;
    QUrl byeUrl = QUrl::fromLocalFile("../Son/Bye.mp3");
    byeSon->setMedia(QMediaContent(byeUrl));
    

    connect(b_quit, &QPushButton::clicked, [this, byeSon]() {
        byeSon->play(); // Jouer le son
        QTimer::singleShot(1000, this, &QCoreApplication::quit); // Quitter l'application apr�s une pause de 1000 ms (1 seconde)
        });
}

MainMenu::~MainMenu()
{
    delete effectTitre;
    delete texteTitre;
    delete b_jouer;
    delete b_regle;
    delete b_scoreboard;
    delete b_quit;
}

void MainMenu::action_jouer()
/*
�met le signal b_jouer_appuyer.

:return:
*/
{
    boutonSon->play();
    emit b_jouer_appuyer();
}

void MainMenu::action_regle()
/*
�met le signal b_regle_appuyer.

:return:
*/
{
    boutonSon->play();
    emit b_regle_appuyer();

}

void MainMenu::action_scoreboard()
/*
�met le signal b_scoreboard_appuyer.

:return:
*/
{
    boutonSon->play();
    emit b_scoreboard_appuyer();
}
