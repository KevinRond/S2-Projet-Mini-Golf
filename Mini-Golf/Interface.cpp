#include "Interface.h"

Interface::Interface(QWidget* parent)
    : QMainWindow(parent)
{
    //ui.setupUi(this);

    this->resize(1280, 720);
    
    //Initialisation des widgets et insertion dans la liste des menus "listeMenus"
    listeMenus = new QStackedWidget(this);
    titleScreen = new TitleScreen(this);
    menuPrincipal = new MainMenu(this);
    menuSelectionTerrain = new MenuSelectionTerrain(this);
    menuScoreboard = new MenuScoreboard(this);
    menuReglements = new MenuReglements(this);
    fenetreTerrain = new FenetreTerrain(this);

    listeMenus->addWidget(titleScreen);
    listeMenus->addWidget(menuPrincipal);
    listeMenus->addWidget(menuSelectionTerrain);
    listeMenus->addWidget(menuScoreboard);
    listeMenus->addWidget(menuReglements);
    listeMenus->addWidget(fenetreTerrain);

    listeMenus->setCurrentWidget(titleScreen);
    
    //Actions de l'ecran d'accueil
    connect(titleScreen, &TitleScreen::buttonClicked, [this]() {
        listeMenus->setCurrentWidget(listeMenus->widget(1));
        //menuPrincipal->launch_Manette();
        });

    //Actions du menu principal
    connect(menuPrincipal, &MainMenu::b_jouer_appuyer, [this]() {
        listeMenus->setCurrentWidget(listeMenus->widget(2));
        //menuSelectionTerrain->launch_Manette();
        });
    connect(menuPrincipal, &MainMenu::b_scoreboard_appuyer, [this]() {
        listeMenus->setCurrentWidget(listeMenus->widget(3));
        });
    connect(menuPrincipal, &MainMenu::b_regle_appuyer, [this]() {
        listeMenus->setCurrentWidget(listeMenus->widget(4));
        });

    //Actions du menu de selection de terrain
    connect(menuSelectionTerrain, &MenuSelectionTerrain::b_retour_appuyer, [this]() {
        listeMenus->setCurrentWidget(listeMenus->widget(1));
        });
    connect(menuSelectionTerrain, &MenuSelectionTerrain::b_terrain1_appuyer, [this]() {
        listeMenus->setCurrentWidget(listeMenus->widget(5));
        fenetreTerrain->set_file_name("Terrain1");
        });
    connect(menuSelectionTerrain, &MenuSelectionTerrain::b_terrain2_appuyer, [this]() {
        listeMenus->setCurrentWidget(listeMenus->widget(5));
        fenetreTerrain->set_file_name("Terrain2");
        });
    connect(menuSelectionTerrain, &MenuSelectionTerrain::b_terrain3_appuyer, [this]() {
        listeMenus->setCurrentWidget(listeMenus->widget(5));
        fenetreTerrain->set_file_name("Terrain3");
        });
    connect(menuSelectionTerrain, &MenuSelectionTerrain::b_terrain4_appuyer, [this]() {
        listeMenus->setCurrentWidget(listeMenus->widget(5));
        fenetreTerrain->set_file_name("Terrain4");
        });
    connect(menuSelectionTerrain, &MenuSelectionTerrain::b_terrain5_appuyer, [this]() {
        listeMenus->setCurrentWidget(listeMenus->widget(5));
        fenetreTerrain->set_file_name("Terrain5");
        });
    connect(menuSelectionTerrain, &MenuSelectionTerrain::b_terrain6_appuyer, [this]() {
        listeMenus->setCurrentWidget(listeMenus->widget(5));
        fenetreTerrain->set_file_name("Terrain6");
        });
    connect(menuSelectionTerrain, &MenuSelectionTerrain::b_terrain7_appuyer, [this]() {
        listeMenus->setCurrentWidget(listeMenus->widget(5));
        fenetreTerrain->set_file_name("Terrain7");
        });
    connect(menuSelectionTerrain, &MenuSelectionTerrain::b_terrain8_appuyer, [this]() {
        listeMenus->setCurrentWidget(listeMenus->widget(5));
        fenetreTerrain->set_file_name("Terrain8");
        });

    //Actions du menu de fenetre terrain
    connect(fenetreTerrain, &FenetreTerrain::b_retour_appuyer, [this]() {
        listeMenus->setCurrentWidget(listeMenus->widget(2));
        });
    
    connect(fenetreTerrain, &FenetreTerrain::b_fin_appuyer, [this]() {
        listeMenus->setCurrentWidget(listeMenus->widget(1));
        });

    //Actions du menu scoreboard
    connect(menuScoreboard, &MenuScoreboard::b_retour_appuyer, [this]() {
        listeMenus->setCurrentWidget(listeMenus->widget(1));
        });

    //Actions du menu reglements 
    connect(menuReglements, &MenuReglements::b_retour_appuyer, [this]() {
        listeMenus->setCurrentWidget(listeMenus->widget(1));
        });



    setCentralWidget(listeMenus);
}

Interface::~Interface()
{
    delete menuPrincipal;
    delete titleScreen;
    delete menuSelectionTerrain;
    delete menuReglements;
    delete fenetreTerrain;
    delete listeMenus;
}


