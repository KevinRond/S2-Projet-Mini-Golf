/*****************************************************************************************************************************************

Fichier: MenuReglements.h
Auteurs:    Samuel Bilodeau – bils2704
            Alexis Guérard – guea0902
            Kevin Rondeau – ronk2602
            Ali Sow – sowa0801
Date: 13 Avril 2023

Description: Fichier d'entête de la classe MenuReglements. Cette classe affiche l'écran des règles du jeu

Description des fonctions:
action_retour(): Émet le signal b_retour_appuyer.

*****************************************************************************************************************************************/

#pragma once

#include <QtWidgets/QMainWindow>
#include <qapplication.h>
#include <qmenu.h>
#include <qaction.h>
#include <qpushbutton.h>
//#include <QMediaPlayer>
#include <QtWidgets/QTextEdit>
#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>



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

class MenuReglements : public QMainWindow
{
    Q_OBJECT

public:
    MenuReglements(QWidget* parent = nullptr);
    ~MenuReglements();

signals:
    void b_retour_appuyer();

private slots:
    void action_retour();

private:
    QTextEdit* texteTitre;                              //Zone de texte du titre
    QTextEdit* texteReglements;                         //Zone de texte pour les reglements
    QPushButton* b_retour;                              //Bouton de retour
    QGraphicsDropShadowEffect* effectTitre;             //Effet du titre
    QGraphicsDropShadowEffect* effectReglements;        //Effet du texte des reglements

};