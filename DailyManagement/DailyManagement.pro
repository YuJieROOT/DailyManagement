QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG += sdk_no_version_check
CONFIG += resources_big

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ClickWidget.cpp \
    MyLabelEdit.cpp \
    calendarPage.cpp \
    countdownPage.cpp \
    dustbinPage.cpp \
    logPage.cpp \
    main.cpp \
    searchPage.cpp \
    settingPage.cpp \
    todoPage.cpp \
    ui_logic.cpp \
    userPage.cpp \
    database.cpp

HEADERS += \
    ClickWidget.h \
    MyLabelEdit.h \
    calendarPage.h \
    countdownPage.h \
    dustbinPage.h \
    logPage.h \
    myDebug.h \
    searchPage.h \
    settingPage.h \
    todoPage.h \
    ui_logic.h \
    userPage.h \
    database.h

FORMS += \
    calendarPage.ui \
    countdownPage.ui \
    dustbinPage.ui \
    logPage.ui \
    searchPage.ui \
    settingPage.ui \
    todoPage.ui \
    userPage.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    rsc.qrc
