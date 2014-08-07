TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    student.cpp

LIBS += -L/usr/lib/oracle/11.2/client64/lib -locci -lnnz11 -lclntsh

HEADERS += \
    student.h

INCLUDEPATH += -I/usr/include/oracle/11.2/client64
