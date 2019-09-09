QT += core gui widgets svg
TARGET = xoExampleCorePlugin

include("../xoCore/xoCorePlugin.pri")

SOURCES += \
    xoExampleCorePlugin.cpp \
    ExampleGuiWidget.cpp

HEADERS += \
    xoExampleCorePlugin.h \
    ExampleGuiWidget.h

RESOURCES += \
    xoexamplecoreplugin.qrc

