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
    board = new MainBoard(this);
    board->setButtonStyleSheetAll(this->ButtonStyle);
    ui->MainBoardFrame->setLayout(board->grid);

    // button set
    this->ui->SelectButtonStack->setCurrentIndex(0);

    //team set
    teams=new MainTeams(this->ymodel->numOfTeam, this);
    teams->setButtonStyleSheetAll(this->ButtonStyle, this->ymodel->numOfTeam, this->ymodel->numOfMal
                                  ,this->ymodel->remainMalNum, this->ymodel->outtedMalNum);
    teams->setLabelStyleSheet(1, this->HighlightStyle);
    ui->InfoFrame->setLayout(teams->grid);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject *object, QEvent *event){
    if(event->type() == QMouseEvent::MouseButtonPress){
        this->yctrl->clickedBoardBtn(object->objectName().toInt());
    }
    return QWidget::eventFilter(object, event);
}


void MainWindow::on_RandomButton_clicked()
{
    qDebug()<<"test==random btn clicked";
    this->yctrl->clicked_YutRandom();
}

void MainWindow::on_SelectButton_clicked()
{   //012345
    qDebug()<<"test==select btn clicked";
    this->ui->SelectButtonStack->setCurrentIndex(1);
}

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
    QQueue<int> resultQueue = this->ymodel->getCurrentQueue();
    int yut= resultQueue.back();
    //show yut img
    setYutImg(yut);
    //show yut result list
    setYutResult(resultQueue);

    if(status){
        //yut button setdisable
        //move mal -> update mal which can moved
        this->setButtonDisable(ui->SelectButtonStack->currentIndex());

        // 사용자가 움직일 수 있는 말 click 가능하게 하기
        this->enableCurrentBoardButtonLocation();
        // 사용자가 움직일 말 선택

        // 사용자가 말을 옮길 수 있는 버튼 활성화

        this->setButtonEnable(ui->SelectButtonStack->currentIndex());
    }
}

void MainWindow::enableCurrentBoardButtonLocation(){
    QVector<int> malLocation = this->ymodel->getCurrentMalLocation();
    for(auto itr = malLocation.begin(); itr != malLocation.end(); ++itr){
        //this->board->setButtonStyleSheet()
        this->board->buttonList[*itr]->setDisabled(false);
    }
}

void MainWindow::setClickableBoardButton(){
    // 사용자가 선택 가능한 BoardButton을 하이라이팅 하고
    // 해당 버튼을 클릭 가능하게 만듦
    QVector<int> locationList = this->ymodel->getCurrentClickableLocation();
    for(auto itr = locationList.begin(); itr != locationList.end(); ++itr){
        this->board->setButtonStyleSheet(*itr, this->HighlightStyle);
        this->board->buttonList[*itr]->setDisabled(false);
    }
}

void MainWindow::endTurn(){
    this->clearYutFrame();
}

void MainWindow::clearYutFrame(){
    ui->YutImage->clear();
    this->setYutResult(QQueue<int>());
}

void MainWindow::setButtonDisable(int index){
    if(index == 0){
        ui->RandomButton->setDisabled(true);
        ui->SelectButton->setDisabled(true);
    }
    else if(index == 1){
        ui->SelectThrow->setDisabled(true);
        ui->BackPage->setDisabled(true);
    }
}

void MainWindow::setButtonEnable(int index){
    if(index == 0){
        ui->RandomButton->setDisabled(false);
        ui->SelectButton->setDisabled(false);
    }
    else if(index == 1){
        ui->SelectThrow->setDisabled(false);
        ui->BackPage->setDisabled(false);
    }
}

/**
 * @brief MainWindow::setYutImg ----파일경로!해결해야함
 * @param yut
 * @return
 */

bool MainWindow::setYutImg(int yut){
    bool status=true;

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
