#include "TitleScreen.h"

TitleScreen::TitleScreen(QWidget* parent)
    : QMainWindow(parent)
{
    //ui.setupUi(this);

    this->resize(1280, 720);

    MainButton = new QPushButton("MINI-GOLF AAAAH", this);
    MainButton->setGeometry(460, 300, 360, 120);
    QString buttonStyle = "QPushButton {"
        "font-family: Papyrus;"
        "font-size: 24px;"
        "}";

    MainButton->setStyleSheet(buttonStyle);

    connect(MainButton, &QPushButton::clicked, this, &TitleScreen::switchMenus);
}

TitleScreen::~TitleScreen()
{
    delete MainButton;
}

void TitleScreen::switchMenus() 
{
    emit buttonClicked();
}