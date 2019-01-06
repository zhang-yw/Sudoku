#include "chooselevel.h"
#include "ui_chooselevel.h"
#include <QLabel>
#include <QComboBox>
#include <QWidget>
#include <QPushButton>
#include <QLayout>

void ChooseLevel::checkEnabled(int index)
{
    if(index != 0)
    {
        pushButton_2->setEnabled(true);
    }
    else
        pushButton_2->setEnabled(false);
}

void ChooseLevel::getIndex(int i)
{
    index = i;
}

void ChooseLevel::emitPrevious()
{
    emit previousPage();
}

void ChooseLevel::emitNext()
{
    emit  nextPage(index);

}


ChooseLevel::ChooseLevel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChooseLevel)
{
    index = 0;
    this->setWindowTitle("Sudoku");
    title = new QLabel(this);
    choice = new QLabel(this);
    comboBox = new QComboBox(this);
    pushButton = new QPushButton(this);
    pushButton_2 = new QPushButton(this);
    layout_0 = new QVBoxLayout(this);
    QHBoxLayout *layout_1 = new QHBoxLayout;
    pushButton_2->setEnabled(false);
    QFont font;
    font.setPixelSize(90);
    font.setFamily("LeviBrush");
    font.setStyle(QFont::StyleNormal);
    title->setFont(font);
    title->setText("Sudoku");
    title->setAlignment(Qt::AlignCenter);
    title->setStyleSheet("color:rgb(224,156,34)");
    title->adjustSize();
    QFont font_1;
    font_1.setPixelSize(17);
    font_1.setFamily("Microsoft Yahei");
    font_1.setStyle(QFont::StyleNormal);
    choice->setFont(font_1);
    choice->setAlignment(Qt::AlignCenter);
    choice->setStyleSheet("color:rgb(224,156,34)");
    choice->adjustSize();
    choice->setText(QStringLiteral("选择难度"));
    comboBox->addItem(QStringLiteral("请选择难度"));
    comboBox->addItem(QStringLiteral("简单"));
    comboBox->addItem(QStringLiteral("中等"));
    comboBox->addItem(QStringLiteral("困难"));
    pushButton->setText(QStringLiteral("返回"));
    pushButton_2->setText(QStringLiteral("开始游戏"));
    pushButton->setStyleSheet("QPushButton{color:rgb(224,156,34);border:2px solid rgb(224,156,34);border-radius:10px;font-size:17px;font-family:造字工房典黑（非商用）;}");
    pushButton->setFixedHeight(45);
    pushButton_2->setStyleSheet("QPushButton{color:rgb(224,156,34);border:2px solid rgb(224,156,34);border-radius:10px;font-size:17px;font-family:造字工房典黑（非商用）;}"
                                "QPushButton:!enabled{color:gray;border:2px solid gray;border-radius:10px;font-size:17px;font-family:造字工房典黑（非商用）;}");
    pushButton_2->setFixedHeight(45);
    comboBox->setFixedHeight(30);
    comboBox->setStyleSheet("QComboBox{border:1px solid rgb(224,156,34);border-radius:15px;color:rgb(224,156,34)}"
                            "QComboBox::drop-down{width: 30px;border-left-width: 1px;border-left-color: darkgray;border-left-style: solid rgb(224,156,34);border-top-right-radius: 15px;border-bottom-right-radius: 15px;}"
                            "QComboBox::down-arrow{border-image:url(:/new/icons/icons/downarrow.png)}");
    QFrame *line_0 = new QFrame;
    line_0->setFrameShape(QFrame::HLine);
    line_0->setStyleSheet("border:1px solid rgb(224,156,34);");
    QFrame *line_1 = new QFrame;
    line_1->setFrameShape(QFrame::HLine);
    line_1->setStyleSheet("border:1px solid rgb(224,156,34);");
    layout_1->addWidget(choice);
    layout_1->addWidget(comboBox);
    layout_0->addWidget(pushButton);
    layout_0->addStretch(10);
    layout_0->addWidget(title);
    layout_0->addStretch(10);
    layout_0->addWidget(line_0);
    layout_0->addLayout(layout_1);
    layout_0->addWidget(line_1);
    layout_0->addStretch(1);
    layout_0->addWidget(pushButton_2);
    this->setLayout(layout_0);
    connect(pushButton,SIGNAL(clicked()),this,SLOT(emitPrevious()));
    connect(pushButton_2,SIGNAL(clicked()),this,SLOT(emitNext()));
    connect(comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(getIndex(int)));
    connect(comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(checkEnabled(int)));
}

ChooseLevel::~ChooseLevel()
{
    delete ui;
}
