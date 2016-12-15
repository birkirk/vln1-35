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
    scientistinfowindow.cpp \
    computerinfowindow.cpp \
    addtypewindow.cpp \
    helpwindow.cpp


HEADERS += \
    datalayer.h \
    scientist.h \
    computer.h \
    servicelayer.h \
    const.h \
    mainwindow.h \
    addscientistwindow.h \
    addcomputerwindow.h \
    scientistinfowindow.h \
    computerinfowindow.h \
    addtypewindow.h \
    helpwindow.h


FORMS += \
    mainwindow.ui \
    addcomputerwindow.ui \
    scientistinfowindow.ui \
    addscientistwindow.ui \
    computerinfowindow.ui \
    addtypewindow.ui \
    helpwindow.ui
