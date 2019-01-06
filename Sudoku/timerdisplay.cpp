#include "timerdisplay.h"
#include "ui_timerdisplay.h"
#include <QLCDNumber>
#include <QTimer>
#include <QTime>
#include <QtGui>
#include <QSizePolicy>

TimerDisplay::TimerDisplay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TimerDisplay)
{
    ui->setupUi(this);
    lcd = new QLCDNumber(this);
    lcd->setDigitCount(5);
    time = new QTime(0,0,0);
    lcd->display(time->toString("mm:ss"));
    QPalette *palette_0 = new QPalette;
    palette_0->setColor(QPalette::WindowText,QColor(224,156,34));
    lcd->setPalette(*palette_0);
    lcd->setSegmentStyle(QLCDNumber::Flat);
    timer = new QTimer;
    QPixmap clockIcon(":/new/icons/icons/clock(1).png");
    icon = new QLabel(this);
    icon->setPixmap(clockIcon.scaled(30,30,Qt::KeepAspectRatio));
    layout = new QHBoxLayout;
    lcd->setStyleSheet("border:1px solid rgb(224,156,34);border-radius:7px;");
    layout->addWidget(icon);
    layout->addWidget(lcd);
    lcd->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
    this->setLayout(layout);
    connect(timer,SIGNAL(timeout()),this,SLOT(updatetime()));
}

void TimerDisplay::start()
{
    lcd->display("00:00");
    timer->start(1000);
}

void TimerDisplay::restart()
{
    lcd->display("00:00");
    time->setHMS(0,0,0,0);
    start();
}

void TimerDisplay::pause()
{
    timer->stop();
}

void TimerDisplay::continuing()
{
    timer->start();
}

void TimerDisplay::updatetime()
{
    *time = time->addSecs(1);
    lcd->display(time->toString("mm:ss"));
}

QTime *TimerDisplay::getTime()
{
    return time;
}

TimerDisplay::~TimerDisplay()
{
    delete ui;
}
