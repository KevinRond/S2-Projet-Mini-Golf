/*****************************************************************************************************************************************

Fichier: MenuScoreboard.h
Auteurs:    Samuel Bilodeau � bils2704
            Alexis Gu�rard � guea0902
            Kevin Rondeau � ronk2602
            Ali Sow � sowa0801
Date: 13 Avril 2023

Description: Fichier d'ent�te de la classe MenuScoreboard. Cette classe affiche l'�cran du tableau d'affichage des meilleurs joueurs du jeu.

Description des fonctions:
action_retour(): �met le signal b_retour_appuyer.

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
#include <QKeyEvent>

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

protected:
    void keyPressEvent(QKeyEvent* event) override;

private:
    QTextEdit* texteTitre;
    QPushButton* b_retour;
    QGraphicsDropShadowEffect* effect;

};