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
	TitleScreen.h \ 
	MenuSelectionTerrain.h \ 
	MenuScoreboard.h \
	MenuReglements.h \
	FenetreTerrain.h  \
	Manette.h \
	SerialPort.hpp
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
	TitleScreen.cpp \ 
	MenuSelectionTerrain.cpp \ 
	MenuScoreboard.cpp \
	MenuReglements.cpp \
	FenetreTerrain.cpp \
	Manette.cpp \
	SerialPort.cpp
INCLUDEPATH += ../../Mini-Golf
INCLUDEPATH += ../../Mini-Golf/include
INCLUDEPATH += ../../Mini-Golf/Terrain
INCLUDEPATH += ../../Mini-Golf/include/serial
INCLUDEPATH += ../Mini-Golf
INCLUDEPATH += ../Mini-Golf/include
INCLUDEPATH += ../Mini-Golf/Terrain
INCLUDEPATH += ../Mini-Golf/include/serial
QT          += widgets