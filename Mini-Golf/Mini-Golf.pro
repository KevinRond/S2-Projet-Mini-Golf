TEMPLATE     = vcapp
TARGET       = Mini-Golf
CONFIG      += warn_on qt debug console
CONFIG      += warn_on qt debug windows console
HEADERS     += Ball.h Hole.h Interraction.h Mur.h Terrain.h Coup.h Manette.h Parcours.h
SOURCES     += Ball.cpp Hole.cpp Interraction.cpp Mur.cpp Terrain.cpp Mini-Golf.cpp Coup.cpp Manette.cpp Parcours.cpp
INCLUDEPATH += ../Mini-Golf
INCLUDEPATH += ../Mini-Golf/include
INCLUDEPATH += ../Mini-Golf/Terrain
INCLUDEPATH += ../Mini-Golf/include/serial
DEFINES += "_HAS_STD_BYTE=0"
LIBS        += 
QT          += widgets
