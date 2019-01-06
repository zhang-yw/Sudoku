#include "cell.h"
#include "ui_cell.h"
#include <memory>

Cell::Cell(QWidget *parent) :
    QPushButton(parent),
    ui(new Ui::Cell)
{
    memset(nums, false, sizeof(nums));
    this->setFixedSize(60,60);
    isChangeable = true;
}

void Cell::typeNum(int num_0)
{
    if(num_0 > 0 && num_0 < 10 && isChangeable)
    {
        nums[num_0-1] = !nums[num_0-1];
        updateText();
    }
}

void Cell::initializeNum(int num_0)
{
    if(num_0 > 0 && num_0 < 10 )
    {
        nums[num_0-1] = !nums[num_0-1];
        updateText();
    }
}

void Cell::updateText()
{
    QString ss;
    int counter = 0;
    for(int i=0;i < 9;i++)
    {
        if(nums[i])
            counter++;
    }
    if(counter == 0)
    {
        QString abc;
        abc.clear();
        this->setText(abc);
        return;
    }
    if(counter == 1)
    {
        for(int i = 0;i < 9;i++)
        {
            if(nums[i])
            {
                QFont font;
                font.setPointSize(27);
                ss += QString::number(i+1);
                this->setText(ss);
                this->setFont(font);
                return;
            }
        }
    }
    ss.clear();
    for(int i = 0;i < 9;i++)
    {
        if(nums[i])
        {
            ss += QString::number(i+1,10);
        }
        else
            ss += QString("  ");
        if(i == 8)
            break;
        if(i%3 == 2)
        {
            ss += '\n';
        }
        else
            ss += ' ';
    }
    QFont font_1;
    font_1.setPointSize(15);

    this->setText(ss);
    this->setFont(font_1);
}

void Cell::clear()
{
    if(isChangeable)
    {
        for(int i = 0;i < 9;i++)
        {
            nums[i] = false;
        }
        updateText();
    }
}

void Cell::clearBools()
{
    for(int i = 0;i < 9;i++)
    {
        nums[i] = false;
    }
}

Cell::~Cell()
{
    delete ui;
}
