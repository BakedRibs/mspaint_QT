#ifndef SHAPESFUNCTIONWIDGET_H
#define SHAPESFUNCTIONWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QApplication>
#include <QLabel>

class shapesFunctionWidget : public QWidget
{
    Q_OBJECT                                        //注意：若包含自定义SIGNAL或SLOT，则需包含此行

public:
    shapesFunctionWidget(QWidget *parent);
    ~shapesFunctionWidget();

    QPushButton *shapesButtonList[18];              //定义类中的18个按钮
    QLabel *label;

    void shapesButtonsInit();                       //初始化类中的18个按钮

public slots:
    void buttonClicked();                           //按钮被按下时，相应事件

signals:
    void whichButtonClicked(int buttonNum);         //按钮被按下时，发送信号，信号中包含被按下按钮序号
};

#endif // SHAPESFUNCTIONWIDGET_H
