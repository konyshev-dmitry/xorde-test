QT       += core network
TARGET = xoExampleModulePlugin

include("../../xoTools/Plugin.pri")

SOURCES += \
        PlusOne.cpp \
        Multiply.cpp \
        xoExampleModulePlugin.cpp

HEADERS += \
        PlusOne.h \
        Multiply.h \
        xoExampleModulePlugin.h

DISTFILES += xoExampleModulePlugin.json

RESOURCES += xoExampleModulePlugin.qrc
