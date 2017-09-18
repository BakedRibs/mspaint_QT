#ifndef COLORSFUNCTIONWIDGET_H
#define COLORSFUNCTIONWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QToolButton>
#include <QApplication>
#include <QTextCodec>
#include <QLabel>
#include <QVector>
#include <QColorDialog>

class colorsFunctionWidget : public QWidget
{
    Q_OBJECT                                        //注意：若包含自定义SIGNAL或SLOT，则需包含此行

public:
    colorsFunctionWidget(QWidget *parent);
    ~colorsFunctionWidget();

    QToolButton *colorOneButton;                    //颜色1按钮
    QToolButton *colorTwoButton;                    //颜色2按钮
    QToolButton *paletteButton;                     //编辑颜色按钮
    QPushButton *buttonList[30];                    //选色框中30个色块按钮
    QLabel *label;
    QColor *colorOne;                               //按钮1颜色
    QColor *colorTwo;                               //按钮2颜色
    int buttonListNow;                              //色块按钮当前解锁位置

    void colorButtonsInit(const int colors[][3]);   //颜色按钮初始化
    void buttonListIconCreate(QPushButton *tempButton,int Rint,int Gint,int Bint,int pixWidth,int pixHeight);   //根据RGB颜色生成按钮的Icon
    void buttonListIconCreate(QToolButton *tempButton,int Rint,int Gint,int Bint,int pixWidth,int pixHeight);   //根据RGB颜色生成按钮的Icon（重载）

public slots:
    void colorOneButtonClick();                     //颜色1按钮按下事件
    void colorTwoButtonClick();                     //颜色2按钮按下事件
    void colorListButtonClick();                    //色块按钮按下事件
    void colorPaletteButtonClick();                 //调色板按钮按下事件

signals:
    void colorButtonClicked(QColor *colorSel);      //选择颜色变化，发出信号
};

#endif // COLORSFUNCTIONWIDGET_H
