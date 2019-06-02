#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "yutcontroller.h"


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
}

bool MainWindow::setup_bool(){
    return setupDig->startbool;
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::clicked(QPushButton *btn){
    qDebug() << btn->objectName();
}
/*
void MainWindow::resizeEvent(QResizeEvent *event){

}
*/
