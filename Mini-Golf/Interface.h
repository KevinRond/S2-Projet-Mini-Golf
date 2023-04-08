#pragma once
#pragma once

#include <QtWidgets/QMainWindow>
#include <qapplication.h>
#include <qmenu.h>
#include <qmenubar.h>
#include <qaction.h>
#include <qpushbutton.h>
#include <QtGui>
#include <Qlabel>
#include <vector>
#include <QstackedWidget>


#include "Terrain.h"
#include "Parcours.h"
#include "AutreMenu.h"
#include "TestAcceuil.h"
//#include <QMediaPlayer>
#include <QtWidgets/QTextEdit>



class Labo1QTApp7 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Labo1QTApp7(QWidget* parent = nullptr);
    ~Labo1QTApp7();
    void SetUpAcceuil();
    void MainMenu();

private slots: 

    //void afficherMessage();
    void terrain();

private:
    //Ui::Labo1QTApp7Class ui;
    QStackedWidget* listeMenu;
    AutreMenu* autreMenu;
    TestAcceuil* testAcceuil;
    
};