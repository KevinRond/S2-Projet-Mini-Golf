/*****************************************************************************************************************************************

Fichier: MenuSelectionTerrain.cpp
Auteurs:    Samuel Bilodeau – bils2704
            Charles Eliot Boudjack – bouc1516
            David Ferron – ferd1901
            Alexis Guérard – guea0902
            Kevin Rondeau – ronk2602
            Benjamin Labelle – labb1904
            Ali Sow – sowa0801
Date: 13 Avril 2023

Description: Fichier source de la classe MenuSelectionTerrain. Cette classe affiche l'écran de sélection des différents terrains.

Description des fonctions:
action_terrain1(): Émet le signal b_terrain1_appuyer.
action_terrain2(): Émet le signal b_terrain2_appuyer.
action_terrain3(): Émet le signal b_terrain3_appuyer.
action_terrain4(): Émet le signal b_terrain4_appuyer.
action_terrain5(): Émet le signal b_terrain5_appuyer.
action_terrain6(): Émet le signal b_terrain6_appuyer.
action_terrain7(): Émet le signal b_terrain7_appuyer.
action_terrain8(): Émet le signal b_terrain8_appuyer.
action_retour(): Émet le signal b_retour_appuyer.

*****************************************************************************************************************************************/

#include "MenuSelectionTerrain.h"

MenuSelectionTerrain::MenuSelectionTerrain(QWidget* parent)
    : QMainWindow(parent)
{
    //ui.setupUi(this);

    this->setFixedSize(1280, 720);
    setStyleSheet("QMainWindow{ background-image: url(../Graphic/BeauFond3.png); }");

    //Texte du titre
    texteTitre = new QTextEdit(this);
    texteTitre->setGeometry(240, 40, 800, 200);
    texteTitre->setPlainText("Selection Terrain");
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
    b_retour = new QPushButton("Retour", this);
    b_retour->setGeometry(1080, 620, 200, 100);
    b_retour->setStyleSheet("QPushButton { border-image: url(../Graphic/BoutonOuvert1.png);"
        "font-family: Helvetica; "
        "font-weight: bold; "
        "font-size: 16px; "
        "color: white "
        "}"
        "QPushButton:hover, QPushButton:focus { border-image: url(../Graphic/BoutonSelect.png); }"
        "QPushButton:pressed { border-image: url(../Graphic/BoutonFermer1.png); }");


    b_terrain1 = new QPushButton("Terrain 1", this);
    b_terrain2 = new QPushButton("Terrain 2", this);
    b_terrain3 = new QPushButton("Terrain 3", this);
    b_terrain4 = new QPushButton("Terrain 4", this);
    b_terrain5 = new QPushButton("Terrain 5", this);
    b_terrain6 = new QPushButton("Terrain 6", this);
    b_terrain7 = new QPushButton("Terrain 7", this);
    b_terrain8 = new QPushButton("Terrain 8", this);

    b_terrain1->setGeometry(206, 140, 256, 152);
    b_terrain1->setStyleSheet("QPushButton { border-image: url(../Terrain/Terrain1.png);"
        "font-family: Helvetica; "
        "font-weight: bold; "
        "font-size: 16px; "
        "color: white "
        "}"
        "QPushButton:hover, QPushButton:focus { border: 15px solid white;  border-radius: 15px; }");
    b_terrain2->setGeometry(512, 140, 256, 152);
    b_terrain2->setStyleSheet("QPushButton { border-image: url(../Terrain/Terrain2.png);"
        "font-family: Helvetica; "
        "font-weight: bold; "
        "font-size: 16px; "
        "color: white "
        "}"
        "QPushButton:hover, QPushButton:focus { border: 15px solid white;  border-radius: 15px; }");
    b_terrain3->setGeometry(818, 140, 256, 152);
    b_terrain3->setStyleSheet("QPushButton { border-image: url(../Terrain/Terrain3.png);"
        "font-family: Helvetica; "
        "font-weight: bold; "
        "font-size: 16px; "
        "color: white "
        "}"
        "QPushButton:hover, QPushButton:focus { border: 15px solid white;  border-radius: 15px; }");
    b_terrain4->setGeometry(206, 342, 256, 152);
    b_terrain4->setStyleSheet("QPushButton { border-image: url(../Terrain/Terrain4.png);"
        "font-family: Helvetica; "
        "font-weight: bold; "
        "font-size: 16px; "
        "color: white "
        "}"
        "QPushButton:hover, QPushButton:focus { border: 15px solid white;  border-radius: 15px; }");
    b_terrain5->setGeometry(512, 342, 256, 152);
    b_terrain5->setStyleSheet("QPushButton { border-image: url(../Terrain/Terrain5.png);"
        "font-family: Helvetica; "
        "font-weight: bold; "
        "font-size: 16px; "
        "color: white "
        "}"
        "QPushButton:hover, QPushButton:focus { border: 15px solid white;  border-radius: 15px; }");
    b_terrain6->setGeometry(818, 342, 256, 152);
    b_terrain6->setStyleSheet("QPushButton { border-image: url(../Terrain/Terrain6.png);"
        "font-family: Helvetica; "
        "font-weight: bold; "
        "font-size: 16px; "
        "color: white "
        "}"
        "QPushButton:hover, QPushButton:focus { border: 15px solid white;  border-radius: 15px; }");
    b_terrain7->setGeometry(359, 544, 256, 152);
    b_terrain7->setStyleSheet("QPushButton { border-image: url(../Terrain/Terrain7.png);"
        "font-family: Helvetica; "
        "font-weight: bold; "
        "font-size: 16px; "
        "color: white "
        "}"
        "QPushButton:hover, QPushButton:focus { border: 15px solid white;  border-radius: 15px; }");
    b_terrain8->setGeometry(665, 544, 256, 152);
    b_terrain8->setStyleSheet("QPushButton { border-image: url(../Terrain/Terrain8.png);"
        "font-family: Helvetica; "
        "font-weight: bold; "
        "font-size: 16px; "
        "color: white "
        "}"
        "QPushButton:hover, QPushButton:focus { border: 15px solid white;  border-radius: 15px; }");


    //Actions des boutons
    connect(b_retour, &QPushButton::clicked, this, &MenuSelectionTerrain::action_retour);
    connect(b_terrain1, &QPushButton::clicked, this, &MenuSelectionTerrain::action_terrain1);
    connect(b_terrain2, &QPushButton::clicked, this, &MenuSelectionTerrain::action_terrain2);
    connect(b_terrain3, &QPushButton::clicked, this, &MenuSelectionTerrain::action_terrain3);
    connect(b_terrain4, &QPushButton::clicked, this, &MenuSelectionTerrain::action_terrain4);
    connect(b_terrain5, &QPushButton::clicked, this, &MenuSelectionTerrain::action_terrain5);
    connect(b_terrain6, &QPushButton::clicked, this, &MenuSelectionTerrain::action_terrain6);
    connect(b_terrain7, &QPushButton::clicked, this, &MenuSelectionTerrain::action_terrain7);
    connect(b_terrain8, &QPushButton::clicked, this, &MenuSelectionTerrain::action_terrain8);

    // Set the focus policy of the widget to accept keyboard focus
    setFocusPolicy(Qt::StrongFocus);
}

