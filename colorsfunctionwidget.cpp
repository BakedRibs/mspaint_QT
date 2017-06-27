#include "colorsfunctionwidget.h"

colorsFunctionWidget::colorsFunctionWidget(QWidget *parent) : QWidget(parent)
{
    colorButtonsInit();

    QGridLayout *buttonListLayout = new QGridLayout;
    for(int i=0;i<30;i++)
    {
        if(i<10)
        {
            buttonListLayout->addWidget(buttonList[i],0,i);
        }
        else if(i<20)
        {
            buttonListLayout->addWidget(buttonList[i],1,i-10);
        }
        else
        {
            buttonListLayout->addWidget(buttonList[i],2,i-20);
        }
    }
    buttonListLayout->setSpacing(2);

    QHBoxLayout *colorsLayout = new QHBoxLayout;
    colorsLayout->addWidget(colorOneButton);
    colorsLayout->addWidget(colorTwoButton);
    colorsLayout->addLayout(buttonListLayout);
    colorsLayout->addWidget(paletteButton);

    QVBoxLayout *colorsFunctionLayout = new QVBoxLayout;
    colorsFunctionLayout->addLayout(colorsLayout);
    colorsFunctionLayout->addWidget(label);

    this->setLayout(colorsFunctionLayout);
    this->show();
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
    paletteButton->setIcon(QIcon(QApplication::applicationDirPath()+"/icons/colorsFunctionWidget/palette.png"));
    label = new QLabel(QString::fromUtf8("颜色") , this);
    label->setAlignment(Qt::AlignCenter);
    for(int i=0;i<30;i++)
    {
        buttonList[i] = new QPushButton(this);
        buttonList[i]->setIconSize(QSize(16,16));
        buttonList[i]->setFixedSize(QSize(22,22));
    }
    QPixmap tempPixmap(16,16);
    tempPixmap.fill(QColor(0,0,0));
    QIcon *addf = new QIcon(tempPixmap);
    buttonList[0]->setIcon(*addf);
    //buttonList[0]->setStyleSheet("background-color:#000000");
    //buttonList[0]->setPalette(QPalette(Qt::white));
    //buttonList[0]->setAutoFillBackground(true);
}
