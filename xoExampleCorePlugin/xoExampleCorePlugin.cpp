#include "xoExampleCorePlugin.h"
#include "Core.h"
#include "fileutilities.h"

xoExampleCorePlugin::xoExampleCorePlugin(QObject *parent) : xoCorePlugin(parent)
{
}


void xoExampleCorePlugin::start()
{
    //qDebug() << FileUtilities::getFilesOfType(Core::FolderSchemes, Core::FileExtensionScheme);
    //qDebug() << Core::FolderModules + "xoExampleModuleApp" << QDir(Core::FolderModules + "xoExampleModuleApp").exists()
    //Copy example schemes if there are no schemes and corresponding modules exists
    if (FileUtilities::getFilesOfType(Core::FolderSchemes, Core::FileExtensionScheme).count() == 0)
    {
        FileUtilities::createIfNotExists(Core::FolderSchemes);
        if (QDir(Core::FolderModules + "xoExampleModuleApp").exists())
        {
            QFile::copy(":/exampleSchemes/Example 1.scheme", Core::FolderSchemes + "Example 1.scheme");

            if (QDir(Core::FolderPlugins + "xoExampleModulePlugin").exists())
            {
                QFile::copy(":/exampleSchemes/Example 2.scheme", Core::FolderSchemes + "Example 2.scheme");
            }
        }
    }

    m_widget = new ExampleGuiWidget();
    m_widget->show();
}
