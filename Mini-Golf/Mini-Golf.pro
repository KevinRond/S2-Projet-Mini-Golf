TEMPLATE     = vcapp
TARGET       = Mini-Golf
CONFIG      += warn_on qt debug windows console
LIBS        += -L"."
HEADERS     += \
	Ball.h \
	Hole.h \
	Interraction.h \
	Mur.h \
	Terrain.h \
	Coup.h \
	GameManager.h \
	Parcours.h \
	Interface.h \
	MainMenu.h \
	TitleScreen.h
SOURCES     += \
	Ball.cpp \
	Hole.cpp \
	Interraction.cpp \
	Mur.cpp \
	Terrain.cpp \
	Coup.cpp \
	GameManager.cpp \
	Parcours.cpp \
	Mini-Golf.cpp \
	Interface.cpp \
	MainMenu.cpp \
	TitleScreen.cpp
INCLUDEPATH += ../Mini-Golf
INCLUDEPATH += ../Mini-Golf/include
INCLUDEPATH += ../Mini-Golf/include/serial
QT          += widgets
QT 		+= multimedia