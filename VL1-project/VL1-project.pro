QT += core sql gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = VL1-project
CONFIG += console
CONFIG -= app_bundle


TEMPLATE = app

SOURCES += main.cpp \
    datalayer.cpp \
    scientist.cpp \
    computer.cpp \
    servicelayer.cpp \
    mainwindow.cpp \
    addscientistwindow.cpp \
    addcomputerwindow.cpp \
    scientistinfowindow.cpp


HEADERS += \
    datalayer.h \
    scientist.h \
    computer.h \
    servicelayer.h \
    const.h \
    mainwindow.h \
    addscientistwindow.h \
    addcomputerwindow.h \
    scientistinfowindow.h


FORMS += \
    mainwindow.ui \
    addscientistwindow.ui \
    addcomputerwindow.ui \
    scientistinfowindow.ui
