#include "MenuSelectionTerrain.h"

using namespace std;

MenuSelectionTerrain::MenuSelectionTerrain(QWidget* parent)
    : QMainWindow(parent)
{
    //ui.setupUi(this);

    this->setFixedSize(1280, 720);
    setStyleSheet("QMainWindow{ background-image: url(../Graphic/BeauFond3.png); }");

    texteTitre = new QTextEdit(this);
    texteTitre->setGeometry(240, 100, 800, 200);
    texteTitre->setPlainText("Selection Terrain");
    texteTitre->setReadOnly(true);
    QString style_titre = "QTextEdit {"
        "font-family: Helvetica;"
        "font-size: 60px;"
        "background-color: transparent;"
        "border: none;"
        "}";
    texteTitre->setStyleSheet(style_titre);
    texteTitre->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    b_retour = new QPushButton("Retour", this);
    b_retour->setGeometry(1080, 620, 200, 100);
    b_retour->setStyleSheet("QPushButton { border-image: url(../Graphic/BoutonOuvert1.png);"
        "font-family: Helvetica; "
        "font-weight: bold; "
        "font-size: 16px; "
        "color: white "
        "}"
        "QPushButton:hover { border-image: url(../Graphic/BoutonSelect.png); }"
        "QPushButton:pressed { border-image: url(../Graphic/BoutonFermer1.png); }");

    b_terrain1 = new QPushButton("Terrain 1", this);
    b_terrain2 = new QPushButton("Terrain 2", this);
    b_terrain3 = new QPushButton("Terrain 3", this);
    b_terrain1->setGeometry(440, 300, 100, 100);
    b_terrain2->setGeometry(590, 300, 100, 100);
    b_terrain3->setGeometry(740, 300, 100, 100);

    connect(b_retour, &QPushButton::clicked, this, &MenuSelectionTerrain::action_retour);
    connect(b_terrain1, &QPushButton::clicked, this, &MenuSelectionTerrain::action_terrain1);
    connect(b_terrain2, &QPushButton::clicked, this, &MenuSelectionTerrain::action_terrain2);
    connect(b_terrain3, &QPushButton::clicked, this, &MenuSelectionTerrain::action_terrain2);

}

MenuSelectionTerrain::~MenuSelectionTerrain()
{
    delete texteTitre;
    delete b_retour;
    delete b_terrain1;
    delete b_terrain2;
    delete b_terrain3;
}

void MenuSelectionTerrain::action_retour()
{
    emit b_retour_appuyer();
}

void MenuSelectionTerrain::action_terrain1()
{
    emit b_terrain1_appuyer();
}

void MenuSelectionTerrain::action_terrain2()
{
    emit b_terrain2_appuyer();
}

void MenuSelectionTerrain::action_terrain3()
{
    emit b_terrain3_appuyer();
}

