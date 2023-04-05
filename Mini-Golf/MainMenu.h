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


class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    MainMenu(QWidget* parent = nullptr);
    ~MainMenu();

signals:
    void buttonClicked();

private slots:
    void updateTextButton();
    void updateTextOuvrir();
    void updateTextFermer();
    void updateTextTrouver();

private:
    //Ui::QTLabo1Class ui;
    QMenu* fichier;
    QMenu* edition;
    QAction* ouvrir;
    QAction* fermer;
    QAction* trouver;
    QPushButton* button1;
    QTextEdit* zoneTexte;
    QTextEdit* textFixe;
    //QMenuBar* menuBar;
};