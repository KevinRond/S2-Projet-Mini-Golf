#include "FenetreTerrain.h"
FenetreTerrain::FenetreTerrain(QWidget* parent)
    : QMainWindow(parent)
{
    //ui.setupUi(this);

    this->setFixedSize(1280, 720);
    

   
    /*texteTitre = new QTextEdit(this);
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
    texteTitre->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);*/

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

    direction = 0;
    force = 0;

    forceText = new QLabel("Force du coup: " + QString::number(force), this);
    forceText->move(50, 100);
    forceText->setFixedSize(300, 50);

    directionText = new QLabel("Direction du coup: " + QString::number(direction), this);
    directionText->move(50, 150);
    directionText->setFixedSize(300, 50);

    coupText = new QLabel("Nombre de coup: " + QString::number(couptxt), this);
    coupText->move(50, 200);
    coupText->setFixedSize(300, 50);

    QString style_etiquette = "QLabel {"
        "font-family: Helvetica;"
        "font-size: 24px;"
        "color: white; "
        "background-color: transparent;"
        "border: none;"
        "}";

    forceText->setStyleSheet(style_etiquette);
    directionText->setStyleSheet(style_etiquette);
    coupText->setStyleSheet(style_etiquette);

    //Design des effets des etiquettes
    effect_etiquette_force = new QGraphicsDropShadowEffect;
    effect_etiquette_force->setBlurRadius(5);
    effect_etiquette_force->setColor(Qt::black);
    effect_etiquette_force->setOffset(1, 1);
    forceText->setGraphicsEffect(effect_etiquette_force);

    effect_etiquette_direction = new QGraphicsDropShadowEffect;
    effect_etiquette_direction->setBlurRadius(5);
    effect_etiquette_direction->setColor(Qt::black);
    effect_etiquette_direction->setOffset(1, 1);
    directionText->setGraphicsEffect(effect_etiquette_direction);

    effect_etiquette_coup = new QGraphicsDropShadowEffect;
    effect_etiquette_coup->setBlurRadius(5);
    effect_etiquette_coup->setColor(Qt::black);
    effect_etiquette_coup->setOffset(1, 1);
    coupText->setGraphicsEffect(effect_etiquette_coup);

    couptxt = 0;
    indexParcours = 0;

    //Creation de la fenetre lorsque la balle arrive dans le trou
    reussi = new QDialog(this);
    reussi->setFixedSize(640, 360);
    reussi->setStyleSheet("QDialog { background-image: url(../Graphic/NextLevel1.png); }");

    finalCoupText = new QLabel("Nombre de coup: " + QString::number(couptxt), reussi);
    finalCoupText->move(125, 50);
    finalCoupText->setFixedSize(400, 50);
    QGraphicsDropShadowEffect* effect_etiquette_finalCoup;

    finalCoupText->setStyleSheet(style_etiquette);

    effect_etiquette_finalCoup = new QGraphicsDropShadowEffect;
    effect_etiquette_finalCoup->setBlurRadius(7);
    effect_etiquette_finalCoup->setColor(Qt::black);
    effect_etiquette_finalCoup->setOffset(1, 1);
    finalCoupText->setGraphicsEffect(effect_etiquette_finalCoup);


    QPushButton* b_retourTrou = new QPushButton("Retour", reussi);
    b_retourTrou->setGeometry(220, 200, 200, 100);
    b_retourTrou->setStyleSheet("QPushButton { border-image: url(../Graphic/BoutonOuvert1.png);"
        "font-family: Helvetica; "
        "font-weight: bold; "
        "font-size: 16px; "
        "color: white "
        "}"
        "QPushButton:hover { border-image: url(../Graphic/BoutonSelect.png); }"
        "QPushButton:pressed { border-image: url(../Graphic/BoutonFermer1.png); }");


    connect(b_retourTrou, &QPushButton::clicked, this, &FenetreTerrain::action_retour);


    QPushButton* b_trouSuivant = new QPushButton("Trou Suivant", reussi);
    b_trouSuivant->setGeometry(220, 100, 200, 100);
    b_trouSuivant->setStyleSheet("QPushButton { border-image: url(../Graphic/BoutonOuvert1.png);"
        "font-family: Helvetica; "
        "font-weight: bold; "
        "font-size: 16px; "
        "color: white "
        "}"
        "QPushButton:hover { border-image: url(../Graphic/BoutonSelect.png); }"
        "QPushButton:pressed { border-image: url(../Graphic/BoutonFermer1.png); }");

    connect(b_trouSuivant, &QPushButton::released, this, &FenetreTerrain::action_trouSuivant);

    //Creation du widget lorsque tu as fini

    fin = new QDialog(this);
    fin->setFixedSize(640, 360);
    fin->setStyleSheet("QDialog { background-image: url(../Graphic/NextLevel1.png); }");

    finCoupText = new QLabel("Nombre de coup: " + QString::number(couptxt), fin);
    finCoupText->move(125, 50);
    finCoupText->setFixedSize(400, 50);

    finalCoupText->setStyleSheet(style_etiquette);

    QPushButton* b_fin = new QPushButton("Retour a l'ecran d'acceuil", fin);
    b_fin->setGeometry(170, 105, 300, 150);
    b_fin->setStyleSheet("QPushButton { border-image: url(../Graphic/BoutonOuvert1.png);"
        "font-family: Helvetica; "
        "font-weight: bold; "
        "font-size: 16px; "
        "color: white "
        "}"
        "QPushButton:hover { border-image: url(../Graphic/BoutonSelect.png); }"
        "QPushButton:pressed { border-image: url(../Graphic/BoutonFermer1.png); }");

    connect(b_fin, &QPushButton::released, this, &FenetreTerrain::action_fin);


    //creation de la mannette
    manette = new Manette("com7");

    point = new QLabel(this);
    QPixmap fleche("../Graphic/crosshair.png");
    point->setPixmap(fleche);
    xPoint = fleche.width();
    yPoint = fleche.height();

    coup = new Coup(0, 0);

    /*son = new QMediaPlayer;
    QString sontxt = "son.mp3";
    son->setMedia(QUrl::fromLocalFile(sontxt));*/

}

