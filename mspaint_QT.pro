#-------------------------------------------------
#
# Project created by QtCreator 2017-06-02T16:53:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mspaint_QT
TEMPLATE = app


SOURCES += main.cpp\
    mypainterwidget.cpp \
    maincontrolpanel.cpp \
    toolsfunctionwidget.cpp \
    mspaint_qt.cpp

HEADERS  += \
    mypainterwidget.h \
    maincontrolpanel.h \
    toolsfunctionwidget.h \
    mspaint_qt.h

FORMS    += \
    mspaint_qt.ui
