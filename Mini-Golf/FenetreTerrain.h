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

#include "Manette.h"

class FenetreTerrain : public QMainWindow
{
    Q_OBJECT

public:
    FenetreTerrain(QWidget* parent = nullptr);
    ~FenetreTerrain();
    void set_file_name(QString file_name);
    QString get_file_name();

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
    QPushButton* b_retour;
    QString nom_fichier_terrain;
    QLabel* balle;
    Terrain* terrain1;
    QDialog* reussi;
    QDialog* fin;
    double xTrans;
    double yTrans;
    double direction = 1;
    double force = 1;
    int indexParcours;
    Manette* manette;
    bool button1;

protected:
    void keyPressEvent(QKeyEvent* event) override;

};