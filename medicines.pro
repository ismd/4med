# -------------------------------------------------
# Project created by QtCreator 2011-04-28T09:00:56
# -------------------------------------------------
QT += sql \
    testlib
TARGET = 4med
TEMPLATE = app
DESTDIR = bin/
SOURCES += main.cpp \
    gui/MainWindow.cpp \
    lib/DrugModel.cpp \
    lib/DefaultModel.cpp
HEADERS += gui/MainWindow.h \
    lib/DrugModel.h \
    lib/DefaultModel.h
FORMS += ui/MainWindow.ui
