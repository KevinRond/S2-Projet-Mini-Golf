#include "FenetreTerrain.h"
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
    b_retour->setGeometry(1080, 620, 200, 100);
    b_retour->setStyleSheet("QPushButton { border-image: url(../Graphic/BoutonOuvert1.png);"
        "font-family: Helvetica; "
        "font-weight: bold; "
        "font-size: 16px; "
        "color: white "
        "}"
        "QPushButton:hover { border-image: url(../Graphic/BoutonSelect.png); }"
        "QPushButton:pressed { border-image: url(../Graphic/BoutonFermer1.png); }");



    connect(b_retour, &QPushButton::clicked, this, &FenetreTerrain::action_retour);

    balle = new QLabel("Balle", this);
    QPixmap pixmap("../Graphic/Ball.png");
    balle->setPixmap(pixmap);
    xTrans = pixmap.width() / 2;
    yTrans = pixmap.height() / 2;

    direction = 1;
    force = 1;

    forceText = new QLabel("Force du coup: " + QString::number(force), this);
    forceText->move(50, 100);
    forceText->setFixedSize(300, 50);

    directionText = new QLabel("Direction du coup: " + QString::number(direction), this);
    directionText->move(50, 150);
    directionText->setFixedSize(300, 50);

    indexParcours = 0;



}

FenetreTerrain::~FenetreTerrain()
{
    delete texteTitre;
    delete b_retour;
    delete balle;
    delete forceText;
    delete directionText;
}

void FenetreTerrain::action_retour()
{
    emit b_retour_appuyer();
    
}

void FenetreTerrain::set_file_name(QString file_name)
{
    direction = 1;
    force = 1;
    indexParcours = 0;
    // Update the strength label
    forceText->setText("Force du coup: " + QString::number(force));
    directionText->setText("Direction du coup: " + QString::number(direction));

    nom_fichier_terrain = file_name;
    QString terrainPNG = "../Terrain/" + nom_fichier_terrain + ".png";
    QString terrainTXTQ = "../Terrain/" + nom_fichier_terrain + ".txt";
    std::string terrainTXT = terrainTXTQ.toStdString();

    setStyleSheet(QString("QMainWindow{ background-image: url(%1); }").arg(terrainPNG));
    terrain1 = new Terrain;
    terrain1->OpenTerrain(terrainTXT);
    terrain1->Display();
    std::string direction;
    std::string force;
    double Ox = terrain1->getOx()*100 - xTrans;
    double Oy = 720 - terrain1->getOy()*100- yTrans;
    balle->setGeometry(Ox, Oy, xTrans*2, yTrans*2);
    balle->show();
    qApp->processEvents();
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
    std::vector<std::pair<double, double>> parcourVec;
    Coup coup1(direction, force);
    Parcours parcours;
    switch (event->key())
    {
    case Qt::Key_R:
        parcours = terrain1->CoupDonne(coup1);
        parcourVec = parcours.GetCoorXY();
        for (indexParcours; indexParcours < parcourVec.size(); indexParcours++)
        {
            const auto& coord = parcourVec[indexParcours];
            int x = (coord.first * 100) - xTrans;
            int y = (720 - (coord.second * 100)) - yTrans;
            balle->move(x, y);
            qApp->processEvents();
            Sleep(37);

        }

    case Qt::Key_A:

        direction--;
        break;

    case Qt::Key_D:

        direction++;
        break;

    case Qt::Key_Z:

        force--;
        break;

    case Qt::Key_C:

        force++;
        break;

    default:

        QMainWindow::keyPressEvent(event);
        return;

    }

    // Ensure that strength is within a valid range
    force = qBound(1.0, force, 20.0);
    direction = qBound(1.0, direction, 360.0);

    // Update the strength label
    forceText->setText("Force du coup: " + QString::number(force));
    directionText->setText("Direction du coup: " + QString::number(direction));

    parcourVec.clear();
    // Accept the key event
    event->accept();
 
}

