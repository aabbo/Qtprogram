#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "yutcontroller.h"


/**
 * main view, call setupdialog and resultdialog
 * @brief MainWindow::MainWindow
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent,YutController* ctrl) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->yctrl=ctrl;

    //setup dialog execute
    setupDig = new SetupDialog(nullptr,this->yctrl);
    setupDig->exec();

    //send value of mal and team

    //yutPan set
    board = new MainBoard();
    ui->MainBoardFrame->setLayout(board->grid);
}

bool MainWindow::setup_bool(){
    return setupDig->startbool;
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
void MainWindow::resizeEvent(QResizeEvent *event){

}
*/
