#include "grid.h"
#include "ui_grid.h"
#include <QDebug>

Grid::Grid(int level, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Grid)
{
    nowCell = -1;
    level_0 = level;
    mapper  = new QSignalMapper(this);
    memento = new Memento;
    updateUndoAndRedo();
    for(int i = 0;i < 81;i++)
    {
        cells[i] = new Cell(this);
        if(getBlockOrder(i)%2 == 0)
        {
        cells[i]->setStyleSheet("border-radius:10px;background-color:rgb(185,167,194);");
        }
        else
            cells[i]->setStyleSheet("border-radius:10px;background-color:rgb(194,223,234);");
        cells[i]->setFixedSize(50,50);
    }
    layout = new QGridLayout;
    generator = new SudokuGenerator;
    generator->setlevel(level);
    gridNumbers = generator->getProblem();
    for(int i = 0;i < 81;i++)
    {
        qDebug()<<gridNumbers[i];
        if(gridNumbers[i])
        {
            cells[i]->setChangeable(false);
            cells[i]->initializeNum(gridNumbers[i]);
            cells[i]->setStyleSheet(cells[i]->styleSheet().append(QString("color:rgb(162,79,73);")));
        }
        else{
            cells[i]->setStyleSheet(cells[i]->styleSheet().append(QString("color:rgb(109,115,118);")));
        }
    }
    QGridLayout *subGrids[9];
    for(int i = 0;i < 9;i++)
    {
        subGrids[i] = new QGridLayout();
    }
    for(int i = 0;i < 81;i++)
    {
        int row = i/9;
        int col = i%9;
        int row_order = row/3;
        int col_order = col/3;
        int order = row_order*3 + col_order;
        subGrids[order]->addWidget(cells[i],row-row_order*3,col-col_order*3);
    }
    for(int i = 0;i < 9;i++)
    {
        subGrids[i]->setSpacing(1);
        layout->addLayout(subGrids[i],i/3,i%3);
    }
    layout->setSpacing(1);
    this->setLayout(layout);
    this->setFocusPolicy(Qt::ClickFocus);
    for(int i = 0;i < 81;i++)
    {
        connect(cells[i],SIGNAL(clicked(bool)),mapper,SLOT(map()));
        mapper->setMapping(cells[i],i);
    }
    connect(mapper,SIGNAL(mapped(int)),this,SLOT(cellClicked(int)));
}

void Grid::acceptInsert(int numInserted,int index)
{
    if(index == -1)
    {
        if(nowCell >= 0 && cells[nowCell]->whetherChangeable())
        {
            cells[nowCell]->typeNum(numInserted);
            cellClicked(nowCell);
            vector<int> a;
            a.push_back(numInserted);
            memento->addAction(nowCell,1,a);
            updateUndoAndRedo();
            if(checkSuccess())
            {
                emit succeed();
            }
        }
    }
    else
    {
        if(index >= 0 && cells[index]->whetherChangeable())
        {
            cells[index]->typeNum(numInserted);
            if(nowCell >= 0)
                cellClicked(nowCell);
            vector<int> a;
            a.push_back(numInserted);
            memento->addAction(index,1,a);
            updateUndoAndRedo();
            if(checkSuccess())
                emit succeed();
        }
    }
}

