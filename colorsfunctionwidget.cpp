#include "colorsfunctionwidget.h"

colorsFunctionWidget::colorsFunctionWidget(QWidget *parent) : QWidget(parent)
{
    colorButtonsInit();
}

colorsFunctionWidget::~colorsFunctionWidget()
{

}

void colorsFunctionWidget::colorButtonsInit()
{
    colorOneButton = new QPushButton(this);
    colorOneButton->setIconSize(QSize(40,40));
    colorOneButton->setText(QString::fromUtf8("颜色1"));
    colorTwoButton = new QPushButton(this);
    colorTwoButton->setIconSize(QSize(30,30));
    colorTwoButton->setText(QString::fromUtf8("颜色2"));
    paletteButton = new QPushButton(this);
    paletteButton->setIconSize(QSize(35,35));
    for(int i=0;i<20;i++)
    {
        QPushButton *tempButton = new QPushButton(this);
        changelessButtonList->append(tempButton);
        tempButton->setIconSize(QSize(20,20));
    }
    for(int i=0;i<10;i++)
    {
        QPushButton *tempButton = new QPushButton(this);
        changeableButtonList->append(tempButton);
        tempButton->setIconSize(QSize(20,20));
    }
}
