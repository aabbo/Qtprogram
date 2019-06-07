#ifndef RESULTDIALOG_H
#define RESULTDIALOG_H

#include <QDialog>

class YutController;

namespace Ui {
class ResultDialog;
}

class ResultDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ResultDialog(QWidget *parent = nullptr);
    ~ResultDialog();

private:
    Ui::ResultDialog *ui;
};

#endif // RESULTDIALOG_H
