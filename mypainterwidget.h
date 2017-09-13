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
#include <QPalette>
#include <QColor>

struct myLine                   //存放鼠标轨迹的线段序列
{
    QPoint startPnt;            //起点
    QPoint endPnt;              //终点
};
enum paintTypeEnum              //存放绘制类型参数
{
    pencil=1,                   //1     铅笔
    fillWithColor,              //2     用颜色填充
    text,                       //3     文本
    eraser,                     //4     橡皮擦
    colorSelect,                //5     颜色选取器
    magnifier,                  //6     放大镜
    line,                       //7     直线
    curve,                      //8     曲线
    ellipse,                    //9     椭圆
    rectangle,                  //10    矩形
    roundedRectangle,           //11    圆角矩形
    triangle,                   //12    三角形
    rightAngledTriangle,        //13    直角三角形
    diamond,                    //14    菱形
    pentagon,                   //15    五边形
    hexagon,                    //16    六边形
    arrow,                      //17    箭头
    fourPointedStar,            //18    四角星
    fivePointedStar,            //19    五角星
    sixPointedStar,             //20    六角星
    rectangleDialogBox,         //21    矩形对话框
    roundDialogBox,             //22    圆形对话框
    heart,                      //23    心形
    flash                       //24    闪电
};
struct paintParameters          //存放绘制参数
{
    QColor paintColor;          //绘制颜色
    qint32 paintWidth;          //绘制粗细
    paintTypeEnum paintType;    //绘制类型
};
struct paintDetails
{
    paintParameters parameters; //绘制参数
    QVector<myLine*> paintLines;          //线段序列
};


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

    QPoint startPnt;            //起点
    QPoint endPnt;              //终点
    bool isPressed;             //鼠标是否按下

    paintParameters parametersTemp;     //暂时存放本次拖动使用的参数
    QVector<myLine*> linesTemp;         //暂时存放本次拖动形成的线段
    QVector<paintDetails*> currentPaintDetails; //本次程序绘制的所有图案

    void paintType_pencil(QPainter *painterTemp);
};

#endif // MYPAINTERWIDGET_H
