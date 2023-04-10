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

private:
    QTextEdit* texteTitre;
    QPushButton* b_jouer;
    QPushButton* b_regle;
    QPushButton* b_scoreboard;
    QPushButton* b_quit;
    QGraphicsDropShadowEffect* effectTitre;
};

#endif