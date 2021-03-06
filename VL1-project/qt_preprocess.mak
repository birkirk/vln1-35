#############################################################################
# Makefile for building: VL1-project
# Generated by qmake (3.0) (Qt 5.7.0)
# Project:  VL1-project.pro
# Template: app
# Command: /Users/Birkir/Qt/5.7/clang_64/bin/qmake -spec macx-xcode -o project.pbxproj VL1-project.pro
#############################################################################

MAKEFILE      = project.pbxproj

MOC       = /Users/Birkir/Qt/5.7/clang_64/bin/moc
UIC       = /Users/Birkir/Qt/5.7/clang_64/bin/uic
LEX       = flex
LEXFLAGS  = 
YACC      = yacc
YACCFLAGS = -d
DEFINES       = -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_SQL_LIB -DQT_CORE_LIB
INCPATH       = -I. -I../../../Qt/5.7/clang_64/lib/QtWidgets.framework/Headers -I../../../Qt/5.7/clang_64/lib/QtGui.framework/Headers -I../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers -I../../../Qt/5.7/clang_64/lib/QtCore.framework/Headers -I. -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.12.sdk/System/Library/Frameworks/OpenGL.framework/Headers -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.12.sdk/System/Library/Frameworks/AGL.framework/Headers -I. -I../../../Qt/5.7/clang_64/mkspecs/macx-clang -F/Users/Birkir/Qt/5.7/clang_64/lib
DEL_FILE  = rm -f
MOVE      = mv -f

preprocess: compilers
clean preprocess_clean: compiler_clean

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

check: first

benchmark: first

compilers: moc_mainwindow.cpp moc_addscientistwindow.cpp moc_addcomputerwindow.cpp\
	 moc_scientistinfowindow.cpp moc_computerinfowindow.cpp ui_mainwindow.h ui_addcomputerwindow.h ui_scientistinfowindow.h\
	 ui_addscientistwindow.h ui_computerinfowindow.h
compiler_rcc_make_all:
compiler_rcc_clean:
compiler_moc_header_make_all: moc_mainwindow.cpp moc_addscientistwindow.cpp moc_addcomputerwindow.cpp moc_scientistinfowindow.cpp moc_computerinfowindow.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_mainwindow.cpp moc_addscientistwindow.cpp moc_addcomputerwindow.cpp moc_scientistinfowindow.cpp moc_computerinfowindow.cpp
moc_mainwindow.cpp: ../../../Qt/5.7/clang_64/lib/QtWidgets.framework/Headers/QMainWindow \
		../../../Qt/5.7/clang_64/lib/QtWidgets.framework/Headers/qmainwindow.h \
		servicelayer.h \
		scientist.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/QtSql \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsql.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsqldatabase.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsqldriver.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsqldriverplugin.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsqlerror.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsqlfield.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsqlindex.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsqlquery.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsqlrecord.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsqlresult.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsqlquerymodel.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsqlrelationaldelegate.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsqlrelationaltablemodel.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsqltablemodel.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qtsqlversion.h \
		computer.h \
		datalayer.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/QSqlQuery \
		../../../Qt/5.7/clang_64/lib/QtCore.framework/Headers/QDebug \
		../../../Qt/5.7/clang_64/lib/QtCore.framework/Headers/qdebug.h \
		../../../Qt/5.7/clang_64/lib/QtCore.framework/Headers/QChar \
		../../../Qt/5.7/clang_64/lib/QtCore.framework/Headers/qchar.h \
		../../../Qt/5.7/clang_64/lib/QtCore.framework/Headers/QString \
		../../../Qt/5.7/clang_64/lib/QtCore.framework/Headers/qstring.h \
		../../../Qt/5.7/clang_64/lib/QtCore.framework/Headers/QFile \
		../../../Qt/5.7/clang_64/lib/QtCore.framework/Headers/qfile.h \
		../../../Qt/5.7/clang_64/lib/QtWidgets.framework/Headers/QMessageBox \
		../../../Qt/5.7/clang_64/lib/QtWidgets.framework/Headers/qmessagebox.h \
		mainwindow.h \
		../../../Qt/5.7/clang_64/bin/moc
	/Users/Birkir/Qt/5.7/clang_64/bin/moc $(DEFINES) -D__APPLE__ -D__GNUC__=4 -D__APPLE_CC__ -I/Users/Birkir/Qt/5.7/clang_64/mkspecs/macx-clang -I/Users/Birkir/Desktop/vln1-35/VL1-project -I/Users/Birkir/Qt/5.7/clang_64/lib/QtWidgets.framework/Headers -I/Users/Birkir/Qt/5.7/clang_64/lib/QtGui.framework/Headers -I/Users/Birkir/Qt/5.7/clang_64/lib/QtSql.framework/Headers -I/Users/Birkir/Qt/5.7/clang_64/lib/QtCore.framework/Headers -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/c++/v1 -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/8.0.0/include -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.12.sdk/usr/include -I'/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.12.sdk/System/Library/Frameworks (framework directory)' -F/Users/Birkir/Qt/5.7/clang_64/lib mainwindow.h -o moc_mainwindow.cpp

