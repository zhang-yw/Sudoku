#include "gameinterface.h"
#include "ui_gameinterface.h"

GameInterface::GameInterface(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameInterface)
{
    layout = new QVBoxLayout(this);
    layout_0 = new QHBoxLayout();
    layout_1 = new QHBoxLayout();
    layout_2 = new QHBoxLayout();
    layout_3 = new QHBoxLayout();
    layout_4 = new QHBoxLayout();
    puaseButton = new QPushButton(this);
    restartButton = new QPushButton(this);
    returnButton = new QPushButton(this);
    withdrawButton = new QPushButton(this);
    recoverButton = new QPushButton(this);
    deleteButton = new QPushButton(this);
    hintButton = new QPushButton(this);
    timer = new TimerDisplay(this);
    title = new QLabel(this);
    for(int i = 0;i < 9;i++)
    {
        keyBoard[i] = new QPushButton;
        keyBoard[i]->setText(QString::number(i+1,10));
        keyBoard[i]->setFixedSize(50,50);
        keyBoard[i]->setStyleSheet("QPushButton{color:rgb(83,83,83);background-color:rgb(178,153,142);border:1px solid rgb(225,224,231);border-radius:15px;font-size:20px;font-weight:bold;font-family:Microsoft Yahei;}"
                                   "QPushButton:pressed{color:rgb(178,153,142);background-color:rgb(83,83,83);}");
    }
    QPixmap *returnButtonPix = new QPixmap(":/new/icons/icons/return (1).png");
    returnButton->setAutoFillBackground(false);
    returnButton->setFlat(true);
    returnButton->setIcon(QIcon(*returnButtonPix));
    returnButton->setIconSize(QSize(30,30));
    returnButton->setToolTip(QStringLiteral("回到上一页"));
    QPixmap *pauseButtonPix = new QPixmap(":/new/icons/icons/pause.png");
    puaseButton->setAutoFillBackground(false);
    puaseButton->setFlat(true);
    puaseButton->setIcon(QIcon(*pauseButtonPix));
    puaseButton->setIconSize(QSize(30,30));
    puaseButton->setToolTip(QStringLiteral("暂停"));
    QPixmap *restartButtonPix = new QPixmap(":/new/icons/icons/restart .png");
    restartButton->setAutoFillBackground(false);
    restartButton->setFlat(true);
    restartButton->setIcon(QIcon(*restartButtonPix));
    restartButton->setIconSize(QSize(30,30));
    restartButton->setToolTip(QStringLiteral("重新开始"));
    layout_1->addWidget(returnButton);
    layout_1->addWidget(restartButton);
    layout_1->addWidget(puaseButton);
    layout_1->addWidget(timer);
    QPixmap *withdrawButtonPix = new QPixmap(":/new/icons/icons/return_1.png");
    withdrawButton->setAutoFillBackground(false);
    withdrawButton->setFlat(true);
    withdrawButton->setIcon(QIcon(*withdrawButtonPix));
    withdrawButton->setIconSize(QSize(38,30));
    withdrawButton->setToolTip(QStringLiteral("撤销一步"));
    withdrawButton->setFixedSize(38,30);
    QPixmap *recoverButtonPix = new QPixmap(":/new/icons/icons/return_2.png");
    recoverButton->setAutoFillBackground(false);
    recoverButton->setFlat(true);
    recoverButton->setIcon(QIcon(*recoverButtonPix));
    recoverButton->setIconSize(QSize(38,30));
    recoverButton->setToolTip(QStringLiteral("恢复一步"));
    recoverButton->setFixedSize(38,30);
    QPixmap *deleteButtonPix = new QPixmap(":/new/icons/icons/delete.png");
    deleteButton->setAutoFillBackground(false);
    deleteButton->setFlat(true);
    deleteButton->setIcon(QIcon(*deleteButtonPix));
    deleteButton->setToolTip(QStringLiteral("删除所选格内容"));
    deleteButton->setIconSize(QSize(30,30));
    deleteButton->setFixedSize(30,30);
    QPixmap *hintButtonPix = new QPixmap(":/new/icons/icons/hint.png");
    hintButton->setAutoFillBackground(false);
    hintButton->setFlat(true);
    hintButton->setIcon(QIcon(*hintButtonPix));
    hintButton->setToolTip(QStringLiteral("提示"));
    hintButton->setIconSize(QSize(30,30));
    hintButton->setFixedSize(30,30);
    layout_2->addWidget(withdrawButton);
    layout_2->addWidget(recoverButton);
    layout_2->addWidget(deleteButton);
    layout_2->addWidget(hintButton);
    withdrawButton->setEnabled(false);
    recoverButton->setEnabled(false);
}

