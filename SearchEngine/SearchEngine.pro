TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    parser.cpp \
    page.cpp \
    indexinterface.cpp

HEADERS += \
    container.h \
    LinkedList.h \
    node.h \
    parser.h \
    avltree.h \
    page.h \
    stemmer.h \
    indexinterface.h

macx {
    QMAKE_CXXFLAGS += -std=c++11

    _BOOST_PATH = /usr/local/Cellar/boost/1.56.0
    INCLUDEPATH += "$${_BOOST_PATH}/include/"
    LIBS += -L$${_BOOST_PATH}/lib
    ## Use only one of these:
    LIBS += -lboost_chrono-mt -lboost_system # using dynamic lib (not sure if you need that "-mt" at the end or not)
    #LIBS += $${_BOOST_PATH}/lib/libboost_chrono-mt.a # using static lib
}

