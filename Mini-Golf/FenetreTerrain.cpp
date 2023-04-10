#include "FenetreTerrain.h"

using namespace std;

FenetreTerrain::FenetreTerrain(QWidget* parent)
    : QMainWindow(parent)
{
    //ui.setupUi(this);

    this->setFixedSize(1280, 720);
    

    setStyleSheet("QMainWindow{ background-image: url(../Terrain/Terrain1.png); }");
    texteTitre = new QTextEdit(this);
    texteTitre->setGeometry(240, 100, 800, 400);
    texteTitre->setPlainText("Terrain");
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
    b_retour->setGeometry(1100, 640, 150, 50);

    nomfichier = new QTextEdit(this);
    nomfichier->setGeometry(40, 50, 370, 250);

    QString terrainPNG = "../Terrain/" + nom_fichier_terrain + ".png";
    QString terrainTXT = "../Terrain/" + nom_fichier_terrain + ".txt";
    
    setStyleSheet(QString("QMainWindow{ background-image: url(%1); }").arg(terrainPNG));
    nomfichier->append(terrainPNG);

    connect(b_retour, &QPushButton::clicked, this, &FenetreTerrain::action_retour);

}

FenetreTerrain::~FenetreTerrain()
{
    delete texteTitre;
    delete b_retour;
    delete nomfichier;
}

void FenetreTerrain::action_retour()
{
    emit b_retour_appuyer();
}

void FenetreTerrain::set_file_name(QString file_name)
{
    nom_fichier_terrain = file_name;
    QString terrainPNG = "../Terrain/" + nom_fichier_terrain + ".png";
    QString terrainTXT = "../Terrain/" + nom_fichier_terrain + ".txt";

    setStyleSheet(QString("QMainWindow{ background-image: url(%1); }").arg(terrainPNG));
}

QString FenetreTerrain::get_file_name()
{
    return nom_fichier_terrain;
}

void FenetreTerrain::affiche_nom_fichier()
{
    nomfichier->append(nom_fichier_terrain);
}

