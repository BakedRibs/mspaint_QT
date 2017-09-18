#include "colorsfunctionwidget.h"

int colorsList[30][3] = {{  0,  0,  0},{127,127,127},{136,  0, 21},{237, 28, 36},{255,127, 39}      //对选色框中
                        ,{255,242,  0},{ 34,177, 76},{  0,162,232},{ 63, 72,204},{163, 73,164}      //的30个按
                        ,{255,255,255},{195,195,195},{185,122, 87},{255,174,201},{255,201, 14}      //钮添加颜色
                        ,{239,228,176},{181,230, 29},{153,217,234},{112,146,190},{200,191,231}
                        ,{245,246,247},{245,246,247},{245,246,247},{245,246,247},{245,246,247}
                        ,{245,246,247},{245,246,247},{245,246,247},{245,246,247},{245,246,247}};

colorsFunctionWidget::colorsFunctionWidget(QWidget *parent) : QWidget(parent)
{
    colorButtonsInit(colorsList);                               //对所有按钮初始化
    colorOneButton->setChecked(true);                           //默认选择第一个按钮

    QGridLayout *buttonListLayout = new QGridLayout;            //选色框布局，存放30个选色按钮
    buttonListLayout->setSpacing(2);                            //设置选色按钮之间间隔为2像素
    for(int i=0;i<30;i++)
    {
        if(i<10)
        {
            buttonListLayout->addWidget(buttonList[i],0,i);     //第一行10个
        }
        else if(i<20)
        {
            buttonListLayout->addWidget(buttonList[i],1,i-10);  //第二行10个
        }
        else
        {
            buttonListLayout->addWidget(buttonList[i],2,i-20);  //第三行10个
        }
    }    

    QHBoxLayout *colorsLayout = new QHBoxLayout;                //主体水平布局
    colorsLayout->setSpacing(1);                                //设置控件间隔为1像素
    colorsLayout->addWidget(colorOneButton);                    //颜色1按钮
    colorsLayout->addWidget(colorTwoButton);                    //颜色2按钮
    colorsLayout->addLayout(buttonListLayout);                  //选色框
    colorsLayout->addWidget(paletteButton);                     //编辑颜色按钮

    QVBoxLayout *colorsFunctionLayout = new QVBoxLayout;        //全体垂直布局
    colorsFunctionLayout->addLayout(colorsLayout);              //水平布局控件
    colorsFunctionLayout->addWidget(label);                     //说明label

    this->setLayout(colorsFunctionLayout);
    this->show();

    connect(colorOneButton,SIGNAL(clicked()),this,SLOT(colorOneButtonClick()));         //颜色1按钮按下
    connect(colorTwoButton,SIGNAL(clicked()),this,SLOT(colorTwoButtonClick()));         //颜色2按钮按下
    connect(paletteButton,SIGNAL(clicked()),this,SLOT(colorPaletteButtonClick()));      //调色板按钮按下
    for(int i=0;i<30;i++)
    {
        connect(buttonList[i],SIGNAL(clicked()),this,SLOT(colorListButtonClick()));     //30个色块按钮逐一设置信号-槽链接
    }
}

colorsFunctionWidget::~colorsFunctionWidget()
{

}

void colorsFunctionWidget::colorButtonsInit(const int colors[][3])
{
    colorOneButton = new QToolButton(this);
    colorOneButton->setIconSize(QSize(28,28));                  //Icon尺寸为28*28
    colorOneButton->setFixedSize(QSize(44,80));                 //按钮尺寸为44*80
    colorOneButton->setText(QString::fromUtf8("颜色1"));
    buttonListIconCreate(colorOneButton,  0,  0,  0,28,28);     //用RGB量生成Icon，将此Icon设置为按钮图片（重载函数）
    colorOne = new QColor(0,0,0);                               //初始化颜色1

    colorTwoButton = new QToolButton(this);
    colorTwoButton->setIconSize(QSize(20,20));                  //Icon尺寸为20*20
    colorTwoButton->setFixedSize(QSize(44,80));                 //按钮尺寸为44*80
    colorTwoButton->setText(QString::fromUtf8("颜色2"));
    buttonListIconCreate(colorTwoButton,255,255,255,28,28);     //用RGB量生成Icon，将此Icon设置为按钮图片（重载函数）
    colorTwo = new QColor(255,255,255);                         //初始化颜色2

    paletteButton = new QToolButton(this);
    paletteButton->setIconSize(QSize(25,25));                   //Icon尺寸为25*25
    paletteButton->setFixedSize(QSize(44,80));                  //按钮尺寸为44*80
    paletteButton->setText(QString::fromUtf8("编辑\n颜色"));
    paletteButton->setIcon(QIcon(QApplication::applicationDirPath()+"/icons/colorsFunctionWidget/palette.png"));
    paletteButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    paletteButton->setCheckable(true);                          //使得QToolButton可以被按下

    label = new QLabel(QString::fromUtf8("颜色") , this);
    label->setAlignment(Qt::AlignCenter);                       //设置label居中

    for(int i=0;i<30;i++)
    {
        buttonList[i] = new QPushButton(this);
        buttonList[i]->setIconSize(QSize(16,16));               //Icon尺寸为16*16
        buttonList[i]->setFixedSize(QSize(22,22));              //按钮尺寸为22*22
        buttonListIconCreate(buttonList[i],colors[i][0],colors[i][1],colors[i][2],16,16);   //用RGB量生成Icon，将此Icon设置为按钮图片
    }
    for(int i=20;i<30;i++)
    {
        buttonList[i]->setEnabled(false);                       //第三行的10个选色按钮暂时未使用，设置其为禁用
    }
    buttonListNow = 20;
}

