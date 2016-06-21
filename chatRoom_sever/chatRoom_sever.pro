#-------------------------------------------------
#
# Project created by QtCreator 2016-06-14T10:22:32
#
#-------------------------------------------------

QT       += core gui
QT       += network
QT       += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = chatRoom_sever
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ClientSocket.cpp \
    DBHandle.cpp \
    User.cpp \
    UserHandle.cpp \
    ClientManager.cpp

HEADERS  += mainwindow.h \
    ClientSocket.h \
    Package.h \
    DBHandle.h \
    User.h \
    UserHandle.h \
    ClientManager.h

FORMS    += mainwindow.ui
