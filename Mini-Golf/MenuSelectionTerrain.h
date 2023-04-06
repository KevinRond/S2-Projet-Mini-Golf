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
    
private slots:
    void action_retour();
    void action_terrain1();
    void action_terrain2();
    void action_terrain3();

private:
    QTextEdit* texteTitre;
    QPushButton* b_retour;
    QPushButton* b_terrain1;
    QPushButton* b_terrain2;
    QPushButton* b_terrain3;
    
};