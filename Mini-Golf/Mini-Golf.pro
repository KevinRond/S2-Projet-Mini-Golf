TEMPLATE     = vcapp
TARGET       = Mini-Golf
CONFIG      += warn_on qt debug windows console
LIBS        += -L"."
HEADERS     += Ball.h Hole.h Interraction.h Mur.h Terrain.h Coup.h GameManager.h Parcours.h Interface.h
SOURCES     += Ball.cpp Hole.cpp Interraction.cpp Mur.cpp Terrain.cpp Coup.cpp GameManager.cpp Parcours.cpp Mini-Golf.cpp Interface.cpp
INCLUDEPATH += ../Mini-Golf
INCLUDEPATH += ../Mini-Golf/include
INCLUDEPATH += ../Mini-Golf/include/serial
QT          += widgets

