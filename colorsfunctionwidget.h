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

class colorsFunctionWidget : public QWidget
{
public:
    colorsFunctionWidget(QWidget *parent);
    ~colorsFunctionWidget();

    QToolButton *colorOneButton;    //颜色1按钮
    QToolButton *colorTwoButton;    //颜色2按钮
    QToolButton *paletteButton;     //编辑颜色按钮
    QPushButton *buttonList[30];    //选色框中30个色块按钮
    QLabel *label;

    void colorButtonsInit(const int colors[][3]);
    void buttonListIconCreate(QPushButton *tempButton,int Rint,int Gint,int Bint,int pixWidth,int pixHeight);   //根据RGB颜色生成按钮的Icon
    void buttonListIconCreate(QToolButton *tempButton,int Rint,int Gint,int Bint,int pixWidth,int pixHeight);   //根据RGB颜色生成按钮的Icon（重载）
};

#endif // COLORSFUNCTIONWIDGET_H
