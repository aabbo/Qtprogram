#include "boardbutton.h"

BoardButton::BoardButton(QWidget *parent) : QPushButton(parent)
{
    connect(this, SIGNAL(clicked()), this, SLOT(click()));
}
void BoardButton::click(){
    emit clicked(this);
}
