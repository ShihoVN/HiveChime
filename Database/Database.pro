TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    dbtable.cpp \
    dbmodeltable.cpp \
    dbhivetable.cpp \
    tool.cpp

HEADERS += \
    dbtable.h \
    dbmodeltable.h \
    dbhivetable.h \
    tool.h
