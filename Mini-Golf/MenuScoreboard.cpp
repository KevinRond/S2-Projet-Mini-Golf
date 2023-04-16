/*****************************************************************************************************************************************

Fichier: MenuScoreboard.cpp
Auteurs:    Samuel Bilodeau – bils2704
            Alexis Guérard – guea0902
            Kevin Rondeau – ronk2602
            Ali Sow – sowa0801
Date: 13 Avril 2023

Description: Fichier source de la classe MenuScoreboard. Cette classe affiche l'écran du tableau d'affichage des meilleurs joueurs du jeu.

Description des fonctions:
action_retour(): Émet le signal b_retour_appuyer.

*****************************************************************************************************************************************/

#include "MenuScoreboard.h"

MenuScoreboard::MenuScoreboard(QWidget* parent)
    : QMainWindow(parent)
{
    //ui.setupUi(this);

    this->setFixedSize(1280, 720);
    setStyleSheet("QMainWindow{ background-image: url(../Graphic/Commande.png); }");

    //Texte du titre
    texteTitre = new QTextEdit(this);
    texteTitre->setGeometry(240, 100, 800, 400);
    texteTitre->setPlainText("Instruction des commandes ");
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
    effect = new QGraphicsDropShadowEffect;
    effect->setBlurRadius(5);
    effect->setColor(Qt::black);
    effect->setOffset(3, 3);
    texteTitre->setGraphicsEffect(effect);

    //Set up du bouton
    b_retour = new QPushButton("Retour", this);
    b_retour->setGeometry(1080, 620, 200, 100);
    b_retour->setStyleSheet("QPushButton { border-image: url(../Graphic/BoutonOuvert1.png);"
        "font-family: Helvetica; "
        "font-weight: bold; "
        "font-size: 16px; "
        "color: white "
        "}"
        "QPushButton:hover { border-image: url(../Graphic/BoutonSelect.png); }"
        "QPushButton:pressed { border-image: url(../Graphic/BoutonFermer1.png); }");

    //Action du bouton
    connect(b_retour, &QPushButton::clicked, this, &MenuScoreboard::action_retour);

}

MenuScoreboard::~MenuScoreboard()
{
    delete effect;
    delete texteTitre;
    delete b_retour;
}

void MenuScoreboard::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Backspace) {
        // Handle enter key press
        emit b_retour_appuyer();
    }
}

void MenuScoreboard::action_retour()
/************************************
Émet le signal b_retour_appuyer.

:return:
*************************************/
{
    emit b_retour_appuyer();
}