FenetreTerrain::~FenetreTerrain()
{
    delete point;
    delete effect_etiquette_direction;
    delete effect_etiquette_force;
    //delete texteTitre;
    delete b_retour;
    delete balle;
    delete coup;
    delete forceText;
    delete directionText;
    delete fin;
    delete reussi;
    delete manette;
}

void FenetreTerrain::action_retour()
{
    emit b_retour_appuyer();
    reussi->close();
}

void FenetreTerrain::set_terrain(QString file_name)
{
    direction = 0;
    force = 0;
    couptxt = 0;
    indexParcours = 0;
    // Update the strength label
    forceText->setText("Force du coup: " + QString::number(force));
    directionText->setText("Direction du coup: " + QString::number(direction));
    coupText->setText("Nombre de coup: " + QString::number(couptxt));

    nom_fichier_terrain = file_name;
    QString terrainPNG = "../Terrain/" + nom_fichier_terrain + ".png";
    QString terrainTXTQ = "../Terrain/" + nom_fichier_terrain + ".txt";
    std::string terrainTXT = terrainTXTQ.toStdString();

    setStyleSheet(QString("QMainWindow{ background-image: url(%1); }").arg(terrainPNG));
    terrain1 = new Terrain;
    terrain1->OpenTerrain(terrainTXT);
    terrain1->Display();
    double Ox = terrain1->getOx() * 100 - xTrans;
    double Oy = 720 - terrain1->getOy() * 100 - yTrans;
    balle->setGeometry(Ox, Oy, xTrans * 2, yTrans * 2);
    balle->show();

    double arrowX = calculateX(Ox);
    double arrowY = calculateY(Oy);
    point->setGeometry((arrowX - (xPoint / 2) + 5), (arrowY - (yPoint / 2) + 5), xPoint, yPoint);
    point->show();

    qApp->processEvents();
    /*son->play();*/
    jouer();
}

