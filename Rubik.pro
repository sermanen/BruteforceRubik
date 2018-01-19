#-------------------------------------------------
#
# Project created by QtCreator 2017-11-27T17:18:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Rubik.exe
TEMPLATE = app


SOURCES += Corners.cpp Cross.cpp Cube.cpp Edges.cpp OLL.cpp PLL.cpp Rubik.cpp Bruteforce.cpp TMyCube.cpp


HEADERS  += Corners.h Cross.h Cube.h Edges.h OLL.h PLL.h Bruteforce.h TMyCube.h

#FORMS    += mainwindow.ui

MOC_DIR		= ./.moc
OBJECTS_DIR	= ./.obj

QMAKE_LFLAGS += -fopenmp -O2 -march=native
QMAKE_CXXFLAGS += -fopenmp -O2 -march=native
