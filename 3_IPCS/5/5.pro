TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        ipcs.cpp \
        main.cpp \
        shmem.cpp

HEADERS += \
    ipcs.h \
    shmem.h
