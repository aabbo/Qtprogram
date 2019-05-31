#include "controller.h"

Controller::Controller()
{
    mw = new MainWindow();
    gamestart = mw->setup_bool();
    if(gamestart==true)
        mw->show();
}
