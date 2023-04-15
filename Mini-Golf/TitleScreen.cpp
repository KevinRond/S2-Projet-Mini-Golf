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

    //musiques

    titleScreen = new QMediaPlayer;
    QString titleScreenFile = "../Son/TitleScreen.mp3";
    titleScreen->setMedia(QUrl::fromLocalFile(titleScreenFile));
    titleScreen->setVolume(50);
    titleScreen->play();

    boutonSon = new QMediaPlayer;
    QString boutonSonFile = "../Son/ButtonTitreEffect.mp3";
    boutonSon->setMedia(QUrl::fromLocalFile(boutonSonFile));
    boutonSon->setVolume(70);

    //manette = new Manette("com3");

}

TitleScreen::~TitleScreen()
{
    delete effectTitre;
    delete effectSousTitre;
    delete MainButton;
    delete texteTitre;
    //delete manette;
}

//void TitleScreen::launchManette()
//{
//    manette->setBouton();
//    while (!manette->getButton1())
//    {
//
//    }
//
//    switchMenus();
//}


void TitleScreen::switchMenus() 
/*
Émet le signal buttonClicked.

:return:
*/
{
    boutonSon->play();
    titleScreen->setVolume(40);
    Sleep(100);
    titleScreen->setVolume(35);
    Sleep(100);
    titleScreen->setVolume(30);
    Sleep(100);
    titleScreen->setVolume(25);
    Sleep(100);
    titleScreen->setVolume(20);
    Sleep(100);
    titleScreen->stop();
    emit buttonClicked();

}


void TitleScreen::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return) {
        // Handle enter key press
        boutonSon->play();
        titleScreen->setVolume(40);
        Sleep(100);
        titleScreen->setVolume(35);
        Sleep(100);
        titleScreen->setVolume(30);
        Sleep(100);
        titleScreen->setVolume(25);
        Sleep(100);
        titleScreen->setVolume(20);
        Sleep(100);
        titleScreen->stop();
        emit buttonClicked();
    }
}

//void TitleScreen::showEvent(QShowEvent* event)
//{
//    launchManette();
//    QMainWindow::showEvent(event);
//}
