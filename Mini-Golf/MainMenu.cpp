#include "MainMenu.h"

MainMenu::MainMenu(QWidget* parent)
    : QMainWindow(parent)
{
    //ui.setupUi(this);

    this->setFixedSize(1280, 720);

    b_jouer = new QPushButton("Jouer", this);
    b_regle = new QPushButton("Regles", this);
    b_scoreboard = new QPushButton("Gagnant du prix Carl Carmoni", this);
    b_quit = new QPushButton("Quitter l'application", this);

    b_jouer->setGeometry(540, 200, 200, 50);
    b_regle->setGeometry(540, 300, 200, 50);
    b_scoreboard->setGeometry(540, 400, 200, 50);
    b_quit->setGeometry(540, 500, 200, 50);
    
    connect(b_jouer, &QPushButton::clicked, this, &MainMenu::action_jouer);
    connect(b_regle, &QPushButton::clicked, this, &MainMenu::action_regle);
    connect(b_scoreboard, &QPushButton::clicked, this, &MainMenu::action_scoreboard);
    connect(b_quit, &QPushButton::clicked, this, &QCoreApplication::quit);
}

MainMenu::~MainMenu()
{
    delete b_jouer;
    delete b_regle;
    delete b_scoreboard;
    delete b_quit;
}

void MainMenu::action_jouer()
{
    emit b_jouer_appuyer();
}

void MainMenu::action_regle()
{
    emit b_regle_appuyer();
}

void MainMenu::action_scoreboard()
{
    emit b_scoreboard_appuyer();
}
