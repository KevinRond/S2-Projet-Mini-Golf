#include "MainMenu.h"

MainMenu::MainMenu(QWidget* parent)
    : QMainWindow(parent)
{
    //ui.setupUi(this);

    this->setFixedSize(1280, 720);
    setStyleSheet("QMainWindow{ background-image: url(../Graphic/BeauFond3.png); }");

    //Texte du titre
    texteTitre = new QTextEdit(this);
    texteTitre->setGeometry(240, 100, 800, 200);
    texteTitre->setPlainText("Menu Principale");
    texteTitre->setReadOnly(true);
    QString style_titre = "QTextEdit {"
        "font-family: Helvetica;"
        "font-size: 60px;"
        "color: white;"
        "background-color: transparent;"
        "border: none;"
        "}";
    texteTitre->setStyleSheet(style_titre);
    texteTitre->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    //Effet du titre
    effectTitre = new QGraphicsDropShadowEffect;
    effectTitre->setBlurRadius(5);
    effectTitre->setColor(Qt::black);
    effectTitre->setOffset(3, 3);
    texteTitre->setGraphicsEffect(effectTitre);

    //Set up des boutons
    b_jouer = new QPushButton("Jouer", this);
    //b_jouer->setFocusPolicy(Qt::StrongFocus);
    //b_jouer->setFocusPolicy(Qt::TabFocus);
    //b_jouer->setFocus();
    b_regle = new QPushButton("Regles", this);
    b_scoreboard = new QPushButton("Gagnant du prix Carl Carmoni", this);
    b_quit = new QPushButton("Quitter l'application", this);


    b_jouer->setGeometry(475, 200, 300, 150);
    b_jouer->setStyleSheet("QPushButton { border-image: url(../Graphic/BoutonOuvert1.png);"
                                    "font-family: Helvetica; "
                                    "font-weight: bold; "
                                    "font-size: 24px; "
                                    "color: white "
                                    "}"
        "QPushButton:hover, QPushButton:focus { border-image: url(../Graphic/BoutonSelect.png); }"
        "QPushButton:pressed { border-image: url(../Graphic/BoutonFermer1.png); }");
    b_regle->setGeometry(475, 300, 300, 150);
    b_regle->setStyleSheet("QPushButton { border-image: url(../Graphic/BoutonOuvert1.png);"
        "font-family: Helvetica; "
        "font-weight: bold; "
        "font-size: 24px; "
        "color: white "
        "}"
        "QPushButton:hover, QPushButton:focus { border-image: url(../Graphic/BoutonSelect.png); }"
        "QPushButton:pressed { border-image: url(../Graphic/BoutonFermer1.png); }");
    b_scoreboard->setGeometry(475, 400, 300, 150);
    b_scoreboard->setStyleSheet("QPushButton { border-image: url(../Graphic/BoutonOuvert1.png);"
        "font-family: Helvetica; "
        "font-weight: bold; "
        "font-size: 14px; "
        "color: white "
        "}"
        "QPushButton:hover, QPushButton:focus { border-image: url(../Graphic/BoutonSelect.png); }"
        "QPushButton:pressed { border-image: url(../Graphic/BoutonFermer1.png); }");
    b_quit->setGeometry(475, 500, 300, 150);
    b_quit->setStyleSheet("QPushButton { border-image: url(../Graphic/BoutonOuvert1.png);"
        "font-family: Helvetica; "
        "font-weight: bold; "
        "font-size: 20px; "
        "color: white "
        "}"
        "QPushButton:hover, QPushButton:focus { border-image: url(../Graphic/BoutonSelect.png); }"
        "QPushButton:pressed { border-image: url(../Graphic/BoutonFermer1.png); }");


    //Actions des boutons
    connect(b_jouer, &QPushButton::clicked, this, &MainMenu::action_jouer);
    connect(b_regle, &QPushButton::clicked, this, &MainMenu::action_regle);
    connect(b_scoreboard, &QPushButton::clicked, this, &MainMenu::action_scoreboard);
    connect(b_quit, &QPushButton::clicked, this, &QCoreApplication::quit);
}

MainMenu::~MainMenu()
{
    delete effectTitre;
    delete texteTitre;
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

void MainMenu::keyPressEvent(QKeyEvent* event)
{
    switch (event->key()) 
    {
    case Qt::Key_Left:
        // Handle left arrow key press
        break;
    case Qt::Key_Right:
        // Handle right arrow key press
        break;
    case Qt::Key_Up:
        if (b_quit->hasFocus()) {
            b_scoreboard->setFocus();
        }
        else if (b_scoreboard->hasFocus()) {
            b_regle->setFocus();
        }
        else if (b_regle->hasFocus()) {
            b_jouer->setFocus();
        }
        else {}
        break;
    case Qt::Key_Down:
        if (b_jouer->hasFocus()) {
            b_regle->setFocus();
        }
        else if (b_regle->hasFocus()) {
            b_scoreboard->setFocus();
        }
        else if (b_scoreboard->hasFocus()) {
            b_quit->setFocus();
        }
        else {}
        break;
    
    case Qt::Key_Enter || Qt::Key_Return:
        if (b_jouer->hasFocus()) {
            action_jouer();
        }
        else if (b_regle->hasFocus()) {
            action_regle();
        }
        else if (b_scoreboard->hasFocus()) {
            action_scoreboard();
        }
        break;
    default:
        QWidget::keyPressEvent(event);
    }

    event->accept();
}
