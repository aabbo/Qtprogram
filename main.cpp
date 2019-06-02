#include "yutcontroller.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    YutController * yctrl=new YutController();
    if(yctrl->gamestart==false){
        a.quit();
        return 0;
    }
    return a.exec();
}
