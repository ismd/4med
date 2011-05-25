#############################################################################
# Makefile for building: bin/4med
# Generated by qmake (2.01a) (Qt 4.7.3) on: Wed May 25 16:02:06 2011
# Project:  4med.pro
# Template: app
# Command: /usr/bin/qmake -spec /usr/share/qt4/mkspecs/linux-g++ CONFIG+=debug QMLJSDEBUGGER_PATH=/usr/share/qtcreator/qml/qmljsdebugger QMLJSDEBUGGER_PATH=/usr/share/qtcreator/qml/qmljsdebugger QMLJSDEBUGGER_PATH=/usr/share/qtcreator/qml/qmljsdebugger QMLJSDEBUGGER_PATH=/usr/share/qtcreator/qml/qmljsdebugger -o Makefile 4med.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_TESTLIB_LIB -DQT_SQL_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtSql -I/usr/include/qt4/QtTest -I/usr/include/qt4 -I. -I.
LINK          = g++
LFLAGS        = -Wl,-rpath,/usr/lib64/qt4
LIBS          = $(SUBLIBS)  -L/usr/lib64/qt4 -lQtTest -L/usr/lib64 -L/usr/lib64/qt4 -lQtSql -L/usr/lib64/mysql -lQtGui -L/usr/X11R6/lib -lQtCore -lgthread-2.0 -lrt -lglib-2.0 -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		gui/MainWindow.cpp \
		gui/AddDrug.cpp \
		gui/AddDepartment.cpp \
		lib/DrugModel.cpp \
		lib/DepartmentModel.cpp \
		lib/Db.cpp \
		lib/RecipientModel.cpp \
		gui/AddRecipient.cpp \
		gui/AddRegistration.cpp \
		lib/RegistrationModel.cpp \
		gui/ShowRecipients.cpp \
		gui/ShowDrugs.cpp moc_MainWindow.cpp \
		moc_AddDrug.cpp \
		moc_AddDepartment.cpp \
		moc_AddRecipient.cpp \
		moc_AddRegistration.cpp \
		moc_ShowRecipients.cpp \
		moc_ShowDrugs.cpp
OBJECTS       = main.o \
		MainWindow.o \
		AddDrug.o \
		AddDepartment.o \
		DrugModel.o \
		DepartmentModel.o \
		Db.o \
		RecipientModel.o \
		AddRecipient.o \
		AddRegistration.o \
		RegistrationModel.o \
		ShowRecipients.o \
		ShowDrugs.o \
		moc_MainWindow.o \
		moc_AddDrug.o \
		moc_AddDepartment.o \
		moc_AddRecipient.o \
		moc_AddRegistration.o \
		moc_ShowRecipients.o \
		moc_ShowDrugs.o
DIST          = /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_phonon.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		4med.pro
QMAKE_TARGET  = 4med
DESTDIR       = bin/
TARGET        = bin/4med

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_MainWindow.h ui_AddDrug.h ui_AddDepartment.h ui_AddRecipient.h ui_AddRegistration.h ui_ShowRecipients.h ui_ShowDrugs.h $(OBJECTS)  
	@$(CHK_DIR_EXISTS) bin/ || $(MKDIR) bin/ 
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: 4med.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_phonon.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib64/qt4/libQtTest.prl \
		/usr/lib64/qt4/libQtCore.prl \
		/usr/lib64/qt4/libQtSql.prl \
		/usr/lib64/qt4/libQtGui.prl
	$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ CONFIG+=debug QMLJSDEBUGGER_PATH=/usr/share/qtcreator/qml/qmljsdebugger QMLJSDEBUGGER_PATH=/usr/share/qtcreator/qml/qmljsdebugger QMLJSDEBUGGER_PATH=/usr/share/qtcreator/qml/qmljsdebugger QMLJSDEBUGGER_PATH=/usr/share/qtcreator/qml/qmljsdebugger -o Makefile 4med.pro
