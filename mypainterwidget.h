#ifndef MYPAINTERWIDGET_H
#define MYPAINTERWIDGET_H

#include <QWidget>
#include <QPoint>
#include <QVector>
#include <QString>
#include <QMessageBox>
#include <QPainter>
#include <QPen>
#include <QMouseEvent>

typedef struct myLine
{
    QPoint startPnt;
    QPoint endPnt;
}myLine;

class MyPainterWidget : public QWidget
{
public:
    MyPainterWidget(QWidget *parent);
    ~MyPainterWidget();

    //继承
    void paintEvent(QPaintEvent *parent);
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

    QPoint startPnt;    //起点
    QPoint endPnt;      //终点
    bool isPressed;     //鼠标是否按下

    QVector<myLine*> lines; //存放所有的线段
};

#endif // MYPAINTERWIDGET_H
