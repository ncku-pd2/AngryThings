#-------------------------------------------------
#
# Project created by QtCreator 2016-03-15T13:55:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AngryThing
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gameitem.cpp \
    scene.cpp \
    pixmapitem.cpp \
    bird.cpp

HEADERS  += mainwindow.h \
    gameitem.h \
    scene.h \
    pixmapitem.h \
    bird.h

FORMS    += mainwindow.ui

RESOURCES += \
    resource.qrc
