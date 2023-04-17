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
    texteTitre->setPlainText("Menu Principal");
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
    b_regle = new QPushButton("Regles", this);
    b_scoreboard = new QPushButton("Commandes", this);
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
        "font-size: 24px; "
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

    // Set the focus policy of the widget to accept keyboard focus
    setFocusPolicy(Qt::StrongFocus);
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

//void MainMenu::launch_Manette()
//{
//    qApp->processEvents();
//    Manette* manette = new Manette("com7");
//    
//
//    manette->demande(2, 9);
//    manette->button1 = false;
//    while (!manette->getButton1())
//    {
//        manette->communication();
//        if (manette->getButton2() || manette->getButton3()) {
//            // Find the currently focused button
//            QPushButton* currentButton = qobject_cast<QPushButton*>(focusWidget());
//            if (currentButton == nullptr) {
//                // If no button is focused, set focus to the first button
//                QWidget* firstChild = findChild<QPushButton*>(); // Find the first QPushButton child
//                if (firstChild != nullptr) {
//                    firstChild->setFocus();
//                    qApp->processEvents();
//                    Sleep(100);
//                }
//            }
//            else {
//                // Find the next or previous button depending on the key press
//                QPushButton* nextButton = nullptr;
//                if (manette->getButton3()) {
//                    nextButton = qobject_cast<QPushButton*>(currentButton->nextInFocusChain());
//                    qApp->processEvents();
//                }
//                else {
//                    nextButton = qobject_cast<QPushButton*>(currentButton->previousInFocusChain());
//                    qApp->processEvents();
//                }
//                if (nextButton != nullptr) {
//                    // Set focus to the next or previous button
//                    nextButton->setFocus();
//                    qApp->processEvents();
//                }
//                Sleep(100);
//            }
//        }
//        else if (manette->getButton1()) {
//            // Handle enter key press
//            QPushButton* currentButton = qobject_cast<QPushButton*>(focusWidget());
//            if (currentButton != nullptr) {
//                // Trigger the clicked signal of the currently focused button
//                QMetaObject::invokeMethod(currentButton, "click", Qt::QueuedConnection);
//                qApp->processEvents();
//                Sleep(100);
//            }
//        }
//        else if (manette->getButton4()) {
//            // Handle backspace key press
//            &QCoreApplication::quit;
//        }
//
//    }
//    delete manette;
//}

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
