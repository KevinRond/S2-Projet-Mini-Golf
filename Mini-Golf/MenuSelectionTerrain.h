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
    
};