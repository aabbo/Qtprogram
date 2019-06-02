#include "boardbutton.h"

BoardButton::BoardButton(QWidget *parent) : QPushButton(parent)
{
    connect(this, SIGNAL(clicked()), this, SLOT(click()));

    mals=0;
    team=-1;
}
void BoardButton::click(){
    emit clicked(this);
}
