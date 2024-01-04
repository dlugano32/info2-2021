TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        ipcs.cpp \
        main.cpp \
        msgqueue.cpp

HEADERS += \
    ipcs.h \
    msgqueue.h