MenuSelectionTerrain::~MenuSelectionTerrain()
{
    delete effectTitre;
    delete texteTitre;
    delete b_retour;
    delete b_terrain1;
    delete b_terrain2;
    delete b_terrain3;
    delete b_terrain4;
    delete b_terrain5;
    delete b_terrain6;
    delete b_terrain7;
    delete b_terrain8;
}

void MenuSelectionTerrain::action_retour()
/*******************************************
Émet le signal b_retour_appuyer.

:return:
********************************************/
{
    emit b_retour_appuyer();
}

void MenuSelectionTerrain::action_terrain1()
/*******************************************
Émet le signal b_terrain1_appuyer.

:return:
********************************************/
{
    emit b_terrain1_appuyer();
}

void MenuSelectionTerrain::action_terrain2()
/*******************************************
Émet le signal b_terrain2_appuyer.

:return:
********************************************/
{
    emit b_terrain2_appuyer();
}

void MenuSelectionTerrain::action_terrain3()
/*******************************************
Émet le signal b_terrain3_appuyer.

:return:
********************************************/
{
    emit b_terrain3_appuyer();
}

void MenuSelectionTerrain::action_terrain4()
/*******************************************
Émet le signal b_terrain4_appuyer.

:return:
********************************************/
{
    emit b_terrain4_appuyer();
}

void MenuSelectionTerrain::action_terrain5()
/*******************************************
Émet le signal b_terrain5_appuyer.

:return:
********************************************/
{
    emit b_terrain5_appuyer();
}

void MenuSelectionTerrain::action_terrain6()
/*******************************************
Émet le signal b_terrain6_appuyer.

:return:
********************************************/
{
    emit b_terrain6_appuyer();
}

void MenuSelectionTerrain::action_terrain7()
/*******************************************
Émet le signal b_terrain7_appuyer.

:return:
********************************************/
{
    emit b_terrain7_appuyer();
}

void MenuSelectionTerrain::action_terrain8()
/*******************************************
Émet le signal b_terrain8_appuyer.

:return:
********************************************/
{
    emit b_terrain8_appuyer();
}

void MenuSelectionTerrain::keyPressEvent(QKeyEvent* event)
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
        // Handle enter key press
        emit b_retour_appuyer();
    }
}

