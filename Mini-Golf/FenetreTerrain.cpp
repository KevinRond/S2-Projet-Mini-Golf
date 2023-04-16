/*********************************************************************************************************

Fichier: FenetreTerrain.cpp
Auteurs:    Samuel Bilodeau – bils2704
            Alexis Guérard – guea0902
            Kevin Rondeau – ronk2602
            Ali Sow – sowa0801
Date: 13 Avril 2023

Description: Fichier source de la classe FenetreTerrain. Cette classe affiche le jeu.

Description des fonctions:

set_terrain(QString file_name): Cette fonction est responsable de créer un objet terrain avec le nom de
fichier qu'elle reçoit en paramètre. Ce nom de fichier lui permet d'aller ouvrir les fichiers lui donnant
pour le fond d'écran ainsi que pour la position des murs et de la balle. La fonction affiche également le
terrain, la balle, ainsi que la cible qui permet de viser.

get_file_name(): Fonction permettant de retourner le nom de fichier du terrain actuel.

calculateX(double posBalleX): Cette fonction calcule la position en X de la cible en prenant la position
de la balle en X comme paramètre.

calculateY(double posBalley): Cette fonction calcule la position en Y de la cible en prenant la position
de la balle en Y comme paramètre.

action_retour(): Émet le signal b_retour_appuyer.

affiche_nom_fichier(): Permet d'afficher le nom de fichier dans une zone de texte.

action_trouSuivant(): Met à jour le terrain actuel si le joueur choisi cette action.

action_fin(): Emet le signal b_fin_appuyer. Ferme le jeu.

jouer(): Cette fonction permet d'exécuter le jeu. Tant que le trou n'est pas réussi, elle prendra les coups
du joueur et déplacera la balle dans le terrain. Si le trou est est réussi, l'usager peut quitter ou jouer
le prochain trou.

keyPressEvent(QKeyEvent* event): Gère les entrées de l'usager avec manette ou clavier.

************************************************************************************************************/


#include "FenetreTerrain.h"

FenetreTerrain::FenetreTerrain(QWidget* parent)
    : QMainWindow(parent)
{


    this->setFixedSize(1280, 720);
    

   
    //texteTitre = new QTextEdit(reussi);
    //texteTitre->setGeometry(240, 100, 800, 400);
    ////texteTitre->setPlainText("Terrain");
    //texteTitre->setReadOnly(true);
    //QString style_titre = "QTextEdit {"
    //    "font-family: Helvetica;"
    //    "font-size: 60px;"
    //    "background-color: transparent;"
    //    "border: none;"
    //    "}";
    //texteTitre->setStyleSheet(style_titre);
    //texteTitre->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

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
        "QPushButton:hover, QPushButton:focus { border-image: url(../Graphic/BoutonSelect.png); }"
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

    finCoupText->setStyleSheet(style_etiquette);
    finalCoupText->setGraphicsEffect(effect_etiquette_finalCoup);




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


    point = new QLabel(this);
    QPixmap fleche("../Graphic/crosshair.png");
    point->setPixmap(fleche);
    xPoint = fleche.width();
    yPoint = fleche.height();

    //music et son

    connard = new QMediaPlayer;
    QString connardfile = "../Son/tUnConnard.wav";
    connard->setMedia(QUrl::fromLocalFile(connardfile));

    back = new QMediaPlayer;
    QString backFile = "../Son/Back.mp3";
    back->setMedia(QUrl::fromLocalFile(backFile));
    back->setVolume(100);

    desert = new QMediaPlayer;
    QString desertFile = "../Son/Desert.mp3";
    desert->setMedia(QUrl::fromLocalFile(desertFile));
    desert->setVolume(40);

    snow = new QMediaPlayer;
    QString snowFile = "../Son/Snow.mp3";
    snow->setMedia(QUrl::fromLocalFile(snowFile));
    snow->setVolume(40);

    green = new QMediaPlayer;
    QString greenFile = "../Son/Green.mp3";
    green->setMedia(QUrl::fromLocalFile(greenFile));
    green->setVolume(40);

    birdie = new QMediaPlayer;
    QString birdieFile = "../Son/Birdie.wav";
    birdie->setMedia(QUrl::fromLocalFile(birdieFile));
    birdie->setVolume(100);

    boo = new QMediaPlayer;
    QString booFile = "../Son/Boo.wav";
    boo->setMedia(QUrl::fromLocalFile(booFile));
    boo->setVolume(100);

    bruh = new QMediaPlayer;
    QString bruhFile = "../Son/bruh.wav";
    bruh->setMedia(QUrl::fromLocalFile(bruhFile));
    bruh->setVolume(100);

    pourris = new QMediaPlayer;
    QString pourrisFile = "../Son/Pourris.wav";
    pourris->setMedia(QUrl::fromLocalFile(pourrisFile));
    pourris->setVolume(100);

    crowd = new QMediaPlayer;
    QString crowdFile = "../Son/crowd.wav";
    crowd->setMedia(QUrl::fromLocalFile(crowdFile));
    crowd->setVolume(100);

    damn = new QMediaPlayer;
    QString damnFile = "../Son/Damn.wav";
    damn->setMedia(QUrl::fromLocalFile(damnFile));
    damn->setVolume(100);

    legitness = new QMediaPlayer;
    QString legitnessFile = "../Son/Legitness.wav";
    legitness->setMedia(QUrl::fromLocalFile(legitnessFile));
    legitness->setVolume(100);

    coupSon = new QMediaPlayer;
    QString coupFile = "../Son/coup.mp3";
    coupSon->setMedia(QUrl::fromLocalFile(coupFile));
    coupSon->setVolume(100);

    //manette

    


}

