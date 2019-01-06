#ifndef CHOOSELEVEL_H
#define CHOOSELEVEL_H

#include <QLabel>
#include <QComboBox>
#include <QWidget>
#include <QFrame>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLayout>
#include <QDebug>

namespace Ui {
class ChooseLevel;
}

class ChooseLevel : public QWidget
{
    Q_OBJECT

public:
    explicit ChooseLevel(QWidget *parent = 0);
    ~ChooseLevel();

public slots:
    void checkEnabled(int);
    void emitPrevious();
    void emitNext();
    void getIndex(int);

signals:
    void previousPage();
    void nextPage(int);

private:
    Ui::ChooseLevel *ui;
    int index;
    QLabel *title;
    QLabel *choice;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QVBoxLayout *layout_0;
};

#endif // CHOOSELEVEL_H
