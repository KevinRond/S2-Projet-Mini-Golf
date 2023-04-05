#include "Interface.h"

Labo1QTApp7::Labo1QTApp7(QWidget* parent)
    : QMainWindow(parent)
{
    //ui.setupUi(this);

    this->resize(500, 500);

    fichier = new QMenu;
    //fichier = menuBar()->addMenu(tr("&Fichier"));
    edition = new QMenu;
    //edition = menuBar()->addMenu(tr("&Edition"));


    ouvrir = new QAction(tr("&Ouvrir"), this);
    fermer = new QAction(tr("&Fermer"), this);
    trouver = new QAction(tr("&Trouver"), this);

    fichier->addAction(ouvrir);
    fichier->addAction(fermer);
    edition->addAction(trouver);

    button = new QPushButton("Cliquer ici", this);
    button->setGeometry(400, 400, 100, 50);

    textEdit = new QTextEdit(this);
    textEdit->setGeometry(0, 40, 300, 300);

    connect(button, &QPushButton::released, this, &Labo1QTApp7::afficherMessage);

   // setStyleSheet("QMainWindow{ background-image: url(C:/Users/alexi/source/repos/Labo1QTApp7/golf.png); }");
    textEdit->setStyleSheet("background-color:white");
    button->setStyleSheet("background-color:green");


}

Labo1QTApp7::~Labo1QTApp7()
{}

void Labo1QTApp7::afficherMessage()
{
    textEdit->append("Bravo tu sais appuyer sur un bouton");
}