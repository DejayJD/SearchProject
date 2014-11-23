TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    porter2stemmer.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    porter2stemmer.h