/usr/share/qt4/mkspecs/common/g++.conf:
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_phonon.pri:
/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/debug.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib64/qt4/libQtTest.prl:
/usr/lib64/qt4/libQtCore.prl:
/usr/lib64/qt4/libQtSql.prl:
/usr/lib64/qt4/libQtGui.prl:
qmake:  FORCE
	@$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ CONFIG+=debug QMLJSDEBUGGER_PATH=/usr/share/qtcreator/qml/qmljsdebugger QMLJSDEBUGGER_PATH=/usr/share/qtcreator/qml/qmljsdebugger QMLJSDEBUGGER_PATH=/usr/share/qtcreator/qml/qmljsdebugger QMLJSDEBUGGER_PATH=/usr/share/qtcreator/qml/qmljsdebugger -o Makefile 4med.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/4med1.0.0 || $(MKDIR) .tmp/4med1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/4med1.0.0/ && $(COPY_FILE) --parents gui/MainWindow.h gui/AddDrug.h gui/AddDepartment.h lib/DrugModel.h lib/DepartmentModel.h lib/DefaultModel.h lib/Db.h lib/RecipientModel.h gui/AddRecipient.h gui/AddRegistration.h lib/RegistrationModel.h gui/ShowRecipients.h gui/ShowDrugs.h .tmp/4med1.0.0/ && $(COPY_FILE) --parents main.cpp gui/MainWindow.cpp gui/AddDrug.cpp gui/AddDepartment.cpp lib/DrugModel.cpp lib/DepartmentModel.cpp lib/Db.cpp lib/RecipientModel.cpp gui/AddRecipient.cpp gui/AddRegistration.cpp lib/RegistrationModel.cpp gui/ShowRecipients.cpp gui/ShowDrugs.cpp .tmp/4med1.0.0/ && $(COPY_FILE) --parents ui/MainWindow.ui ui/AddDrug.ui ui/AddDepartment.ui ui/AddRecipient.ui ui/AddRegistration.ui ui/ShowRecipients.ui ui/ShowDrugs.ui .tmp/4med1.0.0/ && (cd `dirname .tmp/4med1.0.0` && $(TAR) 4med1.0.0.tar 4med1.0.0 && $(COMPRESS) 4med1.0.0.tar) && $(MOVE) `dirname .tmp/4med1.0.0`/4med1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/4med1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_MainWindow.cpp moc_AddDrug.cpp moc_AddDepartment.cpp moc_AddRecipient.cpp moc_AddRegistration.cpp moc_ShowRecipients.cpp moc_ShowDrugs.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_MainWindow.cpp moc_AddDrug.cpp moc_AddDepartment.cpp moc_AddRecipient.cpp moc_AddRegistration.cpp moc_ShowRecipients.cpp moc_ShowDrugs.cpp
moc_MainWindow.cpp: gui/MainWindow.h
	/usr/bin/moc $(DEFINES) $(INCPATH) gui/MainWindow.h -o moc_MainWindow.cpp

moc_AddDrug.cpp: gui/AddDrug.h
	/usr/bin/moc $(DEFINES) $(INCPATH) gui/AddDrug.h -o moc_AddDrug.cpp

moc_AddDepartment.cpp: gui/AddDepartment.h
	/usr/bin/moc $(DEFINES) $(INCPATH) gui/AddDepartment.h -o moc_AddDepartment.cpp

moc_AddRecipient.cpp: gui/AddRecipient.h
	/usr/bin/moc $(DEFINES) $(INCPATH) gui/AddRecipient.h -o moc_AddRecipient.cpp

moc_AddRegistration.cpp: gui/AddRegistration.h
	/usr/bin/moc $(DEFINES) $(INCPATH) gui/AddRegistration.h -o moc_AddRegistration.cpp

moc_ShowRecipients.cpp: gui/ShowRecipients.h
	/usr/bin/moc $(DEFINES) $(INCPATH) gui/ShowRecipients.h -o moc_ShowRecipients.cpp

moc_ShowDrugs.cpp: gui/ShowDrugs.h
	/usr/bin/moc $(DEFINES) $(INCPATH) gui/ShowDrugs.h -o moc_ShowDrugs.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_MainWindow.h ui_AddDrug.h ui_AddDepartment.h ui_AddRecipient.h ui_AddRegistration.h ui_ShowRecipients.h ui_ShowDrugs.h
compiler_uic_clean:
	-$(DEL_FILE) ui_MainWindow.h ui_AddDrug.h ui_AddDepartment.h ui_AddRecipient.h ui_AddRegistration.h ui_ShowRecipients.h ui_ShowDrugs.h
ui_MainWindow.h: ui/MainWindow.ui
	/usr/bin/uic ui/MainWindow.ui -o ui_MainWindow.h

ui_AddDrug.h: ui/AddDrug.ui
	/usr/bin/uic ui/AddDrug.ui -o ui_AddDrug.h

ui_AddDepartment.h: ui/AddDepartment.ui
	/usr/bin/uic ui/AddDepartment.ui -o ui_AddDepartment.h

ui_AddRecipient.h: ui/AddRecipient.ui
	/usr/bin/uic ui/AddRecipient.ui -o ui_AddRecipient.h