void Grid::cellClicked(int cellNum)
{
    qDebug()<<"cellClicked";
    QApplication::beep();
    nowCell = cellNum;
    for(int i = 0;i < 81;i++)
    {
        if(getBlockOrder(i)%2 == 0)
        {
            cells[i]->setStyleSheet("border-radius:10px;border:0px;background-color:rgb(185,167,194);");
            if(gridNumbers[i])
                cells[i]->setStyleSheet(cells[i]->styleSheet().append(QString("color:rgb(162,79,73);")));
            else
                cells[i]->setStyleSheet(cells[i]->styleSheet().append(QString("color:rgb(109,115,118);")));
        }
        else
        {

            cells[i]->setStyleSheet("border-radius:10px;border:0px;background-color:rgb(194,223,234);");
            if(gridNumbers[i])
                cells[i]->setStyleSheet(cells[i]->styleSheet().append(QString("color:rgb(162,79,73);")));
            else
                cells[i]->setStyleSheet(cells[i]->styleSheet().append(QString("color:rgb(109,115,118);")));
        }
    }
    int row_0 = cellNum/9;
    int col_0 = cellNum%9;
    int i = cellNum;
    for(int j = 0;j < 81;j++)
    {
        if(j != i )
        {
            int row_1 = j/9;
            int col_1 = j%9;
            if(row_0 == row_1 || col_0 == col_1)
            {
                if(getBlockOrder(j)%2 == 0)
                {
                    cells[j]->setStyleSheet("border-radius:10px;border:2px solid rgb(148,123,137);background-color:rgb(185,167,194);");
                    if(gridNumbers[j])
                        cells[j]->setStyleSheet(cells[j]->styleSheet().append(QString("color:rgb(162,79,73);")));
                    else
                        cells[j]->setStyleSheet(cells[j]->styleSheet().append(QString("color:rgb(109,115,118);")));
                }
                else
                {
                    cells[j]->setStyleSheet("border-radius:10px;border:2px solid rgb(148,123,137);background-color:rgb(194,223,234);");
                    if(gridNumbers[j])
                        cells[j]->setStyleSheet(cells[j]->styleSheet().append(QString("color:rgb(162,79,73);")));
                    else
                        cells[j]->setStyleSheet(cells[j]->styleSheet().append(QString("color:rgb(109,115,118);")));
                }
            }
        }
    }
    if(cells[i]->text().length() == 1)
    {
        int numOfCell = cells[i]->text().toInt();
        for(int j = 0;j < 81;j++)
        {
            if(j != i)
            {
                if(cells[j]->text().length() == 1)
                {
                    int num_1 = cells[j]->text().toInt();
                    if(num_1 == numOfCell)
                    {
                        if(getBlockOrder(j)%2 == 0)
                        {
                        cells[j]->setStyleSheet("border-radius:10px;background-color:rgb(182,208,201);");
                        if(gridNumbers[j])
                            cells[j]->setStyleSheet(cells[j]->styleSheet().append(QString("color:rgb(162,79,73);")));
                        else
                            cells[j]->setStyleSheet(cells[j]->styleSheet().append(QString("color:rgb(109,115,118);")));
                        }
                        else
                        {
                            cells[j]->setStyleSheet("border-radius:10px;background-color:rgb(182,208,201);");
                            if(gridNumbers[j])
                                cells[j]->setStyleSheet(cells[j]->styleSheet().append(QString("color:rgb(162,79,73);")));
                            else
                                cells[j]->setStyleSheet(cells[j]->styleSheet().append(QString("color:rgb(109,115,118);")));
                        }
                    }
                }
            }
        }
    }
}

void Grid::hint()
{
    for(int i = 0;i < 81;i++)
    {
        if(cells[i]->returnChangeable())
        {
            if(!checkCell(i))
            {
                QString ss = cells[i]->text();
                if(ss.length() > 0)
                {
                    cells[i]->setStyleSheet("border-radius:10px;background-color:rgb(136,0,63);");
                    return;
                }
                else
                {
                    int a = generator->getSolution(i);
                    acceptInsert(a,i);
                    return;
                }
            }
        }
    }
}

bool Grid::checkSuccess()
{
    for(int i = 0;i < 81;i++)
    {
        if(cells[i]->returnChangeable())
        {
            if(!checkCell(i))
                return false;
        }
    }
    return true;
}

