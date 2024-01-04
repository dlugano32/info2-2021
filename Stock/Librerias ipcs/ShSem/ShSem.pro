TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        ipcs.cpp \
        main.cpp \
        shsem.cpp

HEADERS += \
    ipcs.h \
    shsem.h
