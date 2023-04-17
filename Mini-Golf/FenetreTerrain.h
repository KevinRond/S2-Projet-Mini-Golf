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

#include "Manette.h"

#define M_PI 3.14159265

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
    void jouer();

private:
    QTextEdit* texteTitre;
    QTextEdit* nomfichier;
    QLabel* forceText;
    QLabel* directionText;
    QLabel* finalCoupText;
    QLabel* finCoupText;
    QLabel* coupText;
    QPushButton* b_retour;
    QString nom_fichier_terrain;
    QLabel* balle;
    Terrain* terrain1;
    QDialog* reussi;
    QDialog* fin;
    QLabel* point;
    QLabel* finiFinalText;

    QGraphicsDropShadowEffect* effect_etiquette_force;
    QGraphicsDropShadowEffect* effect_etiquette_direction;
    QGraphicsDropShadowEffect* effect_etiquette_coup;

    double xPoint;
    double yPoint;
    double xTrans;
    double yTrans;
    double direction = 0;
    double force = 0;
    int couptxt = 0;
    int indexParcours;
    Manette* manette;
    Coup* coup;
    bool button1;

protected:
    void keyPressEvent(QKeyEvent* event) override;

};