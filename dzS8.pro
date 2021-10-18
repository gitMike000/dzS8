TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt
INCLUDEPATH +=/usr/include/gtest
LIBS += /usr/lib/libgtest.so -lgtest

SOURCES += \
        main.cpp

HEADERS += \
    dzS1.h \
    tests.h
