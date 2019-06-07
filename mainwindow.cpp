#include "mainwindow.h"
#include "yutcontroller.h"
#include <QPair>

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
    board = new MainBoard(this);
    board->setButtonStyleSheetAll(this->ButtonStyle);
    ui->MainBoardFrame->setLayout(board->grid);

    // button set
    this->ui->SelectButtonStack->setCurrentIndex(0);

    //team set
    teams=new MainTeams(this->ymodel->numOfTeam, this->ymodel->numOfMal, this);
    this->malHighlightCanclation();
    teams->setLabelStyleSheet(1, this->HighlightStyle);
    ui->MalFrame->setLayout(teams->mal);
    ui->ResultFrame->setLayout(teams->result);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject *object, QEvent *event){
    if(event->type() == QMouseEvent::MouseButtonPress){
        int index = object->objectName().toInt();
        if(this->ymodel->getMainBoardButtonEnable(index)){
            this->yctrl->clickedBoardBtn(index);
        }
    }
    return QWidget::eventFilter(object, event);
}


void MainWindow::on_RandomButton_clicked()
{
    qDebug()<<"test==random btn clicked";
    this->yctrl->clickedYut();
}

void MainWindow::on_SelectButton_clicked()
{   //012345
    this->ui->SelectButtonStack->setCurrentIndex(1);
}

void MainWindow::on_SelectThrow_clicked()
{
    this->yctrl->clickedYut(this->yut);
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
        this->setButtonDisable(ui->SelectButtonStack->currentIndex());
        Sleep(1000);
        this->yctrl->setStart();
    }
}

int MainWindow::getStackedWidgetIndex(){
    return this->ui->SelectButtonStack->currentIndex();
}

void MainWindow::enableCurrentBoardButtonLocation(){
    // 이동 가능한 BoardButton을 하이라이팅
    // 해당 버튼 클릭기능 활성화
    QVector<int> location = this->ymodel->getCurrentClickableLocation();
    QVector<bool> isExist = this->ymodel->getMalExistVec();
    if(location.size() > 0){
        for(int i=0; i<location.size(); i++){
            //this->board->buttonList[location[i]]->setDisabled(false);
            this->ymodel->setMainBoardButtonEnable(location[i], true);
            if(isExist[i]){
                // 해당 위치에 있는 팀의 정보를 가져오도록 바꾸기
                QPair<int, int> tmpPair = this->ymodel->getSpecificLocationInfo(location[i]);
                if(!(tmpPair == QPair<int, int>())){
                    board->setButtonStyleSheet(location[i],tmpPair.first, tmpPair.second, this->ButtonBorderHighlight);
                }

                //board->boardUiUpdate(this->ymodel->getAllMalLocation(), this->ymodel->getCurrentTeamNum(), false);
            }
            else {
                this->board->setButtonStyleSheet(location[i], this->ButtonBorderHighlight);
            }
        }
    }
}

void MainWindow::setEnableMalButton(){
    // 사용자가 윷을 던지고 나서
    // 사용자가 선택할 수 있는 모든 말판을 Highlight시켜줌
    int yutNum = this->ymodel->getCurrentQueue().front();
    this->setYutImg(yutNum);
    this->setYutResult(this->ymodel->getCurrentQueue());

    if(!yutNum){
        this->teams->setButtonDisable(this->ymodel->getCurrentTeamNum(),
                                      this->ymodel->getCurrentTeamRemainMalNum());
    }
    // 남아있는 말들 하이라이트
    if(this->ymodel->getCurrentTeamRemainMalNum() && yutNum){
        this->teams->setButtonEnable(this->ymodel->getCurrentTeamNum(),
                                     this->ymodel->getCurrentTeamRemainMalNum());
        this->teams->setButtonStyle(this->ButtonBorderHighlight, this->ymodel->getCurrentTeamNum(),
                                    this->ymodel->getCurrentTeamRemainMalNum());
    }
    // 현재 메인 보드에 올라가있는 말 하이라이트
    QVector<QPair<int, int>> tmp = this->ymodel->getCurrentMalLocation();
    if(tmp.size() > 0){
        for(int i=0; i<tmp.size(); i++){
            //this->board->buttonList[tmp[i]]->setDisabled(false);
            this->ymodel->setMainBoardButtonEnable(tmp[i].first, true); // 클릭 가능하게
            // 하이라이트 코드 추가
            this->board->setButtonStyleSheet(tmp[i].first, this->ymodel->getCurrentTeamNum(),
                                             tmp[i].second, this->ButtonBorderHighlight);
        }
    }
}

void MainWindow::endTurn(bool status){
    this->malHighlightCanclation();
    this->setButtonEnable(ui->SelectButtonStack->currentIndex());
    if(status == false){
        this->clearYutFrame();
        this->teams->setLabelStyleSheet(this->ymodel->getCurrentTeamNum(), this->HighlightStyle);
    }
    else if(status == true){
        if(!this->ymodel->getCurrentQueue().isEmpty()){
            this->setYutImg(this->ymodel->getCurrentQueue().back());
            this->setYutResult(this->ymodel->getCurrentQueue());
        }
        this->setButtonEnable(ui->SelectButtonStack->currentIndex());
    }
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

void MainWindow::setMainBoardUpdate(){
    // 모든 사용자가 말 한개를 특정 위치에 놔두고 난 뒤
    // 1. 보드에 존재한 말을 선택했을 경우
    // 하이라이트를 해줄 필요가 없음!
    //this->board->setButtonStyleSheet(clickedBtnNum, teamNum, malNum, this->ButtonStyle);
    board->boardUiUpdate(this->ymodel->getAllMalLocation(), this->ymodel->getCurrentTeamNum(), false);
    this->yctrl->boardSet=true;
}

/**
 * @brief MainWindow::setYutImg ----파일경로!해결해야함
 * @param yut
 * @return
 */

bool MainWindow::setYutImg(int yut){
    bool status=true;

    QString filepath=":/img/yut_"+QString::number(yut)+".png";
    QPixmap mypix = QPixmap(filepath);
    int size=ui->YutImage->width();
    if(size>ui->YutImage->height())
        size=ui->YutImage->height();
    mypix = mypix.scaled(size,size , Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->YutImage->setPixmap(mypix);

    this->repaint();

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
    this->repaint();

    return status;
}

void MainWindow::MalClicked(){
    this->yctrl->clickedRemainedMal();
}

void MainWindow::malHighlightCanclation(){
    this->teams->setButtonDisable(this->ymodel->getCurrentTeamNum(),
                                  this->ymodel->getCurrentTeamRemainMalNum());
    this->teams->setButtonStyleSheetAll(this->ButtonStyle, this->ymodel->numOfTeam,
                                        this->ymodel->getAllRemainMalNum(), this->ymodel->getAllOuttedMalNum());
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
