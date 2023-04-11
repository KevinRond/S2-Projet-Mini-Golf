#ifndef MENUSELECTIONTERRAIN_H
#define MENUSELECTIONTERRAIN_H

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
#include <QGraphicsDropShadowEffect>
#include <QKeyEvent>
#include <QShowEvent>


class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    MainMenu(QWidget* parent = nullptr);
    ~MainMenu();

signals:
    void b_jouer_appuyer();
    void b_regle_appuyer();
    void b_scoreboard_appuyer();

private slots:
    void action_jouer();
    void action_regle();
    void action_scoreboard();

protected:
    void keyPressEvent(QKeyEvent* event) override;

private:
    QTextEdit* texteTitre;                          //Zone de texte du titre
    QPushButton* b_jouer;                           //Bouton jouer
    QPushButton* b_regle;                           //Bouton reglements
    QPushButton* b_scoreboard;                      //Bouton Scoreboard
    QPushButton* b_quit;                            //Bouton quitter
    QGraphicsDropShadowEffect* effectTitre;         //Effet du titre
};

#endif