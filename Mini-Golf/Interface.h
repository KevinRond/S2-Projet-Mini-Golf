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


class Interface : public QMainWindow
{
    Q_OBJECT

public:
    Interface(QWidget* parent = nullptr);
    ~Interface();

private slots:
    

private:
    //Ui::QTLabo1Class ui;
    QStackedWidget* listeMenus;
    TitleScreen* titleScreen;
    MainMenu* menuPrincipal;
    MenuSelectionTerrain* menuSelectionTerrain;
    MenuScoreboard* menuScoreboard;
    MenuReglements* menuReglements;
    FenetreTerrain* fenetreTerrain;
};