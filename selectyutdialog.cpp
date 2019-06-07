#include "selectyutdialog.h"
#include "ui_selectyutdialog.h"
#include <QDebug>
#include <QButtonGroup>
#include <QGridLayout>
#include <QGroupBox>

SelectYutDialog::SelectYutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectYutDialog)
{
    yut=0;
    status=false;
    ui->setupUi(this);


    /*
    QGroupBox * groupBox=new QGroupBox("yut game");
    QRadioButton* radio0=new QRadioButton("BB do");
    QRadioButton* radio1=new QRadioButton("Do");
    QRadioButton* radio2=new QRadioButton("Gae");
    QRadioButton* radio3=new QRadioButton("Gul");
    QRadioButton* radio4=new QRadioButton("Yut");
    QRadioButton* radio5=new QRadioButton("Mo");
    radio0->setChecked(true);

    QVBoxLayout* vbox=new QVBoxLayout;
    vbox->addWidget(radio0);
    vbox->addWidget(radio1);
    vbox->addWidget(radio2);
    vbox->addWidget(radio3);
    vbox->addWidget(radio4);
    vbox->addWidget(radio5);

    vbox->addStretch(1);
    groupBox->setLayout(vbox);


    QGridLayout *grid=new QGridLayout;
    grid->addWidget(groupBox, 0, 0);
    setLayout(grid);
    */

}

SelectYutDialog::~SelectYutDialog()
{
    delete ui;
}

void SelectYutDialog::on_buttonBox_accepted()
{
    qDebug()<<"test==on_buttonBox_accepted()==";
    this->status=true;
}

void SelectYutDialog::on_buttonBox_rejected()
{
    qDebug()<<"test==on_buttonBox_rejected()==";
    this->status=false;
}

void SelectYutDialog::on_radio0_BB_do_clicked()
{
    this->yut=0;
}

void SelectYutDialog::on_radio1_do_clicked()
{
    this->yut=1;
}

void SelectYutDialog::on_radio2_gae_clicked()
{
    this->yut=2;
}

void SelectYutDialog::on_radio3_gul_clicked()
{
    this->yut=3;
}

void SelectYutDialog::on_radio4_yut_clicked()
{
    this->yut=4;
}

void SelectYutDialog::on_radio5_mo_clicked()
{
    this->yut=5;
}
