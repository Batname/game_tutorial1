#-------------------------------------------------
#
# Project created by QtCreator 2016-10-29T13:10:07
#
#-------------------------------------------------

QMAKE_MAC_SDK = macosx10.12
QT       += core gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = game_tutorial1
TEMPLATE = app


SOURCES += main.cpp \
    bullet.cpp \
    enemy.cpp \
    score.cpp \
    game.cpp \
    player.cpp \
    health.cpp

HEADERS  += \
    bullet.h \
    enemy.h \
    score.h \
    game.h \
    player.h \
    health.h

RESOURCES += \
    res.qrc
