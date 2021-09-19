QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


CONFIG += console c++11
CONFIG -= app_bundle


SOURCES += \
        counter.cpp \
        main.cpp \
        quitwidget.cpp

HEADERS += \
    counter.h \
    quitwidget.h
