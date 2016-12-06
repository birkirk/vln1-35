QT += core sql
QT -= gui

CONFIG += c++11

TARGET = VL1-project
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    datalayer.cpp \
    scientist.cpp \
    servicelayer.cpp \
    userinterface.cpp

HEADERS += \
    datalayer.h \
    scientist.h \
    servicelayer.h \
    userinterface.h
