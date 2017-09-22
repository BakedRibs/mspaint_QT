#ifndef TOOLSFUNCTIONWIDGET_H
#define TOOLSFUNCTIONWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QApplication>
#include <QTextCodec>
#include <QLabel>

class toolsFunctionWidget : public QWidget
{
    Q_OBJECT                                        //注意：若包含自定义SIGNAL或SLOT，则需包含此行

public:
    toolsFunctionWidget(QWidget *parent);
    ~toolsFunctionWidget();

    QPushButton *pencilButton;                      //铅笔
    QPushButton *fillWithColor;                     //用颜色填充
    QPushButton *textButton;                        //文本
    QPushButton *eraserButton;                      //橡皮擦
    QPushButton *colorSelectButton;                 //颜色选取器
    QPushButton *magnifierButton;                   //放大镜
    QLabel *label;                                  //标签

    void setButtonAlignment(QPushButton *tmpButton , QString iconPath); //统一设置button参数

public slots:
    void buttonClicked();                           //定义槽，按钮按下时调用

signals:
    void whichButtonClicked(QString buttonName);    //定义信号，按钮按下时发送其名称
};

#endif