void colorsFunctionWidget::buttonListIconCreate(QPushButton *tempButton,int Rint,int Gint,int Bint,int pixWidth,int pixHeight)
{
    QPixmap tempPixmap(pixWidth,pixHeight);                     //根据宽*高生成特定大小的QPixmap
    tempPixmap.fill(QColor(Rint,Gint,Bint));                    //使用RGB生成的颜色来填充QPixmap
    QIcon *tempIcon = new QIcon(tempPixmap);                    //使用QPixmap生成新的QIcon
    tempButton->setIcon(*tempIcon);                             //使用QIcon作为QPushButton的图标
    tempButton->setCheckable(true);
}

void colorsFunctionWidget::buttonListIconCreate(QToolButton *tempButton,int Rint,int Gint,int Bint,int pixWidth,int pixHeight)
{
    QPixmap tempPixmap(pixWidth,pixHeight);                     //根据宽*高生成特定大小的QPixmap
    tempPixmap.fill(QColor(Rint,Gint,Bint));                    //使用RGB生成的颜色来填充QPixmap
    QIcon *tempIcon = new QIcon(tempPixmap);                    //使用QPixmap生成新的QIcon
    tempButton->setIcon(*tempIcon);                             //使用QIcon作为QToolButton的图标

    tempButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);//设置QToolButton的Icon在Text上方
    tempButton->setCheckable(true);                             //设置QToolButton可以被按下选中
}

void colorsFunctionWidget::colorOneButtonClick()
{
    colorOneButton->setChecked(true);
    colorTwoButton->setChecked(false);
    emit colorButtonClicked(colorOne);                          //颜色可能改变，发出信号
}

void colorsFunctionWidget::colorTwoButtonClick()
{
    colorOneButton->setChecked(false);
    colorTwoButton->setChecked(true);
    emit colorButtonClicked(colorTwo);                          //颜色可能改变，发出信号
}

void colorsFunctionWidget::colorListButtonClick()
{
    int R;
    int G;
    int B;
    QColor *colorTemp;
    for(int i=0;i<30;i++)
    {
        if(buttonList[i]->isChecked())                          //判断哪个色块按钮被按下
        {
            R = colorsList[i][0];
            G = colorsList[i][1];
            B = colorsList[i][2];
            colorTemp = new QColor(R,G,B);                      //获取被按下按钮的颜色
            buttonList[i]->setChecked(false);                   //在获取颜色后，使其不被选中，否则下次有其他按钮按下，就会有多于一个按钮同时按下，无法判断选中颜色
        }
    }
    if(colorOneButton->isChecked())                             //如果当前颜色1按钮被选择
    {
        QPixmap tempPixmap(28,28);                              //根据宽*高生成特定大小的QPixmap
        tempPixmap.fill(QColor(R,G,B));                         //使用RGB生成的颜色来填充QPixmap
        QIcon *tempIcon = new QIcon(tempPixmap);                //使用QPixmap生成新的QIcon
        colorOneButton->setIcon(*tempIcon);                     //使用QIcon作为QToolButton的图标
    }
    if(colorTwoButton->isChecked())
    {
        QPixmap tempPixmap(20,20);                              //根据宽*高生成特定大小的QPixmap
        tempPixmap.fill(QColor(R,G,B));                         //使用RGB生成的颜色来填充QPixmap
        QIcon *tempIcon = new QIcon(tempPixmap);                //使用QPixmap生成新的QIcon
        colorTwoButton->setIcon(*tempIcon);                     //使用QIcon作为QToolButton的图标
    }
    emit colorButtonClicked(colorTemp);                         //颜色可能改变，发出信号
}

void colorsFunctionWidget::colorPaletteButtonClick()
{
    QColor colorSelected = QColorDialog::getColor(Qt::black,this);  //弹出选色对话框
    if(colorSelected.isValid())                                     //如果成功选色
    {
        buttonList[buttonListNow]->setEnabled(true);                //激活一个未使用的色块按钮
        QPixmap tempPixmap(16,16);                                  //根据宽*高生成特定大小的QPixmap
        tempPixmap.fill(colorSelected);                             //使用RGB生成的颜色来填充QPixmap
        QIcon *tempIcon = new QIcon(tempPixmap);                    //使用QPixmap生成新的QIcon
        buttonList[buttonListNow]->setIcon(*tempIcon);              //使用QIcon作为QToolButton的图标
        colorSelected.getRgb(&colorsList[buttonListNow][0],&colorsList[buttonListNow][1],&colorsList[buttonListNow][2]);    //用得到的颜色修改颜色列表中的RGB值
        if(buttonListNow < 29)
        {
            buttonListNow++;                                        //最后一个色块按钮使用完成后，每次选色更新最后一个色块
        }
    }
}

