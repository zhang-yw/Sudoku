#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "chooselevel.h"
#include "gameinterface.h"
#include <QFont>
#include <QLabel>
#include <QWidget>
#include <QLayout>
#include <QtWidgets>
#include <QMainWindow>

void MainWindow::changeSize()
{
    for (int i = 0; i < m_pStackedWidget->count (); ++i)
    {
        QSizePolicy::Policy policy = QSizePolicy::Ignored;
        if (i == m_pStackedWidget->currentIndex ())
            policy = QSizePolicy::Expanding;
        QWidget* pPage = m_pStackedWidget->widget (i);
        pPage->setSizePolicy (policy, policy);
        m_pStackedWidget->adjustSize();
    }

}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->setWindowTitle("Sudoku");
    QPushButton *pButton_1 = new QPushButton(this);
    QPushButton *pButton_2 = new QPushButton(this);
    QLabel *title = new QLabel(this);
    m_pStackedWidget = new QStackedWidget(this);
    pButton_1->setText(QStringLiteral("进入游戏"));
    pButton_1->setStyleSheet("QPushButton{color:rgb(224,156,34);border:2px solid rgb(224,156,34);border-radius:15px;font-size:17px;font-family:造字工房典黑（非商用）;}");
    pButton_1->setFixedSize(150,45);
    pButton_2->setText(QStringLiteral("退出游戏"));
    pButton_2->setStyleSheet("QPushButton{color:rgb(224,156,34);border:2px solid rgb(224,156,34);border-radius:15px;font-size:17px;font-family:造字工房典黑（非商用）;}");
    pButton_2->setFixedSize(150,45);
    QFont font;
    font.setPixelSize(90);
    font.setFamily("LeviBrush");
    font.setStyle(QFont::StyleNormal);
    title->setFont(font);
    title->setText("Sudoku");
    title->setAlignment(Qt::AlignCenter);
    title->setStyleSheet("color:rgb(224,156,34)");
    title->adjustSize();
    QVBoxLayout *layout = new QVBoxLayout;
    QHBoxLayout* buttonLayout = new QHBoxLayout;
    QHBoxLayout* buttonLayout_2 = new QHBoxLayout;
    buttonLayout->addStretch(1);
    buttonLayout->addWidget(pButton_2);
    buttonLayout->addStretch(1);
    buttonLayout_2->addStretch(1);
    buttonLayout_2->addWidget(pButton_1);
    buttonLayout_2->addStretch(1);
    layout->addWidget(title);
    layout->addLayout(buttonLayout_2);
    layout->addLayout(buttonLayout);
    QWidget *widget = new QWidget(this);
    widget->setFixedSize(510,711);
    widget->setLayout(layout);
    chooseLevel = new ChooseLevel;
    gameInterface = new GameInterface;
    m_pStackedWidget->addWidget(widget);
    m_pStackedWidget->addWidget(chooseLevel);
    m_pStackedWidget->addWidget(gameInterface);
    this->setCentralWidget(m_pStackedWidget);
    m_pStackedWidget->setCurrentWidget(widget);
    connect(pButton_1,SIGNAL(clicked(bool)),this,SLOT(addPage()));
    connect(chooseLevel,SIGNAL(nextPage(int)),this,SLOT(thirdPage(int)));
    connect(chooseLevel,SIGNAL(nextPage(int)),this,SLOT(addPage()));
    connect(chooseLevel,SIGNAL(previousPage()),this,SLOT(decreasePage()));
    connect(gameInterface,SIGNAL(previousPage()),this,SLOT(decreasePage()));
    connect(pButton_2,SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(m_pStackedWidget,SIGNAL(currentChanged(int)),this,SLOT(changeSize()));
}

void MainWindow::thirdPage(int level)
{
    gameInterface->initialize(level);
    QSound *sound  = new QSound("/Users/yw-zhang/Documents/SummerSemester/Week1Project/Sudoku/music/_-_.wav");
    sound->play();
    sound->setLoops(-1);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::addPage()
{
    int count = m_pStackedWidget->count();
    int index = m_pStackedWidget->currentIndex();
    ++index;
    if(index >= count)
    {
        index = 0;
    }
    m_pStackedWidget->setCurrentIndex(index);
}

void MainWindow::decreasePage()
{
    int count = m_pStackedWidget->count();
    int index = m_pStackedWidget->currentIndex();
    if(index > 0);
    {
        index--;
    }
    m_pStackedWidget->setCurrentIndex(index);
    m_pStackedWidget->resize(510,711);
    m_pStackedWidget->update();
}
