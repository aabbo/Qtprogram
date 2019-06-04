#include "yutcontroller.h"
#include <QtDebug>

YutController::YutController(QObject *parent) : QObject(parent)
{
    //View
    //setup dialog
    sd = new SetupDialog(nullptr,this);
    sd->exec();
    gamestart = sd->GetStartBool();

    //Model
    ymodel = new YutModel(sd->totalTeamNum, sd->totalMalNum);

    //mainwindow
    mw = new MainWindow(nullptr,ymodel,this);
    if(gamestart==true){

        mw->show();
    }

    //result dialog
}

void YutController::clickedBoardBtn(int num){
    qDebug() << "test==ctrl=="<< QString::number(num);
    this->ymodel->clickedButtonNum = num;
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
