#include <QtGui>
#include "paint_qt.h"

paint_QT::paint_QT()
{
    mainLayout = new QVBoxLayout;
    paintZone = new MyPainterWidget(this);          //声明在头文件类定义中，方便引用
    topControlPanel = new mainControlPanel(this);   //声明在头文件类定义中，方便引用

    mainLayout->addWidget(topControlPanel);
    mainLayout->addWidget(paintZone);

    setLayout(mainLayout);

    connect(topControlPanel->colorsFunction,SIGNAL(colorButtonClicked(QColor*)),this,SLOT(colorButtonClicked(QColor*)));    //收到颜色区域信号，传递QColor信息
    connect(topControlPanel->toolsFunction,SIGNAL(whichButtonClicked(QString)),this,SLOT(toolsButtonClicked(QString)));     //收到工具趋于信号，传递工具种类信息
    connect(topControlPanel->shapesFunction,SIGNAL(whichButtonClicked(int)),this,SLOT(shapesButtonClicked(int)));           //收到形状区域信号，传递形状类型号码
    connect(topControlPanel->penWidthFunction,SIGNAL(penWidthChanged(int)),this,SLOT(penwidthButtonClicked(int)));          //收到宽度区域信号，传递宽度数值
}

paint_QT::~paint_QT()
{

}

void paint_QT::colorButtonClicked(QColor* tmpColor)
{
    paintZone->paintNowDetails.parameters.paintColor = *tmpColor;                   //画图区域的颜色参数改变
}

void paint_QT::toolsButtonClicked(QString tmpString)
{
    if(tmpString == "pencilButton")
    {
        paintZone->paintNowDetails.parameters.paintType = pencil;                   //每次点击铅笔图标时，重复设置此参数
        paintZone->paintNowDetails.parameters.paintColor = QColor(0,0,0);
        paintZone->paintNowDetails.parameters.paintWidth = 1;
    }
    else if(tmpString == "fillWithColor")
    {
        paintZone->paintNowDetails.parameters.paintType = fillWithColor;
    }
    else if(tmpString == "textButton")
    {
        paintZone->paintNowDetails.parameters.paintType = text;
    }
    else if(tmpString == "eraserButton")
    {
        paintZone->paintNowDetails.parameters.paintType = eraser;                   //每次点击橡皮图标时，重复设置此参数
        paintZone->paintNowDetails.parameters.paintColor = QColor(255,255,255);
        paintZone->paintNowDetails.parameters.paintWidth = 6;
    }
    else if(tmpString == "colorSelectButton")
    {
        paintZone->paintNowDetails.parameters.paintType = colorSelect;
    }
    else if(tmpString == "magnifierButton")
    {
        paintZone->paintNowDetails.parameters.paintType = magnifier;
    }
}

void paint_QT::shapesButtonClicked(int tmpNum)
{
    paintZone->paintNowDetails.parameters.paintType = paintTypeEnum(tmpNum + 7);    //根据形状号码，为其设置对应枚举值
}

void paint_QT::penwidthButtonClicked(int tmpWid)
{
    paintZone->paintNowDetails.parameters.paintWidth = tmpWid;                      //根据信号传递值，修改画笔参数
}
