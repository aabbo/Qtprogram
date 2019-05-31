#include "controller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Controller * controller = new Controller();
    if(controller->gamestart==false){
        a.quit();
        return 0;
    }
    return a.exec();
}
