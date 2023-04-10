#pragma once

#include <QtWidgets/QMainWindow>
#include <qapplication.h>
#include <qmenu.h>
#include <qaction.h>
#include <qpushbutton.h>
//#include <QMediaPlayer>
#include <QtWidgets/QTextEdit>
#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>



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

class MenuReglements : public QMainWindow
{
    Q_OBJECT

public:
    MenuReglements(QWidget* parent = nullptr);
    ~MenuReglements();

signals:
    void b_retour_appuyer();

private slots:
    void action_retour();

private:
    QTextEdit* texteTitre;
    QTextEdit* texteReglements;
    QPushButton* b_retour;
    QGraphicsDropShadowEffect* effectTitre;
    QGraphicsDropShadowEffect* effectReglements;

};