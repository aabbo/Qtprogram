#include "yutcontroller.h"

#include <QtDebug>
YutController::YutController(QObject *parent) : QObject(parent)
{
    //model
    ymodel=new YutModel();

    //view
    mw = new MainWindow(nullptr,ymodel,this);
    gamestart = mw->setup_bool();
    if(gamestart==true)
        mw->show();

}
void YutController::setValueOfMals(int val){
    qDebug()<<"test==contrl=mal="<<val;
    ymodel->setValueOfMals(val);
}
void YutController::setValueOfTeams(int val){
    qDebug()<<"test==contrl=team="<<val;
    ymodel->setValueOfTeams(val);
}


void YutController::clickedBoardBtn(QPushButton* btn){
    qDebug() << "test==ctrl=="<<btn->objectName();
}


