#-------------------------------------------------
#
# Project created by QtCreator 2018-09-25T12:59:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IMS-xkocic01-xvasic25_gui
TEMPLATE = app

# TODO: Add object files from src folder (EXCEPT main.o !!!)
OBJECTS += ../Grid.o \
           ../Cell.o \
           ../TAV.o \
           ../Args.o

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += "GUI"

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

QMAKE_CXXFLAGS += -std=c++14

SOURCES += \
        ../main.cpp \
        mainwindow.cpp \
        GridUI.cpp \
        RightClickButton.cpp \
        ImageWidget.cpp

HEADERS += \
        mainwindow.h \
        GridUI.h \
        RightClickButton.h \
        ImageWidget.h

RESOURCES += \
    resources.qrc