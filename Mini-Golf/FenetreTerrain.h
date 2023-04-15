/*********************************************************************************************************

Fichier: FenetreTerrain.h
Auteurs:    Samuel Bilodeau – bils2704
            Alexis Guérard – guea0902
            Kevin Rondeau – ronk2602
            Ali Sow – sowa0801
Date: 13 Avril 2023

Description: Fichier d'entête de la classe FenetreTerrain. Cette classe affiche le jeu.

Description des fonctions:

set_terrain(QString file_name): Cette fonction est responsable de créer un objet terrain avec le nom de 
fichier qu'elle reçoit en paramètre. Ce nom de fichier lui permet d'aller ouvrir les fichiers lui donnant
pour le fond d'écran ainsi que pour la position des murs et de la balle. La fonction affiche également le
terrain, la balle, ainsi que la cible qui permet de viser.

get_file_name(): Fonction permettant de retourner le nom de fichier du terrain actuel.

calculateX(double posBalleX): Cette fonction calcule la position en X de la cible en prenant la position 
de la balle en X comme paramètre.

calculateY(double posBalley): Cette fonction calcule la position en Y de la cible en prenant la position 
de la balle en Y comme paramètre.

action_retour(): Émet le signal b_retour_appuyer.

affiche_nom_fichier(): Permet d'afficher le nom de fichier dans une zone de texte.

action_trouSuivant(): Met à jour le terrain actuel si le joueur choisi cette action.

action_fin(): Emet le signal b_fin_appuyer. Ferme le jeu.

jouer(): Cette fonction permet d'exécuter le jeu. Tant que le trou n'est pas réussi, elle prendra les coups
du joueur et déplacera la balle dans le terrain. Si le trou est est réussi, l'usager peut quitter ou jouer
le prochain trou.

keyPressEvent(QKeyEvent* event): Gère les entrées de l'usager avec manette ou clavier.

************************************************************************************************************/

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
#include <iostream>
#include <QKeyEvent>
#include <conio.h>
#include <Terrain.h>
#include <QThread>
#include <Windows.h>
#include <QDialog>
#include <QGraphicsDropShadowEffect>
#include <QMediaPlayer>

#include "Manette.h"

#define M_PI 3.1415926535

class FenetreTerrain : public QMainWindow
{
    Q_OBJECT

public:
    FenetreTerrain(QWidget* parent = nullptr);
    ~FenetreTerrain();
    void set_terrain(QString file_name);
    QString get_file_name();
    double calculateX(double posBalleX);
    double calculateY(double posBalley);

signals:
    void b_retour_appuyer();
    void b_trouSuivant_appuyer();
    void b_fin_appuyer();

private slots:
    void action_retour();
    void affiche_nom_fichier();
    void action_trouSuivant();
    void action_fin();

private:
    QTextEdit* texteTitre;
    QTextEdit* nomfichier;
    QLabel* forceText;
    QLabel* directionText;
    QLabel* coupText;
    QLabel* finalCoupText;
    QPushButton* b_retour;
    QString nom_fichier_terrain;
    QLabel* balle;
    Terrain* terrain1;
    QDialog* reussi;
    QDialog* fin;
    QLabel* point;

    QGraphicsDropShadowEffect* effect_etiquette_force;
    QGraphicsDropShadowEffect* effect_etiquette_direction;
    QGraphicsDropShadowEffect* effect_etiquette_coup;
    


    QMediaPlayer* connard;
    QMediaPlayer* back;
    QMediaPlayer* desert;
    QMediaPlayer* snow;
    QMediaPlayer* green;
    QMediaPlayer* birdie;

    double xPoint;
    double yPoint;
    double xTrans;
    double yTrans;
    double direction = 1;
    double force = 1;
    int couptxt = 0;
    int indexParcours;
    Manette* manette;
    bool button1;
    void jouer();

protected:
    void keyPressEvent(QKeyEvent* event) override;

};