FenetreTerrain::~FenetreTerrain()
{
    delete point;
    delete effect_etiquette_direction;
    delete effect_etiquette_force;
    //delete texteTitre;
    delete b_retour;
    delete balle;
    delete forceText;
    delete directionText;
    delete fin;
    delete reussi;
}

void FenetreTerrain::action_retour()
/*******************************************
Émet le signal b_retour_appuyer.

:return:
********************************************/
{
    back->play();
    desert->stop();
    snow->stop();
    green->stop();
    emit b_retour_appuyer();
    reussi->close();
}

void FenetreTerrain::set_terrain(QString file_name)
/********************************************************************************************************
Cette fonction est responsable de créer un objet terrain avec le nom de
fichier qu'elle reçoit en paramètre. Ce nom de fichier lui permet d'aller ouvrir les fichiers lui donnant
pour le fond d'écran ainsi que pour la position des murs et de la balle. La fonction affiche également le
terrain, la balle, ainsi que la cible qui permet de viser.

:param file_name: Nom du fichier avec lequel le terrain est choisi

:return:
*********************************************************************************************************/
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
    double Ox = terrain1->getOx()*100 - xTrans;
    double Oy = 720 - terrain1->getOy()*100- yTrans;
    balle->setGeometry(Ox, Oy, xTrans*2, yTrans*2);
    balle->show();

    double arrowX = calculateX(Ox);
    double arrowY = calculateY(Oy);
    point->setGeometry((arrowX - (xPoint / 2) + 5), (arrowY - (yPoint / 2) + 5), xPoint, yPoint);
    point->show();

    //changement de music
    QString numtrou = nom_fichier_terrain.right(1)[0];
    int numeroTrou = numtrou.toInt();
    if (0 < numeroTrou && numeroTrou < 5)
    {
        green->play();
        desert->stop();
        snow->stop();
    }
    else if (4 < numeroTrou && numeroTrou < 7)
    {
        desert->play();
        snow->stop();
        green->stop();
    }
    else if(6 < numeroTrou && numeroTrou < 9)
    {
        snow->play();
        desert->stop();
        green->stop();
    }

    qApp->processEvents();
    //jouer();
}

QString FenetreTerrain::get_file_name()
/********************************************************************************************************
Fonction permettant de retourner le nom de fichier du terrain actuel.

:return: Le nom du fichier terrain
*********************************************************************************************************/
{
    return nom_fichier_terrain;
}

double FenetreTerrain::calculateX(double posBalleX)
/********************************************************************************************************
Cette fonction calcule la position en X de la cible en prenant la position
de la balle en X comme paramètre.

:param posBalleX: Position de la balle en X. La cible est placer par rapport à la balle.

:return: Valeur en X qui sert a positionner la cible
*********************************************************************************************************/
{
    double angleInRad = direction * M_PI / 180.0;
    double newX = posBalleX + 45 * cos(angleInRad);

    return newX;
}

double FenetreTerrain::calculateY(double posBalleY)
/********************************************************************************************************
Cette fonction calcule la position en Y de la cible en prenant la position
de la balle en Y comme paramètre.

:param posBalleY: Position de la balle en Y. La cible est placer par rapport à la balle.

:return: Valeur en Y qui sert a positionner la cible
*********************************************************************************************************/
{
    double angleInRad = direction * M_PI / 180.0;
    double newY = posBalleY - 45 * sin(angleInRad);

    return newY;
}

void FenetreTerrain::affiche_nom_fichier()
/********************************************************************************************************
Permet d'afficher le nom de fichier dans une zone de texte.

:return:
*********************************************************************************************************/
{
    nomfichier->append(nom_fichier_terrain);
}

