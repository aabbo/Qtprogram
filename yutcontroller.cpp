#include "yutcontroller.h"
#include <QtDebug>

YutController::YutController(QObject *parent) : QObject(parent)
{
    //View
    //setup dialog
    sd = new SetupDialog();
    sd->exec();
    gamestart = sd->GetStartBool();

    //Model
    ymodel = new YutModel(sd->numOfTeam, sd->numOfMal);

    //mainwindow
    mw = new MainWindow(nullptr,ymodel,this);
    if(gamestart==true){

        mw->show();
    }

    //result dialog
}

void YutController::clickedBoardBtn(QPushButton* btn){
    qDebug() << "test==ctrl=="<<btn->objectName();
    int index = btn->objectName().toInt();
    this->ymodel->updateBoardBtnInfo(index);
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
/**
 * @brief YutController::setMal
 * 1. 클릭 가능한 Button을 업데이트
 * 2. 사용자가 클릭한 Button으로 말을 이동
 * 3. Queue가 비었으면 종료
 */
void YutController::setMal(){
    while(!this->ymodel->isQueueEmpty()){
        int yut = this->ymodel->getYut();
        this->ymodel->setButtonEnable(yut);

    }
}

void YutController::endTurn(){
    this->ymodel->updateCurrentTeamInfo();
    mw->clearYutResult();
}
