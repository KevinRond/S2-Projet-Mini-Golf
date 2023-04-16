#pragma once


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
#include "Manette.h"


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
    //Il faudrait ajouter un menu pause et un menu de reussite apres le trou
};