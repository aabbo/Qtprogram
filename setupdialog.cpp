#include "setupdialog.h"
#include "yutcontroller.h"
#include <QDebug>


SetupDialog::SetupDialog(QWidget *parent,YutController* ctrl) :
    QDialog(parent),
    ui(new Ui::SetupDialog)
{
    this->yctrl=ctrl;

    ui->setupUi(this);
    startbool = true;

    //reset player labels
    ui->player_label->setText("Player");
    ui->player_slider->setRange(2,4);
    ui->player_num_label->setNum(2);

    //reset mal labels
    ui->mal_label->setText("Mal");
    ui->mal_slider->setRange(2,5);
    ui->mal_num_label->setNum(2);

    //reset button
    ui->start_button->setText("Start");
    ui->cancel_button->setText("Cancel");
}

SetupDialog::~SetupDialog()
{
    delete ui;
}

bool SetupDialog::GetStartBool(){
    return startbool;
}

void SetupDialog::on_player_slider_valueChanged(int value)
{
    ui->player_num_label->setNum(value);
    this->totalTeamNum = value;
}

void SetupDialog::on_mal_slider_valueChanged(int value)
{
    ui->mal_num_label->setNum(value);
    this->totalMalNum = value;
}

void SetupDialog::on_start_button_clicked()
{
    this->startBtnClicked = true;
    this->close();
}

void SetupDialog::on_cancel_button_clicked()
{
    this->startBtnClicked = false;
    startbool = false;
    this->close();
}

void SetupDialog::on_SetupDialog_rejected()
{
    this->startbool = false;
    if(startBtnClicked)
        this->startbool = true;
    this->close();


}
