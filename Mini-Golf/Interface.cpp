#include "Interface.h"

Labo1QTApp7::Labo1QTApp7(QWidget* parent)
    : QWidget(parent),
    m_layout(nullptr),
    m_labelLogo(nullptr),
    m_labelVersion(nullptr),
    m_labelDescription(nullptr),
    m_labelCreateur(nullptr),
    m_boutonFermer(nullptr)
{ 
    this->resize(1280, 720);
    
    //ui.setupUi(this);
    m_layout = new QVBoxLayout;

    m_labelLogo = new QLabel;
    m_labelLogo->setPixmap(QPixmap("../Graphic/title.png"));
    m_labelVersion = new QLabel("Tout droit est reserver a equipe de R2P2");
    m_labelDescription = new QLabel("\n\n1. Le but du jeu est de placer la balle dans le trou en un minimum de coups possible.\n2. Reglez la puissance et la direction de votre coup. Utilisez la souris ou les touches directionnelles pour viser et la barre d'espace ou le clic gauche pour frapper la balle. Plus vous maintenez la touche enfoncée, plus le coup sera puissant  .\n3. vitez les obstacles tels que les planches, les tunnels et les virages serrés. Si la balle sort du terrain, vous devrez la replacer sur le dernier endroit traversé et ajouter un coup à votre score.\n4.Atteignez le trou en un minimum de coups possible. Le score est calculé en fonction du nombre de coups nécessaires pour terminer le parcours. Essayez d'obtenir le score le plus bas possible.");
    m_labelDescription->setWordWrap(true);
    m_labelCreateur = new QLabel("Cree par R2P2");
    m_boutonFermer = new QPushButton("Accepter les Reglements");

    m_layout->addWidget(m_labelLogo);
    m_layout->addWidget(m_labelVersion);
    m_layout->addWidget(m_labelDescription);
    m_layout->addWidget(m_labelCreateur);
    m_layout->addWidget(m_boutonFermer);

    setLayout(m_layout);
    setWindowTitle("Credit");


}

Labo1QTApp7::~Labo1QTApp7()
{
     
}
 