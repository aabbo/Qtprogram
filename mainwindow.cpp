#include "mainwindow.h"
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

    //yutPan set
    //board = new MainBoard(ymodel->buttonList,this);
    board = new MainBoard(this->ymodel,this->yctrl,this);
    ui->MainBoardFrame->setLayout(board->grid);

    // button set
    this->ui->SelectButtonStack->setCurrentIndex(0);

    //team set
    teams=new MainTeams(this->ymodel,this->yctrl,this);
    ui->InfoFrame->setLayout(teams->grid);

}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief MainWindow::clicked
 * @param btn
 * 윷판 위의 버튼 클릭시 이벤트
 */
void MainWindow::clicked(QPushButton *btn){
    qDebug() <<"test==" <<btn->objectName();
    this->yctrl->clickedBoardBtn(btn);
}

/**
 * @brief MainWindow::on_RandomButton_clicked
 * 랜덤 윷 던지기
 */
void MainWindow::on_RandomButton_clicked()
{
    qDebug()<<"test==random btn clicked";
    this->yctrl->clicked_YutRandom();
}

/**
 * @brief MainWindow::on_SelectButton_clicked
 * 윷던지기 버튼 화면 전환
 */
void MainWindow::on_SelectButton_clicked()
{   //012345
    qDebug()<<"test==select btn clicked";
    this->ui->SelectButtonStack->setCurrentIndex(1);
}

/**
 * @brief MainWindow::on_SelectThrow_clicked
 * 선택한 윷을 던진것으로 설정. Queue에 저장
 */
void MainWindow::on_SelectThrow_clicked()
{
    this->yctrl->clicked_YutSelect(this->yut);
}

void MainWindow::on_BackPage_clicked()
{
    this->ui->SelectButtonStack->setCurrentIndex(0);
}


/**
 * @brief MainWindow::afterClickYut------구현 덜함!!!
 * @param status
 * true : yut result = 0,1,2,3
 * false : yut result = 4,5
 */
void MainWindow::afterClickYut(bool status){
    int yut=ymodel->getLastYutInfo();
    //show yut img
    setYutImg(yut);
    //show yut result list
    setYutResult(ymodel->getCurrentYutQueue());

    if(status){
        //yut button setdisable
        //move mal -> update mal which can moved
        // yut model currentTeam update
        this->disableButton(this->ui->SelectButtonStack->currentIndex());

        // 말 놓기 이벤트 수행
        this->yctrl->setMal();

        this->yctrl->endTurn();
        this->enableButton(this->ui->SelectButtonStack->currentIndex());
    }
}

void MainWindow::disableButton(int index){
    if(index == 0){
        ui->RandomButton->setDisabled(true);
        ui->SelectButton->setDisabled(true);
    }
    else if(index == 1){
        ui->SelectThrow->setDisabled(true);
        ui->BackPage->setDisabled(true);
    }
    this->update();
}

void MainWindow::enableButton(int index){
    if(index == 0){
        ui->RandomButton->setEnabled(true);
        ui->SelectButton->setEnabled(true);
    }
    else if(index == 1){
        ui->SelectThrow->setEnabled(true);
        ui->BackPage->setEnabled(true);
    }
    this->update();
}

void MainWindow::clearYutResult(){
    this->setYutImg();
    this->setYutResult(ymodel->getCurrentYutQueue());
}

/**
 * @brief MainWindow::setYutImg ----파일경로!해결해야함
 * @param yut
 * @return
 */

bool MainWindow::setYutImg(int yut){
    bool status=true;
    if(yut == -2){
        this->ui->YutImage->clear();
        return status;
    }
    QString filepath=":/img/yut_"+QString::number(yut)+".png";
    QPixmap  mypix = QPixmap(filepath);
    int size=ui->YutImage->width();
    if(size>ui->YutImage->height())
        size=ui->YutImage->height();
    mypix = mypix.scaled(size,size , Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->YutImage->setPixmap(mypix);
    //delete mypix;

    return status;
}

bool MainWindow::setYutResult(QQueue<int> result){
    bool status=true;
    QString str="윷 결과리스트:";
    while(result.size()>0){
        int yut=result.front();
        result.dequeue();
        if(yut==0){
            str=str+" ->빽도";
        }else if(yut==1){
            str=str+" ->도";
        }else if(yut==2){
            str=str+" ->개";
        }else if(yut==3){
            str=str+" ->걸";
        }else if(yut==4){
            str=str+" ->윷";
        }else if(yut==5){
            str=str+" ->모";
        }
    }
    ui->ResultLabel->setText(str);
    return status;
}

void MainWindow::clickedBeforeMal(){
    qDebug()<<"test==clicked!!";
    //connect(this,SIGNAL(sendtoCtrl()),this->yctrl,SLOT());
}

void MainWindow::on_BackDo_clicked()
{
    this->yut = 0;
}

void MainWindow::on_Do_clicked()
{
    this->yut = 1;
}

void MainWindow::on_Gae_clicked()
{
    this->yut = 2;
}

void MainWindow::on_Gul_clicked()
{
    this->yut = 3;
}

void MainWindow::on_Yut_clicked()
{
    this->yut = 4;
}

void MainWindow::on_Mo_clicked()
{
    this->yut = 5;
}
