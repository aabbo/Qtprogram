#include "resultdialog.h"
#include "yutcontroller.h"
#include "ui_resultdialog.h"

ResultDialog::ResultDialog(int winningTeam, YutController* yctrl, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ResultDialog)
{
    ui->setupUi(this);
    this->winningTeam = winningTeam;
    this->yctrl = yctrl;

    this->ui->winner_player_label->setText("팀" + QString::number(this->winningTeam));
}

ResultDialog::~ResultDialog()
{
    delete ui;
}

void ResultDialog::on_end_button_clicked()
{
    this->yctrl->mw->close();
    this->restartBtnClicked = false;
    //delete this->yctrl->mw;
    this->close();
}

void ResultDialog::on_restart_button_clicked()
{
    this->restartBtnClicked = true;
    this->yctrl->isRestart = true;
    this->yctrl->mw->close();
    this->close();
}

void ResultDialog::on_ResultDialog_rejected(){
    this->yctrl->isRestart = false;
    if(this->restartBtnClicked)
        this->yctrl->isRestart = true;
    this->yctrl->mw->close();
    this->close();
}
