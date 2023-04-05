#include "Interface.h"

Labo1QTApp7::Labo1QTApp7(QWidget* parent)
    : QMainWindow(parent)
{
    //ui.setupUi(this);

    this->resize(1280,720);

    QPushButton* button = new QPushButton("Play",this);
    button->setIcon(QIcon(".. / Graphic / Bouton.png"));
    button->setIconSize(QSize(50,50));
    button->setGeometry(400, 400, 300, 150);
    button->setStyleSheet("QPushButton { border-image: url(../Graphic/BoutonOuvert.png); }"
        "QPushButton:pressed { border-image: url(../Graphic/BoutonFermer.png); }");
    
    

    textEdit = new QTextEdit(this);
    textEdit->setGeometry(0, 40, 300, 300);

    connect(button, &QPushButton::released, this, &Labo1QTApp7::afficherMessage);

    setStyleSheet("QMainWindow{ background-image: url(../Graphic/MainMenu.png); }");
    textEdit->setStyleSheet("background-color:white");
    //button->setStyleSheet("background-color:green");


}

Labo1QTApp7::~Labo1QTApp7()
{}

void Labo1QTApp7::afficherMessage()
{
    textEdit->append("Bravo tu sais appuyer sur un bouton");
}