#include "Interface.h"

Interface::Interface(QWidget* parent)
    : QMainWindow(parent)
{
    //ui.setupUi(this);

    this->resize(1280, 720);
    
    listeMenus = new QStackedWidget(this);
    titleScreen = new TitleScreen(this);
    menuPrincipal = new MainMenu(this);

    listeMenus->addWidget(titleScreen);
    listeMenus->addWidget(menuPrincipal);

    listeMenus->setCurrentWidget(titleScreen);
    connect(titleScreen, &TitleScreen::buttonClicked, [this]() {
        listeMenus->setCurrentWidget(listeMenus->widget(1));
        });
    connect(menuPrincipal, &MainMenu::buttonClicked, [this]() {
        listeMenus->setCurrentWidget(listeMenus->widget(0));
        });

    setCentralWidget(listeMenus);


}

Interface::~Interface()
{
    delete menuPrincipal;
    delete titleScreen;
    delete listeMenus;
}

