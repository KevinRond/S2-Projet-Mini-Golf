#pragma once
#pragma once

#include <QtWidgets/QMainWindow>
#include <qapplication.h>
#include <qmenu.h>
#include <qaction.h>
#include <qpushbutton.h>
//#include <QMediaPlayer>
#include <QtWidgets/QTextEdit>



class Labo1QTApp7 : public QMainWindow
{
    Q_OBJECT

public:
    Labo1QTApp7(QWidget* parent = nullptr);
    ~Labo1QTApp7();
    void afficherMessage();

private:
    //Ui::Labo1QTApp7Class ui;
    QMenu* fichier;
    QMenu* edition;
    QAction* ouvrir;
    QAction* fermer;
    QAction* trouver;
    QPushButton* button;
    QTextEdit* textEdit;
};