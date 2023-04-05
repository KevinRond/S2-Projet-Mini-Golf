#pragma once


//#include "ui_QTLabo1.h"
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
#include "TitleScreen.h"
#include "MainMenu.h"


class Interface : public QMainWindow
{
    Q_OBJECT

public:
    Interface(QWidget* parent = nullptr);
    ~Interface();

private slots:
    

private:
    //Ui::QTLabo1Class ui;
    QStackedWidget* listeMenus;
    TitleScreen* titleScreen;
    MainMenu* menuPrincipal;
};