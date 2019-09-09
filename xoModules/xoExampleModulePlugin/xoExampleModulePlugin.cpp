#include "Multiply.h"
#include "PlusOne.h"
#include "xoExampleModulePlugin.h"
#include <QJsonDocument>

xoExampleModulePlugin::xoExampleModulePlugin() : ModuleBaseAppONB("xoExampleModulePlugin", "127.0.0.1", "8080")
{
    setIcon(":/images/test-tube-empty.svg");
    declareComponent(new PlusOne);
    declareComponent(new Multiply);
}

