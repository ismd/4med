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
    lib/DefaultModel.cpp \
    gui/AddDrug.cpp
HEADERS += gui/MainWindow.h \
    lib/DrugModel.h \
    lib/DefaultModel.h \
    gui/AddDrug.h
FORMS += ui/MainWindow.ui \
    ui/AddDrug.ui
