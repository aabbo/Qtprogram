#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "yutcontroller.h"
#include "selectyutdialog.h"


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
 * @brief MainWindow::afterClickYut
 * @param status
 * true : yut result = 0,1,2,3
 * false : yut result = 4,5
 */
void MainWindow::afterClickYut(bool status){
    //show yut img
    //show yut result list

    if(status){
        //yut button setdisable
        //move mal -> update mal which can moved
    }else{
        //one more time
    }
}