void GameInterface::initialize(int level){
    if(!layout_3->count())
{
    grid = new Grid(level,this);
    switch (level) {
    case 1:
        title->setText(QStringLiteral("标准数独(简单难度)"));
        break;
    case 2:
        title->setText(QStringLiteral("标准数独(中等难度)"));
        break;
    case 3:
        title->setText(QStringLiteral("标准数独(困难难度)"));
        break;
    default:
        break;
    }
    QFont font_3;
    font_3.setFamily("YouYuan");
    font_3.setPointSize(30);
    title->setFont(font_3);
    title->setStyleSheet("color:rgb(224,156,34);border:1px solid rgb(224,156,34);border-radius:10px;");
    title->setAlignment(Qt::AlignCenter);
    layout_3->addWidget(grid);
    for(int i = 0;i < 9;i++)
    {
        layout_4->addWidget(keyBoard[i]);
    }
    layout_4->setSpacing(0);
    layout->addStretch(1);
    layout->addWidget(title);
    layout->addStretch(1);
    layout->addLayout(layout_1);
    layout->addLayout(layout_2);
    layout->addLayout(layout_3);
    layout->addLayout(layout_4);
    layout->setSpacing(0);
    this->setLayout(layout);
    timer->restart();
    succeedDialog = new QDialog(this);
    restartButtonAfterSuccess = new QPushButton(succeedDialog);
    layoutOfSuccess = new QVBoxLayout(succeedDialog);
    titleOfSuccess = new QLabel(succeedDialog);
    successTime = new QLabel(succeedDialog);
    QPixmap succeedIcon(":/new/icons/icons/succeed.png");
    titleOfSuccess->setPixmap(succeedIcon.scaled(100,100,Qt::KeepAspectRatio));
    QFont font_0;
    font_0.setFamily("站酷快乐体2016修订版");
    font_0.setPixelSize(50);
    font_0.setStyle(QFont::StyleNormal);
    successTime->setFont(font_0);
    successTime->setAlignment(Qt::AlignCenter);
    successTime->setStyleSheet("color:rgb(224,156,34)");
    successTime->adjustSize();
    restartButtonAfterSuccess->setText(QStringLiteral("再来一局"));
    restartButtonAfterSuccess->setStyleSheet("QPushButton{color:rgb(224,156,34);border-radius:15px;border:2px solid rgb(224,156,34);font-family:站酷快乐体2016修订版;font-size:30px;}"
                                             "QPushButton:pressed{background-color:gray;}");
    pauseDialog = new QDialog(this);
    QHBoxLayout *layoutDialog = new QHBoxLayout;
    restartButton_1 = new QPushButton(pauseDialog);
    QPixmap *continueButtonPix = new QPixmap(":/new/icons/icons/icon_continue.png");
    restartButton_1->setAutoFillBackground(false);
    restartButton_1->setFlat(true);
    restartButton_1->setIcon(QIcon(*continueButtonPix));
    restartButton_1->setToolTip(QStringLiteral("继续"));
    restartButton_1->setIconSize(QSize(60,60));
    restartButton_1->setStyleSheet("QPushButton{background-color:white;border-radius:15px;border:2px groove rgb(224,156,34);border-style: outset;}"
                                   "QPushButton:pressed{background-color:gray;border-style:inset;}");
    restartButton_1->setFixedSize(70,70);
    layoutDialog->addWidget(restartButton_1);
    pauseDialog->setLayout(layoutDialog);
    mapperInsert = new QSignalMapper(this);
    for(int i = 0;i < 9;i++)
    {
        connect(keyBoard[i],SIGNAL(clicked(bool)),mapperInsert,SLOT(map()));
        mapperInsert->setMapping(keyBoard[i],i+1);
    }
    connect(mapperInsert,SIGNAL(mapped(int)),this,SLOT(numInsert(int)));
    connect(returnButton,SIGNAL(clicked(bool)),this,SLOT(emitPreviousPage()));
    connect(restartButton,SIGNAL(clicked(bool)),timer,SLOT(restart()));
    connect(restartButton,SIGNAL(clicked(bool)),grid,SLOT(restart()));
    connect(puaseButton,SIGNAL(clicked(bool)),timer,SLOT(pause()));
    connect(puaseButton,SIGNAL(clicked(bool)),this,SLOT(showDialog()));
    connect(deleteButton,SIGNAL(clicked(bool)),grid,SLOT(deleteCellNum()));
    connect(restartButton_1,SIGNAL(clicked(bool)),pauseDialog,SLOT(hide()));
    connect(grid,SIGNAL(disableRedo(bool)),recoverButton,SLOT(setDisabled(bool)));
    connect(grid,SIGNAL(enableRedo(bool)),recoverButton,SLOT(setEnabled(bool)));
    connect(grid,SIGNAL(disableUndo(bool)),withdrawButton,SLOT(setDisabled(bool)));
    connect(grid,SIGNAL(enableUndo(bool)),withdrawButton,SLOT(setEnabled(bool)));
    connect(withdrawButton,SIGNAL(clicked(bool)),grid,SLOT(undo()));
    connect(recoverButton,SIGNAL(clicked(bool)),grid,SLOT(redo()));
    connect(grid,SIGNAL(succeed()),this,SLOT(succeed()));
    connect(hintButton,SIGNAL(clicked(bool)),grid,SLOT(hint()));
    connect(restartButtonAfterSuccess,SIGNAL(clicked(bool)),succeedDialog,SLOT(hide()));
    connect(restartButtonAfterSuccess,SIGNAL(clicked(bool)),this,SLOT(emitPreviousPage()));
    }
    else{
            grid->rewrite(level);
            timer->restart();
    }
}

void GameInterface::succeed()
{
    QTime *time_success = timer->getTime();
    QString ss_0 = time_success->toString("mm分ss秒");
    QString ss_1 = QStringLiteral("本次用时:");
    QString ss = ss_1 + ss_0;
    successTime->setText(ss);
    timer->pause();
    QHBoxLayout *layout_6 = new QHBoxLayout;
    layout_6->addStretch(1);
    layout_6->addWidget(titleOfSuccess);
    layout_6->addStretch(1);
    layoutOfSuccess->addLayout(layout_6);
    layoutOfSuccess->addWidget(successTime);
    layoutOfSuccess->addWidget(restartButtonAfterSuccess);
    succeedDialog->setLayout(layoutOfSuccess);
    succeedDialog->setModal(true);
    succeedDialog->exec();
}

void GameInterface::numInsert(int numInserted)
{
    grid->acceptInsert(numInserted);
}

void GameInterface::showDialog()
{
    pauseDialog->setModal(true);
    pauseDialog->exec();
    timer->continuing();
}

GameInterface::~GameInterface()
{
    delete ui;
}
