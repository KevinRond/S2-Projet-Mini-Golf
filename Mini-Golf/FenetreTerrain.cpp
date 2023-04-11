#include "FenetreTerrain.h"

using namespace std;

FenetreTerrain::FenetreTerrain(QWidget* parent)
    : QMainWindow(parent)
{
    //ui.setupUi(this);

    this->setFixedSize(1280, 720);

    //Texte du titre
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


    //Set up du bouton retour
    b_retour = new QPushButton("Retour", this);
    b_retour->setGeometry(1100, 640, 150, 50);

    //Action du bouton retour
    connect(b_retour, &QPushButton::clicked, this, &FenetreTerrain::action_retour);


    //Set up de la zone de texte (a enlever eventuellement)
    nomfichier = new QTextEdit(this);
    nomfichier->setGeometry(860, 50, 370, 250);
    nomfichier->append(nom_fichier_terrain);


    //Initialisation des variables de force du coup et de la direction
    force_coup = 0;
    direction_coup = 90;


    //Initialisation de leurs etiquettes
    etiquette_force = new QLabel("Force du coup: 0", this);
    //etiquette_force->setAlignment(Qt::AlignCenter);
    etiquette_force->move(50, 100);
    etiquette_force->setFixedSize(200, 50);

    etiquette_direction = new QLabel("Direction du coup: 90 degre", this);
    //etiquette_direction->setAlignment(Qt::AlignCenter);
    etiquette_direction->move(50, 150);
    etiquette_direction->setFixedSize(300, 50);

    QString style_etiquette = "QLabel {"
        "font-family: Helvetica;"
        "font-size: 24px;"
        "color: white; "
        "background-color: transparent;"
        "border: none;"
        "}";

    etiquette_force->setStyleSheet(style_etiquette);
    etiquette_direction->setStyleSheet(style_etiquette);

     
    //Design des effets des etiquettes
    effect_etiquette_force = new QGraphicsDropShadowEffect;
    effect_etiquette_force->setBlurRadius(5);
    effect_etiquette_force->setColor(Qt::black);
    effect_etiquette_force->setOffset(1, 1);
    etiquette_force->setGraphicsEffect(effect_etiquette_force);

    effect_etiquette_direction = new QGraphicsDropShadowEffect;
    effect_etiquette_direction->setBlurRadius(5);
    effect_etiquette_direction->setColor(Qt::black);
    effect_etiquette_direction->setOffset(1, 1);
    etiquette_direction->setGraphicsEffect(effect_etiquette_direction);



}

FenetreTerrain::~FenetreTerrain()
{
    delete effect_etiquette_direction;
    delete effect_etiquette_force;
    delete etiquette_force;
    delete etiquette_direction;
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
    QString terrainTXTQ = "../Terrain/" + nom_fichier_terrain + ".txt";
    string terrainTXT = terrainTXTQ.toStdString();

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

void FenetreTerrain::keyPressEvent(QKeyEvent* event)
{
    switch (event->key())
    {
    case Qt::Key_W:
        // Increase strength by 1
        force_coup++;
        break;
    case Qt::Key_S:
        // Decrease strength by 1
        force_coup--;
        break;
    case Qt::Key_D:
        // Decrease direction by 5
        direction_coup = direction_coup - 5;
        break;
    case Qt::Key_A:
        // Increase direction by 5
        direction_coup = direction_coup + 5;
        break;
    default:
        QMainWindow::keyPressEvent(event);
        return;
    }

    // Ensure that strength is within a valid range
    force_coup = qBound(0, force_coup, 100);
    direction_coup = qBound(0, direction_coup, 360);

    // Update the strength label
    etiquette_force->setText("Force du coup: " + QString::number(force_coup));
    etiquette_direction->setText("Direction du coup: " + QString::number(direction_coup) + " degre");

    // Accept the key event
    event->accept();
}
