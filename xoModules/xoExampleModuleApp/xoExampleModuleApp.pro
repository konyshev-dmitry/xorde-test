QT *= core widgets network
TARGET = xoExampleModuleApp

include("../../xoTools/Application.pri")

SOURCES += \
    ExampleSlidersComponent.cpp \
    xoExampleModuleApp.cpp \

HEADERS += \
    ExampleSlidersComponent.h \
    xoExampleModuleApp.h

SOURCES += main.cpp mainwindow.cpp
HEADERS += mainwindow.h

DISTFILES += xoCV.json
RESOURCES += xoExampleModuleApp.qrc

win32: RC_ICONS += images/test-tube.ico

