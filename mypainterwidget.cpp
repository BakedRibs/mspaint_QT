#include "mypainterwidget.h"

MyPainterWidget::MyPainterWidget(QWidget *parent) : QWidget(parent)
{
    setMinimumSize(1024,100);
    //setMaximumSize(480,120);
    this->setMouseTracking(true);
    this->isPressed = false;

    paintNowDetails.parameters.paintColor = QColor(0,0,0);      //启动程序后，默认颜色为黑色
    paintNowDetails.parameters.paintWidth = 1;                  //启动程序后，默认画笔粗细为1
    paintNowDetails.parameters.paintType = pencil;              //启动程序后，默认画笔类型为铅笔

    this->setAutoFillBackground(true);
    QPalette pal;
    pal.setColor(QPalette::Background,Qt::white);
    this->setPalette(pal);
    this->show();
}

MyPainterWidget::~MyPainterWidget()
{

}

void MyPainterWidget::mousePressEvent(QMouseEvent *e)
{
    setCursor(Qt::PointingHandCursor);
    startPnt = e->pos();
    endPnt = e->pos();
    this->isPressed = true;
}

void MyPainterWidget::mouseMoveEvent(QMouseEvent *e)
{
    if(this->isPressed)
    {
        endPnt = e->pos();

        myLine *line = new myLine;
        line->startPnt = startPnt;
        line->endPnt = endPnt;
        this->paintNowDetails.paintLines.push_back(line);

        update();
        startPnt = endPnt;
    }
}

void MyPainterWidget::mouseReleaseEvent(QMouseEvent *e)
{
    setCursor(Qt::ArrowCursor);
    this->isPressed = false;
    this->currentPaintDetails.push_back(paintNowDetails);
    paintNowDetails.paintLines.clear();
}

void MyPainterWidget::paintEvent(QPaintEvent *p)
{
    if(!currentPaintDetails.isEmpty())
    {
        for(int i=0;i<currentPaintDetails.size();i++)
        {
            switchType(currentPaintDetails.at(i));
        }
    }
    switchType(paintNowDetails);
}

void MyPainterWidget::switchType(paintDetails detailsTemp)
{
    QPainter *painter = new QPainter(this);             //创建Painter
    QPen pen;
    pen.setColor(detailsTemp.parameters.paintColor);    //为Pen设置颜色
    pen.setWidth(detailsTemp.parameters.paintWidth);    //为Pen设置宽度
    painter->setPen(pen);                               //为Painter设置Pen，将Painter传递给函数

    switch (detailsTemp.parameters.paintType)
    {
        case pencil:
            paintType_pencil(detailsTemp,painter);      //所选为铅笔时，画图函数
            break;
        case eraser:
            paintType_eraser(detailsTemp,painter);      //所选为橡皮时，画图函数
            break;
        case line:
            paintType_line(detailsTemp,painter);        //所选为直线时，画图函数
            break;
        default:
            break;
    }
}

void MyPainterWidget::paintType_pencil(paintDetails detailsTemp,QPainter *painter)  //0_pencil
{
    for(int i=0;i<detailsTemp.paintLines.size();i++)        //对paintLines中的每一条线段画线
    {
        myLine *pLine = detailsTemp.paintLines[i];
        painter->drawLine(pLine->startPnt,pLine->endPnt);   //每一条线段的起点和终点
    }
}

void MyPainterWidget::paintType_eraser(paintDetails detailsTemp, QPainter *painter) //4_eraser
{
    for(int i=0;i<detailsTemp.paintLines.size();i++)        //对paintLines中的每一条线段画线
    {
        myLine *pLine = detailsTemp.paintLines[i];
        painter->drawLine(pLine->startPnt,pLine->endPnt);   //每一条线段的起点和终点
    }
}

void MyPainterWidget::paintType_line(paintDetails detailsTemp, QPainter *painter)   //7_line
{
    if(!detailsTemp.paintLines.isEmpty())                   //非空时进入，防止调用空vector产生崩溃
    {
        int i = detailsTemp.paintLines.size();              //找出paintLines中最后一条线段
        painter->drawLine(detailsTemp.paintLines[0]->startPnt,detailsTemp.paintLines[i-1]->endPnt);     //paintLines中有多条线段，取第一条起点和最后一条终点画直线
    }
}
