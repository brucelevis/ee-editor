include(../libraries/cocos2d/cocos2d.pri)

QT += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = editor
TEMPLATE = app

QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.11

CONFIG += c++1z
CONFIG += staticlib

DEFINES += QT_DEPRECATED_WARNINGS

INCLUDEPATH += \
    ../libraries

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    projectsettings.cpp \
    projectsettingsdialog.cpp \
    config.cpp \
    settings.cpp \
    contentprotectionkey.cpp \
    iserializable.cpp \
    appdelegate.cpp \
    openglwidget.cpp \
    rootscene.cpp \
    utils.cpp \
    glsledit.cpp \
    glslhighlighter.cpp \
    glsleditsidebar.cpp

HEADERS += \
    mainwindow.hpp \
    projectsettings.hpp \
    projectsettingsdialog.hpp \
    config.hpp \
    optional.hpp \
    settings.hpp \
    contentprotectionkey.hpp \
    iserializable.hpp \
    appdelegate.hpp \
    openglwidget.hpp \
    rootscene.hpp \
    utils.hpp \
    glsledit.hpp \
    glslhighlighter.hpp \
    glslcomponent.hpp \
    glsleditsidebar.hpp

FORMS += \
    mainwindow.ui \
    projectsettingsdialog.ui

COCOS2DX_ROOT=$$PWD/../libraries/cocos2d

#LIBS += -L$$OUT_PWD/../libraries/cocos2d/ -lcocos2d
#INCLUDEPATH += $$PWD/../libraries/cocos2d
#DEPENDPATH += $$PWD/../libraries/cocos2d
#PRE_TARGETDEPS += $$OUT_PWD/../libraries/cocos2d/libcocos2d.a
