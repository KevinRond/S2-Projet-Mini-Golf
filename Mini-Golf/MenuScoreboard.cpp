#include "MenuScoreboard.h"

MenuScoreboard::MenuScoreboard(QWidget* parent)
    : QMainWindow(parent)
{
    //ui.setupUi(this);

    this->setFixedSize(1280, 720);

    texteTitre = new QTextEdit(this);
    texteTitre->setGeometry(240, 100, 800, 400);
    texteTitre->setPlainText("Gagnants du prix Carl Carmoni: ");
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

    connect(b_retour, &QPushButton::clicked, this, &MenuScoreboard::action_retour);

}

MenuScoreboard::~MenuScoreboard()
{
    delete texteTitre;
    delete b_retour;
}

void MenuScoreboard::action_retour()
{
    emit b_retour_appuyer();
}

