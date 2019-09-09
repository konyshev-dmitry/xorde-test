#include "ExampleGuiWidget.h"
#include <QGridLayout>
#include "fileutilities.h"
#include "Core.h"
#include "Toolkit/ui/GlobalConsoleWidget.h"
#include <QMessageBox>

ExampleGuiWidget::ExampleGuiWidget(QWidget *parent) : QWidget(parent)
{
    m_btnReload = new QPushButton("Reload schemes");
    connect(m_btnReload, SIGNAL(clicked()), this, SLOT(reloadSchemes()));

    m_btnStart = new QPushButton("Start");
    connect(m_btnStart, &QPushButton::clicked, [=]() { Core::Instance()->getHub()->setIsEnabled(true); });

    m_btnStop = new QPushButton("Stop");
    connect(m_btnStop, &QPushButton::clicked, [=]() { Core::Instance()->getHub()->setIsEnabled(false); });

    m_comboSchemes = new QComboBox();
    connect(m_comboSchemes, SIGNAL(currentTextChanged(const QString &)), SLOT(setCurrentScheme(const QString &)));

    auto grid = new QGridLayout(this);

    grid->addWidget(m_btnReload, 0, 0);
    grid->addWidget(m_btnStart, 0, 1);
    grid->addWidget(m_btnStop, 0, 2);

    grid->addWidget(new QLabel("Scheme:"), 1, 0);
    grid->addWidget(m_comboSchemes, 1, 1, 1, 2);

    grid->addWidget(new GlobalConsoleWidget(), 2, 0, 1, 3);

    reloadSchemes();
}

void ExampleGuiWidget::reloadSchemes()
{
    if (!m_comboSchemes) return;

    m_comboSchemes->blockSignals(true);
    m_comboSchemes->clear();
    m_comboSchemes->addItem("");
    QStringList schemes = FileUtilities::getFilesOfType(Core::FolderSchemes, Core::FileExtensionScheme);

    foreach(QString scheme, schemes)
    {
        m_comboSchemes->addItem(scheme);
    }
    m_comboSchemes->blockSignals(false);
}

void ExampleGuiWidget::setCurrentScheme(const QString &schemeName)
{
    Core::Instance()->getHub()->setIsEnabled(false);
    if (schemeName.isEmpty())
    {
        Core::Instance()->getScheme()->clear();
    }
    else if (Core::Instance()->loadScheme(Core::FolderSchemes+schemeName))
    {
        m_comboSchemes->blockSignals(true);
        m_comboSchemes->setCurrentText(schemeName);
        m_comboSchemes->blockSignals(false);
    }
    else
    {
        QMessageBox::warning(this, tr("Invalid scheme"), tr("Cannot load") + "\n" + schemeName);
    }
}