bool Grid::checkCell(int i)
{
    if(cells[i]->text().isEmpty())
        return false;
    if(cells[i]->text().length() != 1)
        return false;
    int num = cells[i]->text().toInt();
    int row_0 = i/9;
    int col_0 = i%9;
    int row_order = row_0/3;
    int col_order = col_0/3;
    int order = row_order*3 + col_order;
    for(int j = 0;j < 81;j++)
    {
        if(i != i)
        {
            int row_1 = j/9;
            int col_1 = j%9;
            int row_order_1 = row_1/3;
            int col_order_1 = col_1/3;
            int order_1 = row_order_1*3 + col_order_1;
            if(row_1 == row_0 || col_1 == col_0 || order_1 == order)
            {
                int num_1 = cells[i]->text().toInt();
                if(num_1 == num)
                    return false;
            }
        }
    }
    return true;
}

void Grid::deleteNum(int position)
{
    bool *state;
    state = cells[position]->getNumState();
    vector<int> vec;
    for(int i = 0;i < 9;i++)
    {
        if(state[i])
        {
            vec.push_back(i+1);
        }
    }
    cells[position]->clear();
    memento->addAction(position,0,vec);
    updateUndoAndRedo();
}

void Grid::deleteCellNum()
{
    if(nowCell > 0 && cells[nowCell]->whetherChangeable())
        deleteNum(nowCell);
}

void Grid::updateUndoAndRedo()
{
    if(memento->checkAbleUndo())
    {
        emit enableUndo(true);
    }
    else
        emit disableUndo(true);
    if(memento->checkAbleRedo())
    {
        emit enableRedo(true);
    }
    else
        emit disableRedo(true);
}

int Grid::getBlockOrder(int i)
{
    int row = i/9;
    int col = i%9;
    int row_order = row/3;
    int col_order = col/3;
    int order = row_order*3 + col_order;
    return order;
}

void Grid::restart()
{
    for(int i = 0; i < 81;i++)
    {
        if(cells[i]->whetherChangeable())
        {
            cells[i]->clear();
        }
    }
}

void Grid::undo()
{
    if(memento->checkAbleUndo())
    {
        Action act;
        act = memento->getAction(memento->getIndex());
        memento->undo();
        if(act.enumOfAction == 1)
        {
            cells[act.index]->typeNum(act.nums[0]);
        }
        else
        {
            for(int i = 0;i < act.nums.size();i++)
            {
                cells[act.index]->typeNum(act.nums[i]);
                qDebug()<<QString::number(i);
            }
        }
    }
    updateUndoAndRedo();
}

void Grid::redo()
{
    if(memento->checkAbleRedo())
    {
        Action act;
        int n;
        n = memento->getIndex();
        act = memento->getAction(n+1);
        memento->redo();
        if(act.enumOfAction == 1)
        {
            cells[act.index]->typeNum(act.nums[0]);
        }
        else
        {
            for(int i = 0;i < act.nums.size();i++)
            {
                cells[act.index]->typeNum(act.nums[i]);
            }
        }
    }
    updateUndoAndRedo();
}

void Grid::rewrite(int level)
{
    qDebug()<<"rewrite";
    nowCell = -1;
    level_0 = level;
    memento->clear();
    SudokuGenerator *a = new SudokuGenerator;
    generator = a;
    generator->setlevel(level);
    gridNumbers = generator->getProblem();
    for(int i = 0;i < 81;i++)
    {
        QString ss;
        ss.clear();
        cells[i]->setText(ss);
        cells[i]->clearBools();
        if(gridNumbers[i])
        {
            cells[i]->setChangeable(false);
            cells[i]->initializeNum(gridNumbers[i]);
            cells[i]->setStyleSheet(cells[i]->styleSheet().append(QString("color:rgb(162,79,73);")));
        }
        else{
            cells[i]->setChangeable(true);
            cells[i]->setStyleSheet(cells[i]->styleSheet().append(QString("color:rgb(109,115,118);")));
        }
    }
    update();
}

Grid::~Grid()
{
    delete ui;
}
