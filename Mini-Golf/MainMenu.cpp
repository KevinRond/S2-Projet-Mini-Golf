/*****************************************************************************************************************************************

Fichier: MainMenu.cpp
Auteurs:    Samuel Bilodeau – bils2704
            Charles Eliot Boudjack – bouc1516
            David Ferron – ferd1901
            Alexis Guérard – guea0902
            Kevin Rondeau – ronk2602
            Benjamin Labelle – labb1904
            Ali Sow – sowa0801
Date: 13 Avril 2023

Description: Fichier source de la classe MainMenu. Cette classe affiche l'écran principal du jeu

Description des fonctions:
action_jouer(): Émet le signal b_jouer_appuyer.
action_regle(): Émet le signal b_regle_appuyer.
action_scoreboard(): Émet le signal b_scoreboard_appuyer.

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
    texteTitre->setPlainText("Menu Principal");
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
        "QPushButton:hover, QPushButton:focus { border-image: url(../Graphic/BoutonSelect.png); }"
        "QPushButton:pressed { border-image: url(../Graphic/BoutonFermer1.png); }");
    b_regle->setGeometry(475, 300, 300, 150);
    b_regle->setStyleSheet("QPushButton { border-image: url(../Graphic/BoutonOuvert1.png);"
        "font-family: Helvetica; "
        "font-weight: bold; "
        "font-size: 24px; "
        "color: white "
        "}"
        "QPushButton:hover, QPushButton:focus { border-image: url(../Graphic/BoutonSelect.png); }"
        "QPushButton:pressed { border-image: url(../Graphic/BoutonFermer1.png); }");
    b_scoreboard->setGeometry(475, 400, 300, 150);
    b_scoreboard->setStyleSheet("QPushButton { border-image: url(../Graphic/BoutonOuvert1.png);"
        "font-family: Helvetica; "
        "font-weight: bold; "
        "font-size: 14px; "
        "color: white "
        "}"
        "QPushButton:hover, QPushButton:focus  { border-image: url(../Graphic/BoutonSelect.png); }"
        "QPushButton:pressed { border-image: url(../Graphic/BoutonFermer1.png); }");
    b_quit->setGeometry(475, 500, 300, 150);
    b_quit->setStyleSheet("QPushButton { border-image: url(../Graphic/BoutonOuvert1.png);"
        "font-family: Helvetica; "
        "font-weight: bold; "
        "font-size: 20px; "
        "color: white "
        "}"
        "QPushButton:hover, QPushButton:focus  { border-image: url(../Graphic/BoutonSelect.png); }"
        "QPushButton:pressed { border-image: url(../Graphic/BoutonFermer1.png); }");


    //Actions des boutons
    connect(b_jouer, &QPushButton::clicked, this, &MainMenu::action_jouer);
    connect(b_regle, &QPushButton::clicked, this, &MainMenu::action_regle);
    connect(b_scoreboard, &QPushButton::clicked, this, &MainMenu::action_scoreboard);
    connect(b_quit, &QPushButton::clicked, this, &QCoreApplication::quit);

    // Set the focus policy of the widget to accept keyboard focus
    setFocusPolicy(Qt::StrongFocus);

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
Émet le signal b_jouer_appuyer.

:return:
*/
{
    emit b_jouer_appuyer();
}

void MainMenu::action_regle()
/*
Émet le signal b_regle_appuyer.

:return:
*/
{
    emit b_regle_appuyer();
}

void MainMenu::action_scoreboard()
/*
Émet le signal b_scoreboard_appuyer.

:return:
*/
{
    emit b_scoreboard_appuyer();
}

void MainMenu::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_W || event->key() == Qt::Key_S) {
        // Find the currently focused button
        QPushButton* currentButton = qobject_cast<QPushButton*>(focusWidget());
        if (currentButton == nullptr) {
            // If no button is focused, set focus to the first button
            QWidget* firstChild = findChild<QPushButton*>(); // Find the first QPushButton child
            if (firstChild != nullptr) {
                firstChild->setFocus();
            }
        }
        else {
            // Find the next or previous button depending on the key press
            QPushButton* nextButton = nullptr;
            if (event->key() == Qt::Key_S) {
                nextButton = qobject_cast<QPushButton*>(currentButton->nextInFocusChain());
            }
            else {
                nextButton = qobject_cast<QPushButton*>(currentButton->previousInFocusChain());
            }
            if (nextButton != nullptr) {
                // Set focus to the next or previous button
                nextButton->setFocus();
            }
        }
    }
    else if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return) {
        // Handle enter key press
        QPushButton* currentButton = qobject_cast<QPushButton*>(focusWidget());
        if (currentButton != nullptr) {
            // Trigger the clicked signal of the currently focused button
            QMetaObject::invokeMethod(currentButton, "click", Qt::QueuedConnection);
        }
    }
    else if (event->key() == Qt::Key_Backspace) {
        // Handle backspace key press
        &QCoreApplication::quit;
    }
}
