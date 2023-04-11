#ifndef AUTREMENU_H
#define AUTREMENU_H

#include <QtWidgets/QMainWindow>
#include <qapplication.h>
#include <qmenu.h>
#include <qmenubar.h>
#include <qaction.h>
#include <qpushbutton.h>
#include <QtGui>
#include <Qlabel>
#include <vector>
#include "Terrain.h"
#include "Parcours.h"
//#include <QMediaPlayer>
#include <QtWidgets/QTextEdit>

class AutreMenu : public QMainWindow
{
	Q_OBJECT

public: 
	AutreMenu(QWidget* parent = nullptr);
	~AutreMenu();

signals:

	void b_lancer_appuyer();
	void b_retour_appuyer();

private slots:

	void action_lancer();
	void action_retour();

private:
	QPushButton* b_lancer;
	QPushButton* b_quit;
	QPushButton* b_retour;
};



#endif
