#include "yutcontroller.h"
#include <QtDebug>

YutController::YutController(QObject *parent) : QObject(parent)
{
    //Model
    ymodel = new YutModel();

    //View
    //setup dialog
    sd = new SetupDialog(nullptr,this);
    sd->exec();
    gamestart = sd->GetStartBool();

    //mainwindow
    mw = new MainWindow(nullptr,ymodel,this);
    if(gamestart==true)
        mw->show();

    //result dialog
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

void YutController::clicked_YutRandom(){
    qDebug() << "test==clicked_YutRandom()==";
    bool status=ymodel->set_clickedYut(-1);
    mw->afterClickYut(status);
}

void YutController::clicked_YutSelect(int yut){
    qDebug() << "test==clicked_Yutselect()=="<<yut;
    bool status=ymodel->set_clickedYut(yut);
    mw->afterClickYut(status);
}
