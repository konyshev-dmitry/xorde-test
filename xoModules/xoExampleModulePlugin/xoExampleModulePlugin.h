#ifndef XO_EXAMPLE_MODULE_PLUGIN_H
#define XO_EXAMPLE_MODULE_PLUGIN_H

#include "ModuleBaseAppONB.h"

Q_DECLARE_INTERFACE(ModuleBaseAppONB, "xo.ModuleBaseLibONB/1.0")
class xoExampleModulePlugin : public ModuleBaseAppONB
{
    Q_OBJECT
    Q_INTERFACES(ModuleBaseAppONB)
    Q_PLUGIN_METADATA(IID "xorde.Qt.xoPlugin" FILE "xoExampleModulePlugin.json")

public:
    xoExampleModulePlugin();
};

#endif // XO_EXAMPLE_MODULE_PLUGIN_H
