#-------------------------------------------------
#
# Project created by QtCreator 2017-08-29T17:59:54
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Sudoku
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    chooselevel.cpp \
    gameinterface.cpp \
    SudokuCalculator.cpp \
    SudokuGenerator.cpp \
    timerdisplay.cpp \
    cell.cpp \
    grid.cpp \
    memento.cpp

HEADERS  += mainwindow.h \
    chooselevel.h \
    gameinterface.h \
    SudokuCalculator.h \
    SudokuGenerator.h \
    timerdisplay.h \
    cell.h \
    grid.h \
    memento.h

FORMS    += mainwindow.ui \
    chooselevel.ui \
    gameinterface.ui \
    timerdisplay.ui \
    cell.ui \
    grid.ui

RESOURCES += \
    icons.qrc
