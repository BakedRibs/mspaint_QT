#include "mypainterwidget.h"

MyPainterWidget::MyPainterWidget(QWidget *parent) : QWidget(parent)
{
    setMinimumSize(1024,100);
    //setMaximumSize(480,120);
    this->setMouseTracking(true);
    this->isPressed = false;

    parametersTemp.paintColor = QColor(0,0,0);      //启动程序后，默认颜色为黑色
    parametersTemp.paintWidth = 1;                  //启动程序后，默认画笔粗细为1
    parametersTemp.paintType = pencil;                   //启动程序后，默认画笔类型为铅笔

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
        this->linesTemp.push_back(line);

        update();
        startPnt = endPnt;
    }
}

void MyPainterWidget::mouseReleaseEvent(QMouseEvent *e)
{
    setCursor(Qt::ArrowCursor);
    this->isPressed = false;

    paintDetails *detailsTemp = new paintDetails;
    detailsTemp->parameters = parametersTemp;
    detailsTemp->paintLines = linesTemp;
    this->currentPaintDetails.push_back(detailsTemp);
}

void MyPainterWidget::paintEvent(QPaintEvent *p)
{
    QPainter *painter = new QPainter(this);
    QPen pen;
    pen.setColor(parametersTemp.paintColor);
    pen.setWidth(parametersTemp.paintWidth);
    painter->setPen(pen);

    switch (parametersTemp.paintType)
    {
        case pencil:
            paintType_pencil(painter);
            break;
        default:
            break;
    }
}

void MyPainterWidget::paintType_pencil(QPainter *painterTemp)
{
    for(int i=0;i<linesTemp.size();i++)
    {
        myLine *pLine = linesTemp[i];
        painterTemp->drawLine(pLine->startPnt,pLine->endPnt);
    }
}
