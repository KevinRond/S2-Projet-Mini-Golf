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

class MenuScoreboard : public QMainWindow
{
    Q_OBJECT

public:
    MenuScoreboard(QWidget* parent = nullptr);
    ~MenuScoreboard();

signals:
    void b_retour_appuyer();

private slots:
    void action_retour();

private:
    QTextEdit* texteTitre;
    QPushButton* b_retour;

};