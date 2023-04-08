#include "TestAcceuil.h"

using namespace std;

TestAcceuil::TestAcceuil(QWidget* parent)
	:QMainWindow(parent)
{
	this->setFixedSize(1280, 720);

	b_play = new QPushButton("Play", this);
	b_play->setGeometry(490, 300, 300, 150);
	b_play->setStyleSheet("QPushButton { border-image: url(../Graphic/BoutonOuvert1.png); }"
		"QPushButton:hover { border-image: url(../Graphic/BoutonSelect.png); }"
		"QPushButton:pressed { border-image: url(../Graphic/BoutonFermer1.png); }");

	b_jouer = new QPushButton("Jouer", this);
	b_jouer->setGeometry(490, 200, 300, 150);
	b_jouer->setStyleSheet("QPushButton { border-image: url(../Graphic/BoutonOuvert1.png); }"
		"QPushButton:hover { border-image: url(../Graphic/BoutonSelect.png); }"
		"QPushButton:pressed { border-image: url(../Graphic/BoutonFermer1.png); }");

	b_autreMenu = new QPushButton("AutreMenu", this);
	b_autreMenu->setGeometry(490, 400, 300, 150);
	b_autreMenu->setStyleSheet("QPushButton { border-image: url(../Graphic/BoutonOuvert1.png); }"
		"QPushButton:hover { border-image: url(../Graphic/BoutonSelect.png); }"
		"QPushButton:pressed { border-image: url(../Graphic/BoutonFermer1.png); }");

	connect(b_autreMenu, &QPushButton::released, this, &TestAcceuil::action_autreMenu);
	connect(b_jouer, &QPushButton::released, this, &TestAcceuil::action_jouer);
	connect(b_play, &QPushButton::released, this, &TestAcceuil::action_play);


	textEdit = new QTextEdit(this);
	textEdit->setGeometry(0, 40, 300, 300);

	setStyleSheet("QMainWindow{ background-image: url(../Graphic/BeauFond3.png); }");


}

TestAcceuil::~TestAcceuil()
{
	
}

void TestAcceuil::action_play()
{
	QLabel* balle = new QLabel("Balle", this);
	QPixmap pixmap("../Graphic/Ball.png");
	balle->setPixmap(pixmap);
	Terrain* terrain1 = new Terrain;
	terrain1->OpenTerrain("Terrain2.txt");
	terrain1->Display();
	string direction;
	string force;
	double Ox = terrain1->getOx();
	double Oy = terrain1->getOy();
	balle->setGeometry(round(Ox), round(720 - Oy), pixmap.width(), pixmap.height());
	balle->show();
	vector<pair<double, double>> parcourVec;
	Parcours parcour;
	Coup coup1(45, 100);
	parcour = terrain1->CoupDonne(coup1);
	parcourVec = parcour.GetCoorXY();
	for (const auto& coord : parcourVec)
	{
		int x = round(coord.first);
		int y = round(coord.second);
		balle->move(x, y);
		qApp->processEvents();
		Sleep(50);
	}
}

void TestAcceuil::action_autreMenu()
{
	emit b_autreMenu_appuyer();
}

void TestAcceuil::action_jouer()
{
	textEdit->append("Bravo tu sais appuyer sur un bouton");
}
