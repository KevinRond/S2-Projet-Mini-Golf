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
#include <QKeyEvent>
#include <QLabel>
#include <QGraphicsDropShadowEffect>

#include <iostream>

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
    

protected:
    void keyPressEvent(QKeyEvent* event) override;

private:
    QTextEdit* texteTitre;              //Zone de texte du titre
    QTextEdit* nomfichier;              
    QPushButton* b_retour;              //Bouton retour
    QString nom_fichier_terrain;        //QString qui store le fichier terrain a generer
    QLabel* etiquette_force;
    QLabel* etiquette_direction;
    QGraphicsDropShadowEffect* effect_etiquette_force;
    QGraphicsDropShadowEffect* effect_etiquette_direction;

    int force_coup;
    int direction_coup;

};