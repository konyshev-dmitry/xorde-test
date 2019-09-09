TEMPLATE = subdirs
CONFIG += ordered

SUBDIRS += \
    ../components5/usbhid \
    ../NeuroboticsToolkit


win32-msvc: SUBDIRS +=  ../NeuroboticsToolkit.CV

SUBDIRS += \
    xoTools \
    xoCore \
    xoGUI \
    xoWebServer \    
    xoJavaScriptConsole \
    xoExampleCorePlugin \
    xoModules \
    xoRDE

OTHER_FILES += \
    Doxyfile \
    doxy.css
