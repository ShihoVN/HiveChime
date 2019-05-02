#-------------------------------------------------
#
# Project created by QtCreator 2019-04-25T11:24:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LoginGUI
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    secondwindow.cpp \
    secondwindowresearcher.cpp \
    createmodel.cpp \
    userselectmodel.cpp \
    generatedmodel.cpp \
    linegraph.cpp \
    bargraph.cpp

HEADERS += \
        mainwindow.h \
    secondwindow.h \
    secondwindowresearcher.h \
    createmodel.h \
    userselectmodel.h \
    generatedmodel.h \
    linegraph.h \
    bargraph.h

FORMS += \
        mainwindow.ui \
    secondwindow.ui \
    secondwindowresearcher.ui \
    createmodel.ui \
    selectmodel.ui \
    userselectmodel.ui \
    generatedmodel.ui \
    linegraph.ui \
    bargraph.ui


HEADERS += ../Database/dbtable.h
SOURCES += ../Database/dbtable.cpp

HEADERS += ../Database/tool.h
SOURCES += ../Database/tool.cpp

HEADERS += ../Database/dbhivetable.h
SOURCES += ../Database/dbhivetable.cpp

HEADERS += ../Database/dbmodeltable.h
SOURCES += ../Database/dbmodeltable.cpp

HEADERS += ../Database/dbbeelog.h
SOURCES += ../Database/dbbeelog.cpp
LIBS += -lsqlite3

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
