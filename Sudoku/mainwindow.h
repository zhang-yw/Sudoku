#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QSizePolicy>
#include <QVBoxLayout>
#include <QSound>
#include <QHBoxLayout>
#include "chooselevel.h"
#include "gameinterface.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void changeSize();
    void addPage();
    void decreasePage();
    void thirdPage(int);

private:
    Ui::MainWindow *ui;
    QStackedWidget *m_pStackedWidget;
    ChooseLevel *chooseLevel;
    GameInterface *gameInterface;
};

#endif // MAINWINDOW_H
