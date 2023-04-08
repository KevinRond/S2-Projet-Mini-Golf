#include "Interface.h"

using namespace std;

Labo1QTApp7::Labo1QTApp7(QWidget* parent)
    : QMainWindow(parent)
{
    //ui.setupUi(this);

    this->resize(1280,720);

	listeMenu = new QStackedWidget(this);
	autreMenu = new AutreMenu(this);
	testAcceuil = new TestAcceuil(this);

	listeMenu->addWidget(testAcceuil);
	listeMenu->addWidget(autreMenu);

	listeMenu->setCurrentWidget(testAcceuil);

	//action test acceuil

	connect(testAcceuil, &TestAcceuil::b_autreMenu_appuyer, [this]() {listeMenu->setCurrentWidget(listeMenu->widget(1)); });

	//action autremenu

	connect(autreMenu, &AutreMenu::b_retour_appuyer, [this]() {listeMenu->setCurrentWidget(listeMenu->widget(0)); });

	setCentralWidget(listeMenu);

    /*QPushButton* button = new QPushButton("Play",this);
    button->setGeometry(490, 300, 300, 150);
    button->setStyleSheet("QPushButton { border-image: url(../Graphic/BoutonOuvert1.png); }"
		"QPushButton:hover { border-image: url(../Graphic/BoutonSelect.png); }"
        "QPushButton:pressed { border-image: url(../Graphic/BoutonFermer1.png); }");

	QPushButton* button1 = new QPushButton("Jouer", this);
	button1->setGeometry(490, 200, 300, 150);
	button1->setStyleSheet("QPushButton { border-image: url(../Graphic/BoutonOuvert1.png); }"
		"QPushButton:hover { border-image: url(../Graphic/BoutonSelect.png); }"
		"QPushButton:pressed { border-image: url(../Graphic/BoutonFermer1.png); }");
    
	QPushButton* button2 = new QPushButton("Coup", this);
	button2->setGeometry(490, 400, 300, 150);
	button2->setStyleSheet("QPushButton { border-image: url(../Graphic/BoutonOuvert1.png); }"
		"QPushButton:hover { border-image: url(../Graphic/BoutonSelect.png); }"
		"QPushButton:pressed { border-image: url(../Graphic/BoutonFermer1.png); }" 
	);


	

    textEdit = new QTextEdit(this);
    textEdit->setGeometry(0, 40, 300, 300);

    connect(button, &QPushButton::released, this, &Labo1QTApp7::afficherMessage);
	connect(button1, &QPushButton::released, this, &Labo1QTApp7::terrain);

    setStyleSheet("QMainWindow{ background-image: url(../Graphic/BeauFond3.png); }");
    textEdit->setStyleSheet("background-color:white");*/
    //button->setStyleSheet("background-color:green");

 
}

Labo1QTApp7::~Labo1QTApp7()
{
	delete listeMenu;
//	delete autreMenu;
	//delete testAcceuil;
}

void Labo1QTApp7::terrain()
{
	QLabel* balle = new QLabel("Balle",this);
	QPixmap pixmap("../Graphic/Ball.png");
	balle->setPixmap(pixmap);
	Terrain* terrain1 = new Terrain;
	terrain1->OpenTerrain("Terrain2.txt");
	terrain1->Display();
	string direction;
	string force;
	double Ox = terrain1->getOx();
	double Oy = terrain1->getOy();
	balle->setGeometry(round(Ox),round(720 - Oy), pixmap.width(), pixmap.height());
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
	//while (terrain1->verifTrou() == false)
	//{
	//	
	//	//cout << "NOMBRE DE COUP: " << terrain1->getCOup() << endl;
	//	cout << "entrer la direction de la balle" << endl;
	//	cin >> direction;
	//	cout << "enter la puissance" << endl;
	//	cin >> force;
	//	double forced = stod(force);
	//	double directiond = stod(direction);
	//	Coup coup1(directiond, forced);
	//	terrain1->CoupDonne(coup1);

	//	//cout << "NOMBRE DE RICOCHET: " << terrain1->getCOup() << endl;
	//}
	//cout << "BRAVOOOOOOOO" << endl;
}

//void Labo1QTApp7::afficherMessage()
//{
//    textEdit->append("Bravo tu sais appuyer sur un bouton");
//}