moc_addscientistwindow.cpp: scientist.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/QtSql \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsql.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsqldatabase.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsqldriver.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsqldriverplugin.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsqlerror.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsqlfield.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsqlindex.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsqlquery.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsqlrecord.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsqlresult.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsqlquerymodel.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsqlrelationaldelegate.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsqlrelationaltablemodel.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsqltablemodel.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qtsqlversion.h \
		servicelayer.h \
		computer.h \
		datalayer.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/QSqlQuery \
		../../../Qt/5.7/clang_64/lib/QtCore.framework/Headers/QDebug \
		../../../Qt/5.7/clang_64/lib/QtCore.framework/Headers/qdebug.h \
		../../../Qt/5.7/clang_64/lib/QtCore.framework/Headers/QChar \
		../../../Qt/5.7/clang_64/lib/QtCore.framework/Headers/qchar.h \
		../../../Qt/5.7/clang_64/lib/QtCore.framework/Headers/QString \
		../../../Qt/5.7/clang_64/lib/QtCore.framework/Headers/qstring.h \
		../../../Qt/5.7/clang_64/lib/QtCore.framework/Headers/QFile \
		../../../Qt/5.7/clang_64/lib/QtCore.framework/Headers/qfile.h \
		../../../Qt/5.7/clang_64/lib/QtWidgets.framework/Headers/QDialog \
		../../../Qt/5.7/clang_64/lib/QtWidgets.framework/Headers/qdialog.h \
		addscientistwindow.h \
		../../../Qt/5.7/clang_64/bin/moc
	/Users/Birkir/Qt/5.7/clang_64/bin/moc $(DEFINES) -D__APPLE__ -D__GNUC__=4 -D__APPLE_CC__ -I/Users/Birkir/Qt/5.7/clang_64/mkspecs/macx-clang -I/Users/Birkir/Desktop/vln1-35/VL1-project -I/Users/Birkir/Qt/5.7/clang_64/lib/QtWidgets.framework/Headers -I/Users/Birkir/Qt/5.7/clang_64/lib/QtGui.framework/Headers -I/Users/Birkir/Qt/5.7/clang_64/lib/QtSql.framework/Headers -I/Users/Birkir/Qt/5.7/clang_64/lib/QtCore.framework/Headers -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/c++/v1 -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/8.0.0/include -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.12.sdk/usr/include -I'/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.12.sdk/System/Library/Frameworks (framework directory)' -F/Users/Birkir/Qt/5.7/clang_64/lib addscientistwindow.h -o moc_addscientistwindow.cpp

