#include "mainboard.h"
#include <QLabel>
//vector<BoardButton*> btnList,QWidget *parent
MainBoard::MainBoard(YutModel* model, YutController* ctrl,QWidget *parent) : QWidget(parent)
{

    this->ymodel=model;
    this->yctrl=ctrl;

    this->parent=parent;
    grid = new QGridLayout();
    //this->buttonList=btnList;
    this->buttonList=this->ymodel->buttonList;
    setBoard();
    /*
    grid = new QGridLayout();
    int row = 10;
    int col = 10;
    for(int i=0; i<29; i++){
        BoardButton* btn = new BoardButton();
        btn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        btn->setMinimumSize(50,50);
        btn->setMaximumSize(50,50);
        btn->setText(QString::number(i));
        //btn->setObjectName(QString::number(i));
        QString style = "border-color:rgb(0,0,0); border-width:1.2px; border-style:solid;"
                        "border-radius:25px;";
        btn->setStyleSheet(style);
        grid->addWidget(btn, row, col);
        if(i<5){
            row -= 2;
        }else if(i<10){
            col -=2;
        }
        else if(i<15){
            row +=2 ;
        }
        else if(i<19){
            col +=2;
        }else if(i==19){
            row -= 2;
        }
        else if(i==20){
            row -=6;
        }
        else if(i==21){
            col-=6;
        }
        else if(i==22){
            row+=6;
        }
        else if(i ==23){
            row -=2;
            col +=4;
        }
        else if(i==24){
            row -=2;
        }
        else if(i == 25){
            col -=2;
        }
        else if(i==26){
            row +=2;
        }
        else if(i==27){
            row -=1;
            col +=1;
        }
        this->buttonList.push_back(btn);
    }
    BoardButton* btn = new BoardButton();
    btn->setObjectName("end");
    this->buttonList.push_back(btn);

    QLabel* label[10];
    row = 9;
    col = 10;
    for(int i=0; i<10; i++){
        label[i] = new QLabel();
        grid->addWidget(label[i], row, col);
        if(i<4){
            row -=2;
        }
        else if(i==4){
            row -=1;
            col -=1;
        }
        else if(i<9){
            col -=2;
        }
    }*/
/*
    for(int i=0; i<20; i++){
        BoardButton* tmpBtn = this->buttonList[i];
        if(i < 19){
            if(i == 0){
                tmpBtn->nextStep.push_back(this->buttonList[29]);
                tmpBtn->prevStep.push_back(this->buttonList[19]);
            }
            else if(i==5){
                tmpBtn->nextStep.push_back(this->buttonList[21]);
                tmpBtn->prevStep.push_back(this->buttonList[4]);
            }
            else if(i==10){
                tmpBtn->nextStep.push_back(this->buttonList[22]);
                tmpBtn->prevStep.push_back(this->buttonList[9]);
            }else {
                tmpBtn->nextStep.push_back(this->buttonList[i+1]);
                tmpBtn->prevStep.push_back(this->buttonList[i-1]);
            }
        }else if(i==19){
            tmpBtn->nextStep.push_back(this->buttonList[0]);
        }
    }
    this->buttonList[20]->nextStep.push_back(this->buttonList[0]);
    this->buttonList[20]->prevStep.push_back(this->buttonList[24]);

    this->buttonList[21]->nextStep.push_back(this->buttonList[25]);
    this->buttonList[21]->prevStep.push_back(this->buttonList[5]);

    this->buttonList[22]->nextStep.push_back(this->buttonList[26]);
    this->buttonList[22]->prevStep.push_back(this->buttonList[10]);

    this->buttonList[23]->nextStep.push_back(this->buttonList[15]);
    this->buttonList[23]->prevStep.push_back(this->buttonList[27]);

    this->buttonList[24]->nextStep.push_back(this->buttonList[20]);
    this->buttonList[24]->prevStep.push_back(this->buttonList[28]);

    this->buttonList[25]->nextStep.push_back(this->buttonList[28]);
    this->buttonList[25]->prevStep.push_back(this->buttonList[21]);

    this->buttonList[26]->nextStep.push_back(this->buttonList[28]);
    this->buttonList[26]->prevStep.push_back(this->buttonList[22]);

    this->buttonList[27]->nextStep.push_back(this->buttonList[23]);
    this->buttonList[27]->prevStep.push_back(this->buttonList[28]);

    this->buttonList[28]->nextStep.push_back(this->buttonList[24]);
    this->buttonList[28]->nextStep.push_back(this->buttonList[27]);
    this->buttonList[28]->prevStep.push_back(this->buttonList[25]);
    this->buttonList[28]->prevStep.push_back(this->buttonList[26]);

    this->buttonList[29]->nextStep.push_back(this->buttonList[0]);
*/
}

void MainBoard::setBoard(){
    int row = 10;
    int col = 10;
    for(int i=0;i<29;i++){
        this->buttonList.at(i)->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        this->buttonList.at(i)->setMinimumSize(50,50);
        this->buttonList.at(i)->setMaximumSize(50,50);
        this->buttonList.at(i)->setText(QString::number(i));
        //btn->setObjectName(QString::number(i));
        QString style = "border-color:rgb(0,0,0); border-width:1.2px; border-style:solid;"
                        "border-radius:25px;";
        this->buttonList.at(i)->setStyleSheet(style);
        grid->addWidget(this->buttonList.at(i), row, col);

        connect(this->buttonList.at(i), SIGNAL(clicked(QPushButton*)), parent, SLOT(clicked(QPushButton*)));

        if(i<5){
            row -= 2;
        }else if(i<10){
            col -=2;
        }
        else if(i<15){
            row +=2 ;
        }
        else if(i<19){
            col +=2;
        }else if(i==19){
            row -= 2;
        }
        else if(i==20){
            row -=6;
        }
        else if(i==21){
            col-=6;
        }
        else if(i==22){
            row+=6;
        }
        else if(i ==23){
            row -=2;
            col +=4;
        }
        else if(i==24){
            row -=2;
        }
        else if(i == 25){
            col -=2;
        }
        else if(i==26){
            row +=2;
        }
        else if(i==27){
            row -=1;
            col +=1;
        }
    }

    QLabel* label[10];
    row = 9;
    col = 10;
    for(int i=0; i<10; i++){
        label[i] = new QLabel();
        grid->addWidget(label[i], row, col);
        if(i<4){
            row -=2;
        }
        else if(i==4){
            row -=1;
            col -=1;
        }
        else if(i<9){
            col -=2;
        }
    }





}
