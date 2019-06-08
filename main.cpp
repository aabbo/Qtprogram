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
    while(1){
        int tmp = a.exec();
        if(tmp == 0){
            if(yctrl->isRestart){
                //delete yctrl;
                yctrl = new YutController();
                if(yctrl->gamestart == false){
                    a.quit();
                    return 0;
                }
            }
            else{
                break;
            }
        }
    }
    return 0;
}