QString FenetreTerrain::get_file_name()
{
    return nom_fichier_terrain;
}

double FenetreTerrain::calculateX(double posBalleX)
{
    double angleInRad = direction * M_PI / 180.0;
    double newX = posBalleX + 45 * cos(angleInRad);

    return newX;
}

double FenetreTerrain::calculateY(double posBalleY)
{
    double angleInRad = direction * M_PI / 180.0;
    double newY = posBalleY - 45 * sin(angleInRad);

    return newY;
}

void FenetreTerrain::affiche_nom_fichier()
{
    nomfichier->append(nom_fichier_terrain);
}

void FenetreTerrain::action_trouSuivant()
{
    reussi->close();
    QString numtrou = nom_fichier_terrain.right(1)[0];
    int numeroTrou = numtrou.toInt();
    numeroTrou++;
    nom_fichier_terrain.chop(1);
    nom_fichier_terrain = nom_fichier_terrain + QString::number(numeroTrou);
    set_terrain(nom_fichier_terrain);
    
}

void FenetreTerrain::action_fin()
{
    emit b_fin_appuyer();
    fin->close();
}

void FenetreTerrain::jouer()
{
    //Manette* manette = new Manette("com7");
    std::vector<std::pair<double, double>> parcourVec;
    while (terrain1->TerrainReussi() == false)
    {
        
        Parcours parcours;

        double Ox = terrain1->getOx() * 100 - xTrans;
        double Oy = 720 - terrain1->getOy() * 100 - yTrans;
        double arrowX = calculateX(Ox);
        double arrowY = calculateY(Oy);
        point->setGeometry((arrowX - (xPoint / 2) + 5), (arrowY - (yPoint / 2) + 5), xPoint, yPoint);
        manette->setBouton();
        while (!manette->getButton1())
        {
  
           // manette->button2 = false;
            
            double prevDirect = direction;
            direction = manette->GetDirectionElec(coup);
            directionText->setText("Direction du coup: " + QString::number(direction));
            if (prevDirect < direction)
            {
                arrowX = calculateX(Ox);
                arrowY = calculateY(Oy);
                point->setGeometry((arrowX - (xPoint / 2) + 5), (arrowY - (yPoint / 2) + 5), xPoint, yPoint);
            }
            else
            {
                arrowX = calculateX(Ox);
                arrowY = calculateY(Oy);
                point->setGeometry((arrowX - (xPoint / 2) + 5), (arrowY - (yPoint / 2) + 5), xPoint, yPoint);
            }
            point->show();
            qApp->processEvents();
            Sleep(10);
        }

        
        force = manette->GetPuissanceElec(coup);
        forceText->setText("Force du coup: " + QString::number(force));
        //qApp->processEvents();
        //manette->SequenceCoup(coup);
        parcours = terrain1->CoupDonne(coup);
        parcourVec = parcours.GetCoorXY();
        point->setVisible(false);

        for (indexParcours; indexParcours < parcourVec.size(); indexParcours++)
        {
            const auto& coord = parcourVec[indexParcours];
            int x = (coord.first * 100) - xTrans;
            int y = (720 - (coord.second * 100)) - yTrans;
            balle->move(x, y);
            qApp->processEvents();
            Sleep(37);
        }
        couptxt++;
        coupText->setText("Nombre de coup: " + QString::number(couptxt));
        direction = 0;
    }

    parcourVec.clear();
    QString numtrou = nom_fichier_terrain.right(1)[0];
    int numeroTrou = numtrou.toInt();
    balle->hide();
    qApp->processEvents();
    if (numeroTrou < 8)
    {
        if (couptxt == 1)
        {
            finalCoupText->move(200, 50);
            finalCoupText->setText("BRAVO!! Trou en " + QString::number(couptxt) + "!!");
        }
        else
        {
            finalCoupText->setText("BRAVO!! Trou reussi en " + QString::number(couptxt) + " coups !!");
        }
        reussi->exec();
    }
   
    else
    {
        fin->exec();
    }
    //delete manette;
}

