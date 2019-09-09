#include "xoExampleModuleApp.h"
#include "ExampleSlidersComponent.h"

xoExampleModuleApp::xoExampleModuleApp(QString ip, QString port) : ModuleBaseAppONB("xoExampleModuleApp", ip, port)
{
    declareComponent(new ExampleSlidersComponent);
}
