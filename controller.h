#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QApplication>
#include "mainwindow.h"

class Controller
{
public:
    Controller();
    bool gamestart;

private:
    MainWindow * mw;
};

#endif // CONTROLLER_H
