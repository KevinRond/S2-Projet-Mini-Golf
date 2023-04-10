#include "MenuReglements.h"

MenuReglements::MenuReglements(QWidget* parent)
    : QMainWindow(parent)
{
    //ui.setupUi(this);

    this->setFixedSize(1280, 720);
    setStyleSheet("QMainWindow{ background-image: url(../Graphic/BeauFond3.png); }");


    texteTitre = new QTextEdit(this);
    texteTitre->setGeometry(240, 100, 800, 400);
    texteTitre->setPlainText("Reglements ");
    texteTitre->setReadOnly(true);
    QString style_titre = "QTextEdit {"
        "font-family: Helvetica;"
        "font-size: 60px;"
        "color: white;"
        "background-color: transparent;"
        "border: none;"
        "}";
    texteTitre->setStyleSheet(style_titre);
    texteTitre->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    effectTitre = new QGraphicsDropShadowEffect;
    effectTitre->setBlurRadius(5);
    effectTitre->setColor(Qt::black);
    effectTitre->setOffset(3, 3);
    texteTitre->setGraphicsEffect(effectTitre);


    texteReglements = new QTextEdit(this);
    texteReglements->setGeometry(150, 200, 980, 480);
    texteReglements->append("1. Le but du jeu est de placer la balle dans le trou en un minimum de coups possible.\n");
    texteReglements->append("2. Reglez la puissance et la direction de votre coup. Utilisez la souris ou les touches directionnelles pour viser et la barre d'espace ou le clic gauche pour frapper la balle. Plus vous maintenez la touche enfoncee, plus le coup sera puissant.\n");
    texteReglements->append("3. Evitez les obstacles tels que les planches, les tunnels et les virages serres. Si la balle sort du terrain, vous devrez la replacer sur le dernier endroit traversee et ajouter un coup a votre score.\n");
    texteReglements->append("4. Atteignez le trou en un minimum de coups possible. Le score est calcule en fonction du nombre de coups necessaires pour terminer le parcours. Essayez d'obtenir le score le plus bas possible.\n");
    texteReglements->setReadOnly(true);
    QString style_reglements = "QTextEdit {"
        "font-family: Helvetica;"
        "font-size: 24px;"
        "color: white;"
        "background-color: transparent;"
        "border: none;"
        "}";
    texteReglements->setStyleSheet(style_reglements);
    texteReglements->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    effectReglements = new QGraphicsDropShadowEffect;
    effectReglements->setBlurRadius(5);
    effectReglements->setColor(Qt::black);
    effectReglements->setOffset(3, 3);
    texteReglements->setGraphicsEffect(effectReglements);

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

    connect(b_retour, &QPushButton::clicked, this, &MenuReglements::action_retour);

}

MenuReglements::~MenuReglements()
{
    delete texteTitre;
    delete texteReglements;
    delete b_retour;
    delete effectTitre;
    delete effectReglements;
}

void MenuReglements::action_retour()
{
    emit b_retour_appuyer();
}