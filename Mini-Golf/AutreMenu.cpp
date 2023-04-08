#include "AutreMenu.h"


AutreMenu::AutreMenu(QWidget* parent)
	: QMainWindow(parent)
{
	this->setFixedSize(1280, 720);

	b_quit = new QPushButton("Quitter", this);
	b_quit->setGeometry(490, 400, 300, 150);
	b_quit->setStyleSheet("QPushButton { border-image: url(../Graphic/BoutonOuvert1.png); }"
		"QPushButton:hover { border-image: url(../Graphic/BoutonSelect.png); }"
		"QPushButton:pressed { border-image: url(../Graphic/BoutonFermer1.png); }");

	b_retour = new QPushButton("Retour", this);
	b_retour->setGeometry(490, 200, 300, 150);
	b_retour->setStyleSheet("QPushButton { border-image: url(../Graphic/BoutonOuvert1.png); }"
		"QPushButton:hover { border-image: url(../Graphic/BoutonSelect.png); }"
		"QPushButton:pressed { border-image: url(../Graphic/BoutonFermer1.png); }");


	connect(b_retour, &QPushButton::released, this, &AutreMenu::action_retour);
	connect(b_quit, &QPushButton::released, this, &QCoreApplication::quit);

	
}

AutreMenu::~AutreMenu()
{

}



void AutreMenu::action_retour()
{
	emit b_retour_appuyer();
}


void AutreMenu::action_lancer()
{

}
