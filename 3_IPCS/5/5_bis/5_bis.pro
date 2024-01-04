TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        ipcs.cpp \
        main.cpp \
        shmem.cpp

HEADERS += \
    ipcs.h \
    shmem.h
