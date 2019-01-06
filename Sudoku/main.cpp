#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include "timerdisplay.h"
#include "grid.h"
#include "SudokuGenerator.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SudokuGenerator gene;
    gene.setlevel(1);
    qDebug()<<"check";
    qDebug()<<"doubleCheck";
    int *nums = gene.getProblem();
    for(int i = 0;i < 81; i = i+9)
    {
        qDebug("%d%d%d%d%d%d%d%d%d",nums[i],nums[i+1],nums[i+2],nums[i+3],nums[i+4],nums[i+5],nums[i+6],nums[i+7],nums[i+8]);
    }
    MainWindow window;
    window.show();

    return a.exec();
}