ui_AddRegistration.h: ui/AddRegistration.ui
	/usr/bin/uic ui/AddRegistration.ui -o ui_AddRegistration.h

ui_ShowRecipients.h: ui/ShowRecipients.ui
	/usr/bin/uic ui/ShowRecipients.ui -o ui_ShowRecipients.h

ui_ShowDrugs.h: ui/ShowDrugs.ui
	/usr/bin/uic ui/ShowDrugs.ui -o ui_ShowDrugs.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

main.o: main.cpp gui/MainWindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

MainWindow.o: gui/MainWindow.cpp gui/MainWindow.h \
		ui_MainWindow.h \
		lib/Db.h \
		gui/AddDrug.h \
		gui/AddDepartment.h \
		gui/AddRecipient.h \
		gui/AddRegistration.h \
		gui/ShowRecipients.h \
		gui/ShowDrugs.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o MainWindow.o gui/MainWindow.cpp

AddDrug.o: gui/AddDrug.cpp gui/AddDrug.h \
		ui_AddDrug.h \
		lib/DrugModel.h \
		lib/DefaultModel.h \
		lib/Db.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o AddDrug.o gui/AddDrug.cpp

AddDepartment.o: gui/AddDepartment.cpp gui/AddDepartment.h \
		ui_AddDepartment.h \
		lib/DepartmentModel.h \
		lib/DefaultModel.h \
		lib/Db.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o AddDepartment.o gui/AddDepartment.cpp

DrugModel.o: lib/DrugModel.cpp lib/DrugModel.h \
		lib/DefaultModel.h \
		lib/Db.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o DrugModel.o lib/DrugModel.cpp

DepartmentModel.o: lib/DepartmentModel.cpp lib/DepartmentModel.h \
		lib/DefaultModel.h \
		lib/Db.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o DepartmentModel.o lib/DepartmentModel.cpp

Db.o: lib/Db.cpp lib/Db.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Db.o lib/Db.cpp

RecipientModel.o: lib/RecipientModel.cpp lib/RecipientModel.h \
		lib/DefaultModel.h \
		lib/Db.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o RecipientModel.o lib/RecipientModel.cpp

AddRecipient.o: gui/AddRecipient.cpp gui/AddRecipient.h \
		ui_AddRecipient.h \
		lib/RecipientModel.h \
		lib/DefaultModel.h \
		lib/Db.h \
		lib/DepartmentModel.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o AddRecipient.o gui/AddRecipient.cpp

AddRegistration.o: gui/AddRegistration.cpp gui/AddRegistration.h \
		ui_AddRegistration.h \
		lib/DrugModel.h \
		lib/DefaultModel.h \
		lib/DepartmentModel.h \
		lib/RecipientModel.h \
		lib/RegistrationModel.h \
		lib/Db.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o AddRegistration.o gui/AddRegistration.cpp

RegistrationModel.o: lib/RegistrationModel.cpp lib/RegistrationModel.h \
		lib/DefaultModel.h \
		lib/Db.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o RegistrationModel.o lib/RegistrationModel.cpp

ShowRecipients.o: gui/ShowRecipients.cpp gui/ShowRecipients.h \
		ui_ShowRecipients.h \
		lib/DepartmentModel.h \
		lib/DefaultModel.h \
		lib/RecipientModel.h \
		gui/AddDepartment.h \
		gui/AddRecipient.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ShowRecipients.o gui/ShowRecipients.cpp

ShowDrugs.o: gui/ShowDrugs.cpp gui/ShowDrugs.h \
		ui_ShowDrugs.h \
		lib/DrugModel.h \
		lib/DefaultModel.h \
		gui/AddDrug.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ShowDrugs.o gui/ShowDrugs.cpp

moc_MainWindow.o: moc_MainWindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_MainWindow.o moc_MainWindow.cpp

moc_AddDrug.o: moc_AddDrug.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_AddDrug.o moc_AddDrug.cpp

moc_AddDepartment.o: moc_AddDepartment.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_AddDepartment.o moc_AddDepartment.cpp

moc_AddRecipient.o: moc_AddRecipient.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_AddRecipient.o moc_AddRecipient.cpp

moc_AddRegistration.o: moc_AddRegistration.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_AddRegistration.o moc_AddRegistration.cpp

moc_ShowRecipients.o: moc_ShowRecipients.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_ShowRecipients.o moc_ShowRecipients.cpp

moc_ShowDrugs.o: moc_ShowDrugs.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_ShowDrugs.o moc_ShowDrugs.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

