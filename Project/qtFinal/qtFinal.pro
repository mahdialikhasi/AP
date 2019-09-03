#-------------------------------------------------
#
# Project created by QtCreator 2017-06-18T18:13:28
#
#-------------------------------------------------

QT       += core gui \
        multimedia \
        multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qtFinal
TEMPLATE = app


SOURCES += main.cpp \
    bullet.cpp \
    myplayer.cpp \
    pad.cpp \
    boundary.cpp \
    game.cpp \
    score.cpp \
    enemy.cpp \
    health.cpp \
    bonus.cpp

HEADERS  += \
    bullet.h \
    myplayer.h \
    boundary.h \
    pad.h \
    game.h \
    score.h \
    enemy.h \
    health.h \
    bonus.h

RESOURCES += \
    res.qrc
