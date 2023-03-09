TEMPLATE     = vcapp
TARGET       = Mini-Golf
CONFIG      += warn_on qt debug windows console
HEADERS     += Ball.h Hole.h Interraction.h Mur.h Terrain.h Coup.h
SOURCES     += Ball.cpp Hole.cpp Interraction.cpp Mur.cpp Terrain.cpp Mini-Golf.cpp Coup.cpp
INCLUDEPATH += ../Mini-Golf
LIBS        += 
QT          += widgets
