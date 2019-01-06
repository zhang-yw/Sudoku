#ifndef GAMEINTERFACE_H
#define GAMEINTERFACE_H

#include <QWidget>
#include <QPushButton>
#include <QDialog>
#include <QFont>
#include <QLabel>
#include <QPalette>
#include <QSignalMapper>
#include <QCOlor>
#include <QRegion>
#include "timerdisplay.h"
#include "grid.h"

namespace Ui {
class GameInterface;
}

class GameInterface : public QWidget
{
    Q_OBJECT

public:
    explicit GameInterface(QWidget *parent = 0);
    ~GameInterface();


signals:
    void previousPage();

public slots:
    void emitPreviousPage(){emit previousPage();}
    void initialize(int);
    void showDialog();
    void numInsert(int);
    void succeed();

private:
    Ui::GameInterface *ui;
    QVBoxLayout *layout;
    QHBoxLayout *layout_0;
    QHBoxLayout *layout_1;
    QHBoxLayout *layout_2;
    QHBoxLayout *layout_3;
    QHBoxLayout *layout_4;
    QVBoxLayout *layoutOfSuccess;
    QPushButton *puaseButton;
    QPushButton *restartButton;
    QPushButton *returnButton;
    QPushButton *withdrawButton;
    QPushButton *recoverButton;
    QPushButton *deleteButton;
    QPushButton *hintButton;
    QPushButton *restartButton_1;
    QPushButton *restartButtonAfterSuccess;
    TimerDisplay *timer;
    QSignalMapper *mapperInsert;
    QDialog *pauseDialog;
    QDialog *succeedDialog;
    QLabel *title;
    QLabel *titleOfSuccess;
    QLabel *successTime;
    Grid *grid;
    QPushButton *keyBoard[9];
};

#endif // GAMEINTERFACE_H