moc_addcomputerwindow.cpp: servicelayer.h \
		scientist.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/QtSql \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsql.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsqldatabase.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsqldriver.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsqldriverplugin.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsqlerror.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsqlfield.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsqlindex.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsqlquery.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsqlrecord.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsqlresult.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsqlquerymodel.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsqlrelationaldelegate.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsqlrelationaltablemodel.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsqltablemodel.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qtsqlversion.h \
		computer.h \
		datalayer.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/QSqlQuery \
		../../../Qt/5.7/clang_64/lib/QtCore.framework/Headers/QDebug \
		../../../Qt/5.7/clang_64/lib/QtCore.framework/Headers/qdebug.h \
		../../../Qt/5.7/clang_64/lib/QtCore.framework/Headers/QChar \
		../../../Qt/5.7/clang_64/lib/QtCore.framework/Headers/qchar.h \
		../../../Qt/5.7/clang_64/lib/QtCore.framework/Headers/QString \
		../../../Qt/5.7/clang_64/lib/QtCore.framework/Headers/qstring.h \
		../../../Qt/5.7/clang_64/lib/QtCore.framework/Headers/QFile \
		../../../Qt/5.7/clang_64/lib/QtCore.framework/Headers/qfile.h \
		../../../Qt/5.7/clang_64/lib/QtWidgets.framework/Headers/QDialog \
		../../../Qt/5.7/clang_64/lib/QtWidgets.framework/Headers/qdialog.h \
		addcomputerwindow.h \
		../../../Qt/5.7/clang_64/bin/moc
	/Users/Birkir/Qt/5.7/clang_64/bin/moc $(DEFINES) -D__APPLE__ -D__GNUC__=4 -D__APPLE_CC__ -I/Users/Birkir/Qt/5.7/clang_64/mkspecs/macx-clang -I/Users/Birkir/Desktop/vln1-35/VL1-project -I/Users/Birkir/Qt/5.7/clang_64/lib/QtWidgets.framework/Headers -I/Users/Birkir/Qt/5.7/clang_64/lib/QtGui.framework/Headers -I/Users/Birkir/Qt/5.7/clang_64/lib/QtSql.framework/Headers -I/Users/Birkir/Qt/5.7/clang_64/lib/QtCore.framework/Headers -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/c++/v1 -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/8.0.0/include -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.12.sdk/usr/include -I'/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.12.sdk/System/Library/Frameworks (framework directory)' -F/Users/Birkir/Qt/5.7/clang_64/lib addcomputerwindow.h -o moc_addcomputerwindow.cpp

moc_scientistinfowindow.cpp: scientist.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/QtSql \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsql.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsqldatabase.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsqldriver.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsqldriverplugin.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsqlerror.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsqlfield.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsqlindex.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsqlquery.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsqlrecord.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsqlresult.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsqlquerymodel.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsqlrelationaldelegate.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsqlrelationaltablemodel.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsqltablemodel.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qtsqlversion.h \
		servicelayer.h \
		computer.h \
		datalayer.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/QSqlQuery \
		../../../Qt/5.7/clang_64/lib/QtCore.framework/Headers/QDebug \
		../../../Qt/5.7/clang_64/lib/QtCore.framework/Headers/qdebug.h \
		../../../Qt/5.7/clang_64/lib/QtCore.framework/Headers/QChar \
		../../../Qt/5.7/clang_64/lib/QtCore.framework/Headers/qchar.h \
		../../../Qt/5.7/clang_64/lib/QtCore.framework/Headers/QString \
		../../../Qt/5.7/clang_64/lib/QtCore.framework/Headers/qstring.h \
		../../../Qt/5.7/clang_64/lib/QtCore.framework/Headers/QFile \
		../../../Qt/5.7/clang_64/lib/QtCore.framework/Headers/qfile.h \
		../../../Qt/5.7/clang_64/lib/QtWidgets.framework/Headers/QDialog \
		../../../Qt/5.7/clang_64/lib/QtWidgets.framework/Headers/qdialog.h \
		scientistinfowindow.h \
		../../../Qt/5.7/clang_64/bin/moc
	/Users/Birkir/Qt/5.7/clang_64/bin/moc $(DEFINES) -D__APPLE__ -D__GNUC__=4 -D__APPLE_CC__ -I/Users/Birkir/Qt/5.7/clang_64/mkspecs/macx-clang -I/Users/Birkir/Desktop/vln1-35/VL1-project -I/Users/Birkir/Qt/5.7/clang_64/lib/QtWidgets.framework/Headers -I/Users/Birkir/Qt/5.7/clang_64/lib/QtGui.framework/Headers -I/Users/Birkir/Qt/5.7/clang_64/lib/QtSql.framework/Headers -I/Users/Birkir/Qt/5.7/clang_64/lib/QtCore.framework/Headers -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/c++/v1 -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/8.0.0/include -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.12.sdk/usr/include -I'/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.12.sdk/System/Library/Frameworks (framework directory)' -F/Users/Birkir/Qt/5.7/clang_64/lib scientistinfowindow.h -o moc_scientistinfowindow.cpp

