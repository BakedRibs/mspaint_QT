#include <QtGui>
#include "paint_qt.h"

paint_QT::paint_QT()
{
    mainLayout = new QVBoxLayout;
    paintZone = new MyPainterWidget(this);
    topControlPanel = new mainControlPanel(this);

    mainLayout->addWidget(topControlPanel);
    mainLayout->addWidget(paintZone);

    setLayout(mainLayout);

    connect(topControlPanel->colorsFunction,SIGNAL(colorButtonClicked(QColor*)),this,SLOT(colorButtonClicked(QColor*)));
    connect(topControlPanel->toolsFunction,SIGNAL(whichButtonClicked(QString)),this,SLOT(toolsButtonClicked(QString)));
    connect(topControlPanel->shapesFunction,SIGNAL(whichButtonClicked(int)),this,SLOT(penwidthButtonClicked(int)));
    connect(topControlPanel->penWidthFunction,SIGNAL(penWidthChanged(int)),this,SLOT(penwidthButtonClicked(int)));
}

paint_QT::~paint_QT()
{

}

void paint_QT::colorButtonClicked(QColor* tmpColor)
{
    paintZone->paintNowDetails.parameters.paintColor = *tmpColor;
}

void paint_QT::toolsButtonClicked(QString tmpString)
{
    if(tmpString == "pencilButton")
    {
        paintZone->paintNowDetails.parameters.paintType = pencil;
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
        paintZone->paintNowDetails.parameters.paintType = eraser;
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
    paintZone->paintNowDetails.parameters.paintType = paintTypeEnum(tmpNum + 7);
}

void paint_QT::penwidthButtonClicked(int tmpWid)
{
    paintZone->paintNowDetails.parameters.paintWidth = tmpWid;
}
