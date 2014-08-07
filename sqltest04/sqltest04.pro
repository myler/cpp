#-------------------------------------------------
#
# Project created by QtCreator 2014-08-07T10:55:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sqltest04
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    student.cpp

HEADERS  += mainwindow.h \
    student.h

FORMS    += mainwindow.ui

LIBS += -L/usr/lib/oracle/11.2/client64/lib -locci -lnnz11 -lclntsh
INCLUDEPATH += -I/usr/include/oracle/11.2/client64
