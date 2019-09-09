#ifndef XOEXAMPLEAPP_H
#define XOEXAMPLEAPP_H

#include <QGenericPlugin>
#include "ComponentBase.h"
#include "ModuleBaseAppONB.h"

Q_DECLARE_INTERFACE(ModuleBaseAppONB, "xo.ModuleBaseLibONB/1.0")

class xoExampleModuleApp : public ModuleBaseAppONB
{
    Q_OBJECT
    Q_INTERFACES(ModuleBaseAppONB)
    Q_PLUGIN_METADATA(IID "xorde.Qt.xoPlugin" FILE "xoExampleModuleApp.json")
public:
    explicit xoExampleModuleApp(QString ip = "127.0.0.1", QString port = "8080");
};

#endif // XOEXAMPLEAPP_H
