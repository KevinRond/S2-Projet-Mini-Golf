#pragma once

/*****************************************************************************************************************************************

Fichier: TitleScreen.h
Auteurs:    Samuel Bilodeau – bils2704
            Alexis Guérard – guea0902
            Kevin Rondeau – ronk2602
            Ali Sow – sowa0801
Date: 13 Avril 2023

Description: Fichier d'entête de la classe TitleScreen. Cette classe affiche l'écran titre du jeu.

Description des fonctions:
switchMenus(): Émet le signal buttonClicked.

*****************************************************************************************************************************************/

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
#include <QKeyEvent>
#include <QGraphicsDropShadowEffect>
#include <QMediaPlayer>
#include <Windows.h>


class TitleScreen : public QMainWindow
{
    Q_OBJECT

public:
    TitleScreen(QWidget* parent = nullptr);
    ~TitleScreen();

signals:
    void buttonClicked();


private slots:
    void switchMenus();

private:
    //Ui::QTLabo1Class ui;
    QPushButton* MainButton;
    QTextEdit* texteTitre;
    QTextEdit* soustitre;
    QGraphicsDropShadowEffect* effectTitre;
    QGraphicsDropShadowEffect* effectSousTitre;
    QMediaPlayer* titleScreen;
    QMediaPlayer* boutonSon;
};