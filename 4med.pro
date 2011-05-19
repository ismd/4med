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
    gui/AddDrug.cpp \
    gui/AddDepartment.cpp \
    lib/DrugModel.cpp \
    lib/DepartmentModel.cpp \
    lib/Db.cpp \
    lib/RecipientModel.cpp \
    gui/AddRecipient.cpp \
    gui/AddRegistration.cpp \
    lib/RegistrationModel.cpp
HEADERS += gui/MainWindow.h \
    gui/AddDrug.h \
    gui/AddDepartment.h \
    lib/DrugModel.h \
    lib/DepartmentModel.h \
    lib/DefaultModel.h \
    lib/Db.h \
    lib/RecipientModel.h \
    gui/AddRecipient.h \
    gui/AddRegistration.h \
    lib/RegistrationModel.h
FORMS += ui/MainWindow.ui \
    ui/AddDrug.ui \
    ui/AddDepartment.ui \
    ui/AddRecipient.ui \
    ui/AddRegistration.ui
