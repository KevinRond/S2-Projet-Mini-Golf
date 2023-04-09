#include "MenuReglements.h"

MenuReglements::MenuReglements(QWidget* parent)
    : QWidget(parent),
    m_layout(nullptr),
    m_labelLogo(nullptr),
    m_labelVersion(nullptr),
    m_labelDescription(nullptr),
    m_labelCreateur(nullptr),
    b_retour(nullptr)
{
    this->setFixedSize(1280, 720);
    setStyleSheet("QWidget{ background-image: url(../Graphic/BeauFond3.png); }");

    //ui.setupUi(this);
    m_layout = new QVBoxLayout;

    m_labelLogo = new QLabel;
    m_labelLogo->setPixmap(QPixmap("../Graphic/title.png"));
    m_labelVersion = new QLabel("Tout droit est reserver a equipe de R2P2");
    m_labelDescription = new QLabel("\n\n1. Le but du jeu est de placer la balle dans le trou en un minimum de coups possible.\n2. Reglez la puissance et la direction de votre coup. Utilisez la souris ou les touches directionnelles pour viser et la barre d'espace ou le clic gauche pour frapper la balle. Plus vous maintenez la touche enfonc�e, plus le coup sera puissant  .\n3. vitez les obstacles tels que les planches, les tunnels et les virages serr�s. Si la balle sort du terrain, vous devrez la replacer sur le dernier endroit travers� et ajouter un coup � votre score.\n4.Atteignez le trou en un minimum de coups possible. Le score est calcul� en fonction du nombre de coups n�cessaires pour terminer le parcours. Essayez d'obtenir le score le plus bas possible.");
    m_labelDescription->setWordWrap(true);
    m_labelCreateur = new QLabel("Cree par R2P2");
    //m_boutonFermer = new QPushButton("Accepter les Reglements");

    b_retour = new QPushButton("Retour", this);

    m_layout->addWidget(m_labelLogo);
    m_layout->addWidget(m_labelVersion);
    m_layout->addWidget(m_labelDescription);
    m_layout->addWidget(m_labelCreateur);
    m_layout->addWidget(b_retour);

    setLayout(m_layout);
    setWindowTitle("Credit");

    connect(b_retour, &QPushButton::clicked, this, &MenuReglements::action_retour);

}

MenuReglements::~MenuReglements()
{
    delete m_layout;
    delete m_labelLogo;
    delete m_labelVersion;
    delete m_labelDescription;
    delete m_labelCreateur;
    delete b_retour;
}

void MenuReglements::action_retour()
{
    emit b_retour_appuyer();
}