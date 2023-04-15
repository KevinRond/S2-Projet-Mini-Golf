/*****************************************************************************************************************************************

Fichier: MenuSelectionTerrain.h
Auteurs:    Samuel Bilodeau – bils2704
            Alexis Guérard – guea0902
            Kevin Rondeau – ronk2602
            Ali Sow – sowa0801
Date: 13 Avril 2023

Description: Fichier d'entête de la classe MenuSelectionTerrain. Cette classe affiche l'écran de sélection des différents terrains.

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
#include <QGraphicsDropShadowEffect>
#include <QMediaPlayer>
#include <QKeyEvent>

class MenuSelectionTerrain : public QMainWindow
{
    Q_OBJECT

public:
    MenuSelectionTerrain(QWidget* parent = nullptr);
    ~MenuSelectionTerrain();

signals:
    void b_retour_appuyer();
    void b_terrain1_appuyer();
    void b_terrain2_appuyer();
    void b_terrain3_appuyer();
    void b_terrain4_appuyer();
    void b_terrain5_appuyer();
    void b_terrain6_appuyer();
    void b_terrain7_appuyer();
    void b_terrain8_appuyer();
    
private slots:
    void action_retour();
    void action_terrain1();
    void action_terrain2();
    void action_terrain3();
    void action_terrain4();
    void action_terrain5();
    void action_terrain6();
    void action_terrain7();
    void action_terrain8();

private:
    QTextEdit* texteTitre;
    QPushButton* b_retour;
    QPushButton* b_terrain1;
    QPushButton* b_terrain2;
    QPushButton* b_terrain3;
    QPushButton* b_terrain4;
    QPushButton* b_terrain5;
    QPushButton* b_terrain6;
    QPushButton* b_terrain7;
    QPushButton* b_terrain8;
    QGraphicsDropShadowEffect* effectTitre;
    QMediaPlayer* back;

protected:
    void keyPressEvent(QKeyEvent* event) override;
    
};