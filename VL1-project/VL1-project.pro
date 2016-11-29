QT += core
QT -= gui

CONFIG += c++11

TARGET = VL1-project
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
<<<<<<< HEAD
    datalayer.cpp \
    scientist.cpp \
    servicelayer.cpp

HEADERS += \
    datalayer.h \
    scientist.h \
    servicelayer.h
=======
    userinterface.cpp

HEADERS += \
    userinterface.h
>>>>>>> 01248c3250f9ed792159436e716bf8e1c842e66f
