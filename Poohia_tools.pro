#-------------------------------------------------
#
# Project created by QtCreator 2015-11-15T17:10:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Poohia_tools
TEMPLATE = app

RC_FILE = myapp.rc

SOURCES += main.cpp\
        viewobject.cpp \
    module.cpp \
    updateobject.cpp


HEADERS  += viewobject.h \
    module.h \
updateobject.h


FORMS    += viewobject.ui



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../qt-solutions-master/qtservice/lib/ -lQtSolutions_Service-head
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../qt-solutions-master/qtservice/lib/ -lQtSolutions_Service-headd

INCLUDEPATH += $$PWD/../qt-solutions-master/qtservice/src
DEPENDPATH += $$PWD/../qt-solutions-master/qtservice/src

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../qt-solutions-master/qtservice/lib/libQtSolutions_Service-head.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../qt-solutions-master/qtservice/lib/libQtSolutions_Service-headd.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../qt-solutions-master/qtservice/lib/QtSolutions_Service-head.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../qt-solutions-master/qtservice/lib/QtSolutions_Service-headd.lib

win32: LIBS += -L$$PWD/../Poohia_settings/release/ -lPoohia_settings

INCLUDEPATH += $$PWD/../Poohia_settings/
DEPENDPATH += $$PWD/../Poohia_settings/

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../qt-solutions-master/qtsingleapplication/lib/ -lQt5Solutions_SingleApplication-head
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../qt-solutions-master/qtsingleapplication/lib/ -lQt5Solutions_SingleApplication-headd

INCLUDEPATH += $$PWD/../qt-solutions-master/qtsingleapplication/src
DEPENDPATH += $$PWD/../qt-solutions-master/qtsingleapplication/src

RESOURCES += \
    ressources.qrc
