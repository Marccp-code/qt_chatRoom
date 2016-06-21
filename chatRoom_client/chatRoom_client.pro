#-------------------------------------------------
#
# Project created by QtCreator 2016-06-14T10:23:13
#
#-------------------------------------------------

QT       += core gui
QT       +=network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = chatRoom_client
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    chatWidget.cpp \
    Setting.cpp

HEADERS  += mainwindow.h \
    Package.h \
    chatWidget.h \
    Setting.h

FORMS    += mainwindow.ui \
    chatWidget.ui \
    setting.ui
