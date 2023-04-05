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


class TitleScreen : public QMainWindow
{
    Q_OBJECT

public:
    TitleScreen(QWidget* parent = nullptr);
    ~TitleScreen();

signals:
    void buttonClicked();

private slots:
    void switchMenus();

private:
    //Ui::QTLabo1Class ui;
    QPushButton* MainButton;
};