/*****************************************************************************************************************************************

Fichier: MenuScoreboard.h
Auteurs:    Samuel Bilodeau – bils2704
            Charles Eliot Boudjack – bouc1516
            David Ferron – ferd1901
            Alexis Guérard – guea0902
            Kevin Rondeau – ronk2602
            Benjamin Labelle – labb1904
            Ali Sow – sowa0801
Date: 13 Avril 2023

Description: Fichier d'entête de la classe MenuScoreboard. Cette classe affiche l'écran du tableau d'affichage des meilleurs joueurs du jeu.

Description des fonctions:
action_retour(): Émet le signal b_retour_appuyer.

*****************************************************************************************************************************************/

#pragma once

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
#include <QGraphicsDropShadowEffect>

class MenuScoreboard : public QMainWindow
{
    Q_OBJECT

public:
    MenuScoreboard(QWidget* parent = nullptr);
    ~MenuScoreboard();

signals:
    void b_retour_appuyer();

private slots:
    void action_retour();

private:
    QTextEdit* texteTitre;
    QPushButton* b_retour;
    QGraphicsDropShadowEffect* effect;

};