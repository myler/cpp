TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    director.cpp \
    builder.cpp \
    concreatebuildera.cpp \
    concreatebuilderb.cpp

HEADERS += \
    director.h \
    builder.h \
    concreatebuildera.h \
    concreatebuilderb.h

