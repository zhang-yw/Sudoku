#ifndef CELL_H
#define CELL_H

#include <QWidget>
#include <QPushButton>
#include <QFont>

namespace Ui {
class Cell;
}

class Cell : public QPushButton
{
    Q_OBJECT

public:
    explicit Cell(QWidget *parent = 0);
    ~Cell();
    bool *getNumState(){return nums;}
    bool whetherChangeable(){return isChangeable;}
    void setChangeable(bool is){isChangeable = is;}
    bool returnChangeable(){return isChangeable;}
    void clear();
    void clearBools();
    void initializeNum(int);

public slots:
    void typeNum(int);

private:
    void updateText();

private:
    Ui::Cell *ui;
    bool isChangeable;
    bool nums[9];
};

#endif // CELL_H
