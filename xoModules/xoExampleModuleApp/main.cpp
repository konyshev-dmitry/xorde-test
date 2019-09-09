#include "mainwindow.h"
#include "xoExampleModuleApp.h"
#include "xoWindow.h"
#include <QApplication>
#include <QCommandLineOption>
#include <QCommandLineParser>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    xoWindow w(new xoExampleModuleApp);
    w.show();

    return a.exec();
}
