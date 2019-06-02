#include "setupdialog.h"
#include "ui_setupdialog.h"
#include <QDebug>
#include "yutcontroller.h"

SetupDialog::SetupDialog(QWidget *parent,YutController* ctrl) :
    QDialog(parent),
    ui(new Ui::SetupDialog)
{
    this->yctrl=ctrl;
    connect(this,SIGNAL(setValueOfMals(int)),this->yctrl,SLOT(setValueOfMals(int)));
    connect(this,SIGNAL(setValueOfTeams(int)),this->yctrl,SLOT(setValueOfTeams(int)));

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

void SetupDialog::on_player_slider_valueChanged(int value)
{
    ui->player_num_label->setNum(value);
    emit setValueOfTeams(value);

}

void SetupDialog::on_mal_slider_valueChanged(int value)
{
    ui->mal_num_label->setNum(value);
    emit setValueOfMals(value);
}

void SetupDialog::on_start_button_clicked()
{
    playerNum = ui->player_num_label->text().toInt();
    malNum = ui->mal_num_label->text().toInt();
    this->close();
}

void SetupDialog::on_cancel_button_clicked()
{
    startbool = false;
    this->close();
}

