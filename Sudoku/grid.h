#ifndef GRID_H
#define GRID_H

#include <QWidget>
#include <QGridLayout>
#include <QPalette>
#include <QColor>
#include <QSignalMapper>
#include <QWidget>
#include "cell.h"
#include "SudokuGenerator.h"
#include "memento.h"

using namespace std;

namespace Ui {
class Grid;
}

class Grid : public QWidget
{
    Q_OBJECT

public:
    explicit Grid(int level,QWidget *parent = 0);
    ~Grid();
    int getlevel(){return level_0;}
    void rewrite(int);
    int getBlockOrder(int);
    void deleteNum(int);
    void updateUndoAndRedo();
    bool checkSuccess();
    bool checkCell(int);

signals:
    void enableUndo(bool);
    void enableRedo(bool);
    void disableRedo(bool);
    void disableUndo(bool);
    void success(bool);
    void succeed();

public slots:
    void restart();
    void undo();
    void redo();
    void cellClicked(int);
    void hint();
    void acceptInsert(int n,int m= -1);
    void deleteCellNum();

private:
    Ui::Grid *ui;
    Cell *cells[81];
    QGridLayout *layout;
    SudokuGenerator *generator;
    int *gridNumbers;
    int level_0;
    Memento *memento;
    QSignalMapper *mapper;
    int nowCell;
};

#endif // GRID_H
