#include "colorsfunctionwidget.h"

colorsFunctionWidget::colorsFunctionWidget(QWidget *parent) : QWidget(parent)
{
    int colorsList[30][3] = {{  0,  0,  0},{127,127,127},{136,  0, 21},{237, 28, 36},{255,127, 39}
                            ,{255,242,  0},{ 34,177, 76},{  0,162,232},{ 63, 72,204},{163, 73,164}
                            ,{255,255,255},{195,195,195},{185,122, 87},{255,174,201},{255,201, 14}
                            ,{239,228,176},{181,230, 29},{153,217,234},{112,146,190},{200,191,231}
                            ,{245,246,247},{245,246,247},{245,246,247},{245,246,247},{245,246,247}
                            ,{245,246,247},{245,246,247},{245,246,247},{245,246,247},{245,246,247}};
    colorButtonsInit(colorsList);

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

void colorsFunctionWidget::colorButtonsInit(const int colors[][3])
{
    colorOneButton = new QToolButton(this);
    colorOneButton->setIconSize(QSize(28,28));
    colorOneButton->setFixedSize(QSize(44,80));
    colorOneButton->setText(QString::fromUtf8("颜色1"));
    buttonListIconCreate(colorOneButton,0,0,0,28,28);

    colorTwoButton = new QToolButton(this);
    colorTwoButton->setIconSize(QSize(20,20));

    colorTwoButton->setText(QString::fromUtf8("颜色2"));

    paletteButton = new QToolButton(this);
    paletteButton->setIconSize(QSize(35,35));
    paletteButton->setIcon(QIcon(QApplication::applicationDirPath()+"/icons/colorsFunctionWidget/palette.png"));

    label = new QLabel(QString::fromUtf8("颜色") , this);
    label->setAlignment(Qt::AlignCenter);

    for(int i=0;i<30;i++)
    {
        buttonList[i] = new QPushButton(this);
        buttonList[i]->setIconSize(QSize(16,16));
        buttonList[i]->setFixedSize(QSize(22,22));
        buttonListIconCreate(buttonList[i],colors[i][0],colors[i][1],colors[i][2],16,16);
    }
    for(int i=20;i<30;i++)
    {
        buttonList[i]->setEnabled(false);
    }
}

void colorsFunctionWidget::buttonListIconCreate(QPushButton *tempButton,int Rint,int Gint,int Bint,int pixWidth,int pixHeight)
{
    QPixmap tempPixmap(pixWidth,pixHeight);
    tempPixmap.fill(QColor(Rint,Gint,Bint));
    QIcon *tempIcon = new QIcon(tempPixmap);
    tempButton->setIcon(*tempIcon);
}

void colorsFunctionWidget::buttonListIconCreate(QToolButton *tempButton,int Rint,int Gint,int Bint,int pixWidth,int pixHeight)
{
    QPixmap tempPixmap(pixWidth,pixHeight);
    tempPixmap.fill(QColor(Rint,Gint,Bint));
    QIcon *tempIcon = new QIcon(tempPixmap);
    tempButton->setIcon(*tempIcon);

    tempButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    tempButton->setCheckable(true);
}

