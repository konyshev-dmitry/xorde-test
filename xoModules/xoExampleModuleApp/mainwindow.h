#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include "ModuleBaseAppONB.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    ModuleBaseAppONB *m_module = nullptr;

public:
    MainWindow(QString ip = "127.0.0.1", QString port = "8080", QWidget *parent = nullptr);
    ~MainWindow();
};

#endif // MAINWINDOW_H