void FenetreTerrain::keyPressEvent(QKeyEvent* event)
{
    std::vector<std::pair<double, double>> parcourVec;
    
    Parcours parcours;

    double Ox = terrain1->getOx() * 100 - xTrans;
    double Oy = 720 - terrain1->getOy() * 100 - yTrans;
    double arrowX = calculateX(Ox);
    double arrowY = calculateY(Oy);

    point->setGeometry((arrowX - (xPoint / 2) + 5), (arrowY - (yPoint / 2) + 5), xPoint, yPoint);

    switch (event->key())
    {
    case Qt::Key_R:

        manette->setBouton();
        while (!manette->getButton1())
        {
            double prevDirect = direction;
            direction = - manette->GetDirectionElec(coup);
            directionText->setText("Direction du coup: " + QString::number(direction));
            if (prevDirect < direction)
            {
                arrowX = calculateX(Ox);
                arrowY = calculateY(Oy);
                point->setGeometry((arrowX - (xPoint / 2) + 5), (arrowY - (yPoint / 2) + 5), xPoint, yPoint);
            }
            else
            {
                arrowX = calculateX(Ox);
                arrowY = calculateY(Oy);
                point->setGeometry((arrowX - (xPoint / 2) + 5), (arrowY - (yPoint / 2) + 5), xPoint, yPoint);
            }
            point->show();
            qApp->processEvents();
            Sleep(10);
        }

        manette->GetPuissanceElec(coup);
        //manette->SequenceCoup(coup);
        parcours = terrain1->CoupDonne(coup);
        parcourVec = parcours.GetCoorXY();
        point->setVisible(false);

        for (indexParcours; indexParcours < parcourVec.size(); indexParcours++)
        {
            const auto& coord = parcourVec[indexParcours];
            int x = (coord.first * 100) - xTrans;
            int y = (720 - (coord.second * 100)) - yTrans;
            balle->move(x, y);
            qApp->processEvents();
            Sleep(37);
        }
        if (terrain1->TerrainReussi())
        {
            QString numtrou = nom_fichier_terrain.right(1)[0];
            int numeroTrou = numtrou.toInt();
            balle->hide();
            qApp->processEvents();
            if (numeroTrou < 8)
            {
                reussi->exec();
            }
            else
            {
                fin->exec();
            }
            
        }

    case Qt::Key_A:

        direction--;
        arrowX = calculateX(Ox);
        arrowY = calculateY(Oy);
        point->setGeometry((arrowX - (xPoint / 2) + 5), (arrowY - (yPoint / 2) + 5), xPoint, yPoint);
        break;

    case Qt::Key_D:

        direction++;
        arrowX = calculateX(Ox);
        arrowY = calculateY(Oy);
        point->setGeometry((arrowX - (xPoint / 2) + 5), (arrowY - (yPoint / 2) + 5), xPoint, yPoint);
        break;

    case Qt::Key_S:

        force--;
        break;

    case Qt::Key_W:

        force++;
        break;

    default:

        QMainWindow::keyPressEvent(event);
        return;

    }

    // Ensure that strength is within a valid range
    force = qBound(0.0, force, 20.0);
    direction = qBound(-360.0, direction, 360.0);

    // Update the strength label
    forceText->setText("Force du coup: " + QString::number(force));
    directionText->setText("Direction du coup: " + QString::number(direction));

    parcourVec.clear();
    // Accept the key event
    event->accept();
 
}

