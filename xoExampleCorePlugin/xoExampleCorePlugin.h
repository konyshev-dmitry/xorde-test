#ifndef XO_EXAMPLE_CORE_PLUGIN_H
#define XO_EXAMPLE_CORE_PLUGIN_H

#include <QObject>
#include "xoCorePlugin.h"
#include "ExampleGuiWidget.h"

/* Make the topmost class (e.g. "XXX") a xoCorePlugin child
 * All "Q_..." marcos are required
 * The XXX.json file is empty and needed only by the QtPlugin subsystem
 * */

Q_DECLARE_INTERFACE(xoCorePlugin, "xo.CorePlugin/1.0")
class xoExampleCorePlugin : public xoCorePlugin
{
Q_OBJECT
Q_INTERFACES(xoCorePlugin)
Q_PLUGIN_METADATA(IID "xorde.Qt.xoCorePlugin" FILE "xoExampleCorePlugin.json")
public:
    explicit xoExampleCorePlugin(QObject *parent = nullptr);

    void start() override;
    bool providesUI() override { return true; }

protected:
    ExampleGuiWidget *m_widget = nullptr;
};

#endif // XO_EXAMPLE_CORE_PLUGIN_H
