#ifndef TOOLSFUNCTIONWIDGET_H
#define TOOLSFUNCTIONWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QToolButton>

class toolsFunctionWidget : public QWidget
{
public:
    toolsFunctionWidget(QWidget *parent);
    ~toolsFunctionWidget();

    QToolButton *pencilButton;      //铅笔
    QToolButton *fillWithColor;     //用颜色填充
    QToolButton *textButton;        //文本
    QToolButton *eraserButton;      //橡皮擦
    QToolButton *colorSelectButton; //颜色选取器
    QToolButton *magnifierButton;   //放大镜

    void setButtonAlignment(QToolButton *tmpButton , QString iconPath);
};

#endif // TOOLSFUNCTIONWIDGET_H
