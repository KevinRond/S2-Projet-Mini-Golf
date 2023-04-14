#pragma once

/*****************************************************************************************************************************************

Fichier: Interface.h
Auteurs:    Samuel Bilodeau – bils2704
            Alexis Guérard – guea0902
            Kevin Rondeau – ronk2602
            Ali Sow – sowa0801
Date: 13 Avril 2023

Description: Fichier d'entête de la classe Interface. Cette classe gère les différents widget qui compose l'interface graphique du jeu.
Cette classe reçoit les signaux de chaque widget afin d'afficher les interfaces désirés.

*****************************************************************************************************************************************/


#include <iostream>
#include <string>

#include <QtWidgets/QMainWindow>
#include <QApplication>
#include <QPushButton>
#include <QMenu>
#include <QAction>
#include <QVBoxLayout>
#include <QMenuBar>
#include <QTextEdit>
#include <QTextBrowser>
#include <QStackedWidget>
#include <QLabel>

#include "TitleScreen.h"
#include "MainMenu.h"
#include "MenuSelectionTerrain.h"
#include "MenuScoreboard.h"
#include "MenuReglements.h"
#include "FenetreTerrain.h"


class Interface : public QMainWindow
{
    Q_OBJECT

public:
    Interface(QWidget* parent = nullptr);
    ~Interface();

private slots:
    

private:
    //Ui::QTLabo1Class ui;
    QStackedWidget* listeMenus;                     //Liste des menus
    TitleScreen* titleScreen;                       //Menu Title Screen
    MainMenu* menuPrincipal;                        //Menu Principale
    MenuSelectionTerrain* menuSelectionTerrain;     //Menu de selection de terrains
    MenuScoreboard* menuScoreboard;                 //Menu de scoreboard
    MenuReglements* menuReglements;                 //Menu des reglements
    FenetreTerrain* fenetreTerrain;                 //Menu d'affichage du terrain
};