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



class MenuReglements : public QWidget
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
    //Ui::Labo1QTApp7Class ui;
    QVBoxLayout* m_layout;
    QLabel* m_labelLogo;
    QLabel* m_labelVersion;
    QLabel* m_labelDescription;
    QLabel* m_labelCreateur;
    //QPushButton* m_boutonFermer;
    QPushButton* b_retour;

};