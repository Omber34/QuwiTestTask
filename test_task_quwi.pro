QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

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
    Authentificator.cpp \
    Command.cpp \
    DebugWindow.cpp \
    LoginForm.cpp \
    Loginer.cpp \
    LogoCacher.cpp \
    MainWindow.cpp \
    MyApplication.cpp \
    NetworkManager.cpp \
    ProjectEditDialog.cpp \
    ProjectEditor.cpp \
    ProjectInfo.cpp \
    ProjectItemDelegate.cpp \
    ProjectListModel.cpp \
    ProjectLoader.cpp \
    UserInfo.cpp \
    main.cpp

HEADERS += \
    Authentificator.h \
    Command.h \
    DebugWindow.h \
    LoginForm.h \
    Loginer.h \
    LogoCacher.h \
    MainWindow.h \
    MyApplication.h \
    NetworkManager.h \
    ProjectEditDialog.h \
    ProjectEditor.h \
    ProjectInfo.h \
    ProjectItemDelegate.h \
    ProjectListModel.h \
    ProjectLoader.h \
    UserInfo.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
    DebugWindowUI.ui \
    LoginFormUI.ui \
    MainWindowUI.ui \
    ProjectEditFormUI.ui
