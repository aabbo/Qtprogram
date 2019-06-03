#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "yutcontroller.h"
#include "selectyutdialog.h"
#include <QImage>
#include <QPixmap>
#include <QLabel>



/**
 * main view, call setupdialog and resultdialog
 * @brief MainWindow::MainWindow
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent,YutModel* model,YutController* ctrl) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ymodel=model;
    this->yctrl=ctrl;

    //setup dialog execute
    setupDig = new SetupDialog(nullptr,this->yctrl);
    setupDig->exec();

    //yutPan set
    //board = new MainBoard(ymodel->buttonList,this);
    board = new MainBoard(this->ymodel,this->yctrl,this);
    ui->MainBoardFrame->setLayout(board->grid);

    //team set
    teams=new MainTeams(this->ymodel,this->yctrl,this);
    ui->InfoFrame->setLayout(teams->grid);

}

bool MainWindow::setup_bool(){
    return setupDig->startbool;
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::clicked(QPushButton *btn){
    qDebug() <<"test==" <<btn->objectName();
    this->yctrl->clickedBoardBtn(btn);
}
/*
void MainWindow::resizeEvent(QResizeEvent *event){

}
*/

void MainWindow::on_RandomButton_clicked()
{
    qDebug()<<"test==random btn clicked";
    this->yctrl->clicked_YutRandom();
}

void MainWindow::on_SelectButton_clicked()
{   //012345
    qDebug()<<"test==select btn clicked";

    SelectYutDialog selecDialog;
    selecDialog.setModal(true);
    selecDialog.exec();
    if(selecDialog.status){
        int yut=selecDialog.yut;
        this->yctrl->clicked_YutSelect(yut);
    }
}

/**
 * @brief MainWindow::afterClickYut------구현 덜함!!!
 * @param status
 * true : yut result = 0,1,2,3
 * false : yut result = 4,5
 */
void MainWindow::afterClickYut(bool status){
    int yut=ymodel->yutResults.back();
    //show yut img
    setYutImg(yut);
    //show yut result list
    setYutResult(ymodel->yutResults);

    if(status){
        //yut button setdisable
        //move mal -> update mal which can moved
    }else{
        //one more time
    }
}

/**
 * @brief MainWindow::setYutImg ----파일경로!해결해야함
 * @param yut
 * @return
 */
bool MainWindow::setYutImg(int yut){
    bool status=true;

    QString filepath=":/img/yut_"+QString::number(yut)+".png";
    QPixmap  mypix = QPixmap(filepath);
    int size=ui->YutImage->width();
    if(size>ui->YutImage->height())
        size=ui->YutImage->height();
    mypix = mypix.scaled(size,size , Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->YutImage->setPixmap(mypix);
    //delete mypix;

    return status;
}
bool MainWindow::setYutResult(QQueue<int> result){
    result.push_back(2);
    bool status=true;
    QString str="윷 결과리스트:";
    while(result.size()>0){
        int yut=result.front();
        result.pop_front();
        if(yut==0){
            str=str+" ->빽도";
        }else if(yut==1){
            str=str+" ->도";
        }else if(yut==2){
            str=str+" ->개";
        }else if(yut==3){
            str=str+" ->걸";
        }else if(yut==4){
            str=str+" ->윷";
        }else if(yut==5){
            str=str+" ->모";
        }
    }
    ui->ResultLabel->setText(str);
    return status;
}



void MainWindow::clickedBeforeMal(){


    qDebug()<<"test==clicked!!";
    //connect(this,SIGNAL(sendtoCtrl()),this->yctrl,SLOT());

}
