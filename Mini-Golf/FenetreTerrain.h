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
#include <QGraphicsDropShadowEffect>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QTransform>

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

private slots:
    void action_retour();
    void affiche_nom_fichier();

private:
    QTextEdit* texteTitre;
    QTextEdit* nomfichier;
    QLabel* forceText;
    QLabel* directionText;
    QPushButton* b_retour;
    QString nom_fichier_terrain;
    QLabel* balle;
    Terrain* terrain1;
    QLabel* etiquette_force;
    QLabel* etiquette_direction;
    QGraphicsDropShadowEffect* effect_etiquette_force;
    QGraphicsDropShadowEffect* effect_etiquette_direction;

    QLabel* point;
    QTransform ninetydeg;
    QTransform onedeg;
    QTransform angleFleche;

    int transformIndex;


    double xPoint;
    double yPoint;

    double xTrans;
    double yTrans;
    double direction;
    double force;
    int indexParcours;

protected:
    void keyPressEvent(QKeyEvent* event) override;

};