#ifndef TIMERDISPLAY_H
#define TIMERDISPLAY_H

#include <QWidget>
#include <QTime>
#include <QTimer>
#include <QLCDNumber>
#include <QIcon>
#include <QLabel>
#include <QPixmap>
#include <QHBoxLayout>

namespace Ui {
class TimerDisplay;
}

class TimerDisplay : public QWidget
{
    Q_OBJECT

public:
    explicit TimerDisplay(QWidget *parent = 0);
    ~TimerDisplay();
    QTime *getTime();

public slots:
    void start();
    void pause();
    void restart();
    void continuing();

private slots:
    void updatetime();

private:
    Ui::TimerDisplay *ui;
    QLCDNumber *lcd;
    QTime *time;
    QTimer *timer;
    QLabel *icon;
    QHBoxLayout *layout;
};

#endif // TIMERDISPLAY_H
