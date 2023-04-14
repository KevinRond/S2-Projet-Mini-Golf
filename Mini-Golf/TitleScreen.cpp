/*****************************************************************************************************************************************

Fichier: TitleScreen.cpp
Auteurs:    Samuel Bilodeau – bils2704
            Alexis Guérard – guea0902
            Kevin Rondeau – ronk2602
            Ali Sow – sowa0801
Date: 13 Avril 2023

Description: Fichier source de la classe TitleScreen. Cette classe affiche l'écran titre du jeu.

Description des fonctions:
switchMenus(): Émet le signal buttonClicked.

*****************************************************************************************************************************************/

#include "TitleScreen.h"

TitleScreen::TitleScreen(QWidget* parent)
    : QMainWindow(parent)
{
    //ui.setupUi(this);

    this->setFixedSize(1280, 720);
    setStyleSheet("QMainWindow{ background-image: url(../Graphic/TitleScreen.png); }");

    //Texte du titre
    texteTitre = new QTextEdit(this);
    texteTitre->setGeometry(440, 150, 360, 120);
    texteTitre->setPlainText("Mini-G");
    texteTitre->setReadOnly(true);
    QString style_titre = "QTextEdit {"
        "font-family: Helvetica;"
        "font-size: 90px;"
        "color: white;"
        "background-color: transparent;"
        "border: none;"
        "}";
    texteTitre->setStyleSheet(style_titre);
    texteTitre->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);



    //Texte du sous-titre
    soustitre = new QTextEdit(this);
    soustitre->setGeometry(440, 250, 360, 60);
    soustitre->setPlainText("par R2P2");
    soustitre->setReadOnly(true);
    QString style_soustitre = "QTextEdit {"
        "font-family: Helvetica;"
        "font-size: 24px;"
        "color: white;" 
        "background-color: transparent;"
        "border: none;"
        "}";
    soustitre->setStyleSheet(style_soustitre);
    soustitre->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    //Effet du titre
    effectTitre = new QGraphicsDropShadowEffect;
    effectTitre->setBlurRadius(5);
    effectTitre->setColor(Qt::black);
    effectTitre->setOffset(4, 4);
    texteTitre->setGraphicsEffect(effectTitre);

    //Effet du sous-titre
    effectSousTitre = new QGraphicsDropShadowEffect;
    effectSousTitre->setBlurRadius(5);
    effectSousTitre->setColor(Qt::black);
    effectSousTitre->setOffset(3, 3);
    soustitre->setGraphicsEffect(effectSousTitre);


    //Set up du bouton
    MainButton = new QPushButton("Appuyer pour commencer", this);
    MainButton->setGeometry(475, 400, 300, 150);
    MainButton->setStyleSheet("QPushButton { border-image: url(../Graphic/BoutonOuvert1.png);"
        "font-family: Helvetica; "
        "font-weight: bold; "
        "font-size: 16px; "
        "color: white "
        "}"
        "QPushButton:hover { border-image: url(../Graphic/BoutonSelect.png); }"
        "QPushButton:pressed { border-image: url(../Graphic/BoutonFermer1.png); }");
    //MainButton->setStyleSheet(buttonStyle);

    //Actions du bouton
    connect(MainButton, &QPushButton::clicked, this, &TitleScreen::switchMenus);
}

TitleScreen::~TitleScreen()
{
    delete effectTitre;
    delete effectSousTitre;
    delete MainButton;
    delete texteTitre;
}


void TitleScreen::switchMenus() 
/*
Émet le signal buttonClicked.

:return:
*/
{
    emit buttonClicked();
}