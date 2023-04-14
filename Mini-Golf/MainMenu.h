/*****************************************************************************************************************************************

Fichier: MainMenu.h
Auteurs:    Samuel Bilodeau – bils2704
            Charles Eliot Boudjack – bouc1516
            David Ferron – ferd1901
            Alexis Guérard – guea0902
            Kevin Rondeau – ronk2602
            Benjamin Labelle – labb1904
            Ali Sow – sowa0801
Date: 13 Avril 2023

Description: Fichier d'entête de la classe MainMenu. Cette classe affiche l'écran principal du jeu

Description des fonctions:
action_jouer(): Émet le signal b_jouer_appuyer.
action_regle(): Émet le signal b_regle_appuyer.
action_scoreboard(): Émet le signal b_scoreboard_appuyer.

*****************************************************************************************************************************************/

#ifndef MENUSELECTIONTERRAIN_H
#define MENUSELECTIONTERRAIN_H

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
#include <QGraphicsDropShadowEffect>


class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    MainMenu(QWidget* parent = nullptr);
    ~MainMenu();

signals:
    void b_jouer_appuyer();
    void b_regle_appuyer();
    void b_scoreboard_appuyer();

private slots:
    void action_jouer();
    void action_regle();
    void action_scoreboard();

private:
    QTextEdit* texteTitre;                          //Zone de texte du titre
    QPushButton* b_jouer;                           //Bouton jouer
    QPushButton* b_regle;                           //Bouton reglements
    QPushButton* b_scoreboard;                      //Bouton Scoreboard
    QPushButton* b_quit;                            //Bouton quitter
    QGraphicsDropShadowEffect* effectTitre;         //Effet du titre
};

#endif