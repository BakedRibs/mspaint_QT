#include "mypainterwidget.h"

MyPainterWidget::MyPainterWidget(QWidget *parent) : QWidget(parent)
{
    setMinimumSize(1024,100);
    //setMaximumSize(480,120);
    this->setMouseTracking(true);
    this->isPressed = false;

    paintNowDetails = new paintDetails();
    paintNowDetails->parameters.paintColor = QColor(0,0,0);      //启动程序后，默认颜色为黑色
    paintNowDetails->parameters.paintWidth = 1;                  //启动程序后，默认画笔粗细为1
    paintNowDetails->parameters.paintType = pencil;              //启动程序后，默认画笔类型为铅笔

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
        this->paintNowDetails->paintLines.push_back(line);

        update();
        startPnt = endPnt;
    }
}

void MyPainterWidget::mouseReleaseEvent(QMouseEvent *e)
{
    setCursor(Qt::ArrowCursor);
    this->isPressed = false;
    this->currentPaintDetails.push_back(paintNowDetails);
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

void MyPainterWidget::switchType(paintDetails *detailsTemp)
{
    switch (detailsTemp->parameters.paintType)
    {
        case pencil:
            paintType_pencil(detailsTemp);
            break;
        default:
            break;
    }
}

void MyPainterWidget::paintType_pencil(paintDetails *detailsTemp)
{
    QPainter *painter = new QPainter(this);
    QPen pen;
    pen.setColor(detailsTemp->parameters.paintColor);
    pen.setWidth(detailsTemp->parameters.paintWidth);
    painter->setPen(pen);

    for(int i=0;i<detailsTemp->paintLines.size();i++)
    {
        myLine *pLine = detailsTemp->paintLines[i];
        painter->drawLine(pLine->startPnt,pLine->endPnt);
    }
}
