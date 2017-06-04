#include "mypainterwidget.h"

MyPainterWidget::MyPainterWidget(QWidget *parent) : QWidget(parent)
{
    setMinimumSize(240,120);
    setMaximumSize(480,120);
    this->setMouseTracking(true);
    this->isPressed = false;
}

MyPainterWidget::~MyPainterWidget()
{

}

void MyPainterWidget::paintEvent(QPaintEvent *p)
{
    QPainter painter(this);
    QPen pen;
    pen.setColor(Qt::black);
    pen.setWidth(5);
    painter.setPen(pen);

    for(int i=0;i<lines.size();i++)
    {
        myLine *pLine = lines[i];
        painter.drawLine(pLine->startPnt,pLine->endPnt);
    }
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
        this->lines.push_back(line);

        update();
        startPnt = endPnt;
    }
}

void MyPainterWidget::mouseReleaseEvent(QMouseEvent *e)
{
    setCursor(Qt::ArrowCursor);
    this->isPressed = false;
}
