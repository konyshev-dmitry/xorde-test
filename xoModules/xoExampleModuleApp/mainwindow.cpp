#include "mainwindow.h"
#include "xoExampleModuleApp.h"
#include "ui/GlobalConsoleWidget.h"

MainWindow::MainWindow(QString ip, QString port, QWidget *parent) : QMainWindow(parent)
{
    m_module = new xoExampleModuleApp(ip, port);
    m_module->setIcon(":/images/xocv.png");

    m_module->tryConnect();

    QPushButton *connectButton = new QPushButton("Connect");
    connect(connectButton, &QPushButton::clicked, [=](){m_module->tryConnect();});

    setCentralWidget(new QWidget());

    auto layout = new QVBoxLayout(centralWidget());
    layout->addWidget(connectButton);
    layout->addWidget(new GlobalConsoleWidget(), 100);
}

MainWindow::~MainWindow()
{
    //delete comp;
    delete m_module;
}
