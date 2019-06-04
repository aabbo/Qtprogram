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
    this->buttonList = this->ymodel->getButtonList();
    setBoard();

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
