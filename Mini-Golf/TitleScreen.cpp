#include "TitleScreen.h"

TitleScreen::TitleScreen(QWidget* parent)
    : QMainWindow(parent)
{
    //ui.setupUi(this);

    this->setFixedSize(1280, 720);

    //Texte du titre
    texteTitre = new QTextEdit(this);
    texteTitre->setGeometry(460, 200, 360, 80);
    texteTitre->setPlainText("Mini-G");
    texteTitre->setReadOnly(true);
    QString style_titre = "QTextEdit {"
        "font-family: Helvetica;"
        "font-size: 60px;"
        "background-color: transparent;"
        "border: none;"
        "}";
    texteTitre->setStyleSheet(style_titre);
    texteTitre->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    

    //Texte du sous-titre
    soustitre = new QTextEdit(this);
    soustitre->setGeometry(460, 280, 360, 60);
    soustitre->setPlainText("par R2P2");
    soustitre->setReadOnly(true);
    QString style_soustitre = "QTextEdit {"
        "font-family: Helvetica;"
        "font-size: 24px;"
        "background-color: transparent;"
        "border: none;"
        "}";
    soustitre->setStyleSheet(style_soustitre);
    soustitre->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);


    //Set up du bouton
    MainButton = new QPushButton("Appuyer pour commencer", this);
    MainButton->setGeometry(460, 400, 360, 70);
    //MainButton->setStyleSheet(buttonStyle);

    connect(MainButton, &QPushButton::clicked, this, &TitleScreen::switchMenus);
}

TitleScreen::~TitleScreen()
{
    delete MainButton;
    delete texteTitre;
}


void TitleScreen::switchMenus() 
{
    emit buttonClicked();
}