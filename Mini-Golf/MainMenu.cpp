#include "MainMenu.h"

MainMenu::MainMenu(QWidget* parent)
    : QMainWindow(parent), fichier(nullptr), edition(nullptr), ouvrir(nullptr), fermer(nullptr), trouver(nullptr),
    button1(nullptr), zoneTexte(nullptr)
{
    //ui.setupUi(this);

    this->resize(1280, 720);
    //this->setFixedSize(450, 350);

    /*ListeMenus = new QStackedWidget(this);
    menu1 = new QWidget(this);
    menu2 = new QWidget(this);
    ListeMenus->addWidget(menu1);
    ListeMenus->addWidget(menu2);*/

    /*layout1 = new QVBoxLayout(this);
    layout1->addWidget(menu1);*/

    //menuBar = new QMenuBar(this);

    fichier = new QMenu;
    fichier = menuBar()->addMenu("Fichier");
    edition = new QMenu;
    edition = menuBar()->addMenu("Edition");

    //layout->addWidget(menuBar);

    ouvrir = new QAction("Ouvrir", this);
    fermer = new QAction("Fermer", this);
    trouver = new QAction("Trouver", this);

    fichier->addAction(ouvrir);
    fichier->addAction(fermer);
    edition->addAction(trouver);

    button1 = new QPushButton("Cliquez ici", this);
    button1->setToolTip("Clickety click click");
    button1->setGeometry(350, 310, 80, 30);

    zoneTexte = new QTextEdit(this);
    zoneTexte->setGeometry(40, 50, 370, 250);
    //zoneTexte->setText("Laurence");

    textFixe = new QTextEdit(this);
    textFixe->setGeometry(40, 25, 370, 25);
    textFixe->setPlainText("Texte associe aux actions");
    textFixe->setReadOnly(true);
    textFixe->setStyleSheet("background-color: #F8F8F8; border: none;");

    /*layout1->addWidget(fichier);
    layout1->addWidget(edition);
    layout1->addWidget(button1);
    layout1->addWidget(zoneTexte);
    layout1->addWidget(textFixe);*/

    connect(ouvrir, &QAction::triggered, this, &MainMenu::updateTextOuvrir);
    connect(fermer, &QAction::triggered, this, &MainMenu::updateTextFermer);
    connect(trouver, &QAction::triggered, this, &MainMenu::updateTextTrouver);
    connect(button1, &QPushButton::clicked, this, &MainMenu::updateTextButton);

}

MainMenu::~MainMenu()
{
    delete textFixe;
    delete zoneTexte;
    delete button1;
    delete trouver;
    delete fermer;
    delete ouvrir;
    delete edition;
    delete fichier;
}

void MainMenu::updateTextOuvrir()
{
    zoneTexte->append("Action : Fichier/Ouvrir");
}

void MainMenu::updateTextFermer()
{
    zoneTexte->append("Action : Fichier/Fermer");
}

void MainMenu::updateTextTrouver()
{
    zoneTexte->append("Action : Edition/Trouver");
}

void MainMenu::updateTextButton()
{
    zoneTexte->append("Action : Button");
    emit buttonClicked();
}