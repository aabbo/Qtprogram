#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //setup dialog execute
    setupDig = new SetupDialog();
    setupDig->exec();

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