void FenetreTerrain::action_trouSuivant()
/********************************************************************************************************
Met à jour le terrain actuel si le joueur choisi cette action.

:return:
*********************************************************************************************************/
{
    back->play();
    reussi->close();
    QString numtrou = nom_fichier_terrain.right(1)[0];
    int numeroTrou = numtrou.toInt();
    numeroTrou++;
    nom_fichier_terrain.chop(1);
    nom_fichier_terrain = nom_fichier_terrain + QString::number(numeroTrou);
    set_terrain(nom_fichier_terrain);
    
}

void FenetreTerrain::action_fin()
/********************************************************************************************************
Emet le signal b_fin_appuyer. Ferme le jeu.

:return:
*********************************************************************************************************/
{
    back->play();
    desert->stop();
    snow->stop();
    green->stop();
    emit b_fin_appuyer();
    fin->close();
}



void FenetreTerrain::keyPressEvent(QKeyEvent* event)
/********************************************************************************************************
Gère les entrées de l'usager avec manette ou clavier.

:return:
*********************************************************************************************************/
{
    std::vector<std::pair<double, double>> parcourVec;
    Coup* coup1 = new Coup(-direction, force);
    Coup *coup = new Coup(90, 1);
    Parcours parcours;

    double Ox = terrain1->getOx() * 100 - xTrans;
    double Oy = 720 - terrain1->getOy() * 100 - yTrans;
    double arrowX = calculateX(Ox);
    double arrowY = calculateY(Oy);

    point->setGeometry((arrowX - (xPoint / 2) + 5), (arrowY - (yPoint / 2) + 5), xPoint, yPoint);

    switch (event->key())
    {
    case Qt::Key_R:

        parcours = terrain1->CoupDonne(coup1);
        parcourVec = parcours.GetCoorXY();
        point->setVisible(false);
        coupSon->play();
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
        if (terrain1->TerrainReussi())
        {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<int> distribution(1, 4);

            int trouRd = distribution(gen);
            if (trouRd == 1)
            {
                birdie->play();
            }

            else if (trouRd == 2)
            {
                crowd->play();
            }

            else if (trouRd == 3)
            {
                damn->play();
            }

            else
            {
                legitness->play();
            }
            
            QString numtrou = nom_fichier_terrain.right(1)[0];
            int numeroTrou = numtrou.toInt();
            balle->hide();
            qApp->processEvents();
            Sleep(2000);
            if (numeroTrou < 8)
            {
                if (couptxt == 1)
                {
                    finalCoupText->move(200, 50);
                    finalCoupText->setText("BRAVO!! Trou en " + QString::number(couptxt) + "!!");  
                }
                else
                {
                    finalCoupText->move(125, 50);
                    finalCoupText->setText("BRAVO!! Trou reussi en " + QString::number(couptxt) + " coups !!");
                }
                reussi->exec();
            }
            else
            {
                if (couptxt == 1)
                {
                    finCoupText->move(200, 50);
                    finCoupText->setText("BRAVO!! Trou en " + QString::number(couptxt) + "!!");
                }
                else
                {
                    finCoupText->move(125, 50);
                    finCoupText->setText("BRAVO!! Trou reussi en " + QString::number(couptxt) + " coups !!");
                }
                fin->exec();
            }
            
        }
        else
        {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<int> distribution(1, 4);

            int sonRd = distribution(gen);

            if (couptxt % 3 == 0)
            {
                if (sonRd == 1)
                {
                    connard->play();
                }

                else if (sonRd == 2)
                {
                    boo->play();
                }

                else if (sonRd == 3)
                {
                    pourris->play();
                }

                else
                {
                    bruh->play();
                }
                
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

    case Qt::Key_Backspace:

        // Handle enter key press
        back->play();
        desert->stop();
        snow->stop();
        green->stop();
        emit b_retour_appuyer();
        reussi->close();

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
    point->show();
    qApp->processEvents();
    // Accept the key event
    event->accept();
 
}


void FenetreTerrain::jouer()
/********************************************************************************************************
Cette fonction permet d'exécuter le jeu. Tant que le trou n'est pas réussi, elle prendra les coups
du joueur et déplacera la balle dans le terrain. Si le trou est est réussi, l'usager peut quitter ou jouer
le prochain trou.
:return:
*********************************************************************************************************/
{

    Manette *manette = new Manette("com3");
    while (terrain1->TerrainReussi() == false)
    {
        std::vector<std::pair<double, double>> parcourVec;
        Coup* coup1 = new Coup(direction, force);
        Coup* coup = new Coup(0, 0);
        Parcours parcours;

        double Ox = terrain1->getOx() * 100 - xTrans;
        double Oy = 720 - terrain1->getOy() * 100 - yTrans;
        double arrowX = calculateX(Ox);
        double arrowY = calculateY(Oy);
        point->setGeometry((arrowX - (xPoint / 2) + 5), (arrowY - (yPoint / 2) + 5), xPoint, yPoint);
        manette->setBouton();
        while (!manette->getButton1())
        {
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
    }

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

