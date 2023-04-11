#ifndef TESTACCEUIL_H
#define TESTACCEUIL_H

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

class TestAcceuil : public QMainWindow
{
	Q_OBJECT

public: 
	TestAcceuil(QWidget* parent = nullptr);
	~TestAcceuil();

signals:
	void b_jouer_appuyer();
	void b_play_appuyer();
	void b_autreMenu_appuyer();

private slots:
	void action_jouer();
	void action_play();
	void action_autreMenu();


private:
	QPushButton *b_jouer;
	QPushButton* b_play;
	QPushButton* b_autreMenu;
	QTextEdit* textEdit;

};



#endif