moc_computerinfowindow.cpp: servicelayer.h \
		scientist.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/QtSql \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsql.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsqldatabase.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsqldriver.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsqldriverplugin.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsqlerror.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsqlfield.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsqlindex.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsqlquery.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsqlrecord.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsqlresult.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsqlquerymodel.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsqlrelationaldelegate.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsqlrelationaltablemodel.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qsqltablemodel.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/qtsqlversion.h \
		computer.h \
		datalayer.h \
		../../../Qt/5.7/clang_64/lib/QtSql.framework/Headers/QSqlQuery \
		../../../Qt/5.7/clang_64/lib/QtCore.framework/Headers/QDebug \
		../../../Qt/5.7/clang_64/lib/QtCore.framework/Headers/qdebug.h \
		../../../Qt/5.7/clang_64/lib/QtCore.framework/Headers/QChar \
		../../../Qt/5.7/clang_64/lib/QtCore.framework/Headers/qchar.h \
		../../../Qt/5.7/clang_64/lib/QtCore.framework/Headers/QString \
		../../../Qt/5.7/clang_64/lib/QtCore.framework/Headers/qstring.h \
		../../../Qt/5.7/clang_64/lib/QtCore.framework/Headers/QFile \
		../../../Qt/5.7/clang_64/lib/QtCore.framework/Headers/qfile.h \
		../../../Qt/5.7/clang_64/lib/QtWidgets.framework/Headers/QDialog \
		../../../Qt/5.7/clang_64/lib/QtWidgets.framework/Headers/qdialog.h \
		computerinfowindow.h \
		../../../Qt/5.7/clang_64/bin/moc
	/Users/Birkir/Qt/5.7/clang_64/bin/moc $(DEFINES) -D__APPLE__ -D__GNUC__=4 -D__APPLE_CC__ -I/Users/Birkir/Qt/5.7/clang_64/mkspecs/macx-clang -I/Users/Birkir/Desktop/vln1-35/VL1-project -I/Users/Birkir/Qt/5.7/clang_64/lib/QtWidgets.framework/Headers -I/Users/Birkir/Qt/5.7/clang_64/lib/QtGui.framework/Headers -I/Users/Birkir/Qt/5.7/clang_64/lib/QtSql.framework/Headers -I/Users/Birkir/Qt/5.7/clang_64/lib/QtCore.framework/Headers -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/c++/v1 -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/8.0.0/include -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.12.sdk/usr/include -I'/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.12.sdk/System/Library/Frameworks (framework directory)' -F/Users/Birkir/Qt/5.7/clang_64/lib computerinfowindow.h -o moc_computerinfowindow.cpp

compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_mainwindow.h ui_addcomputerwindow.h ui_scientistinfowindow.h ui_addscientistwindow.h ui_computerinfowindow.h
compiler_uic_clean:
	-$(DEL_FILE) ui_mainwindow.h ui_addcomputerwindow.h ui_scientistinfowindow.h ui_addscientistwindow.h ui_computerinfowindow.h
ui_mainwindow.h: mainwindow.ui \
		../../../Qt/5.7/clang_64/bin/uic
	/Users/Birkir/Qt/5.7/clang_64/bin/uic mainwindow.ui -o ui_mainwindow.h

ui_addcomputerwindow.h: addcomputerwindow.ui \
		../../../Qt/5.7/clang_64/bin/uic
	/Users/Birkir/Qt/5.7/clang_64/bin/uic addcomputerwindow.ui -o ui_addcomputerwindow.h

ui_scientistinfowindow.h: scientistinfowindow.ui \
		../../../Qt/5.7/clang_64/bin/uic
	/Users/Birkir/Qt/5.7/clang_64/bin/uic scientistinfowindow.ui -o ui_scientistinfowindow.h

ui_addscientistwindow.h: addscientistwindow.ui \
		../../../Qt/5.7/clang_64/bin/uic
	/Users/Birkir/Qt/5.7/clang_64/bin/uic addscientistwindow.ui -o ui_addscientistwindow.h

ui_computerinfowindow.h: computerinfowindow.ui \
		../../../Qt/5.7/clang_64/bin/uic
	/Users/Birkir/Qt/5.7/clang_64/bin/uic computerinfowindow.ui -o ui_computerinfowindow.h

compiler_rez_source_make_all:
compiler_rez_source_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

