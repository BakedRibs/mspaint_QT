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
            paintType_pencil(detailsTemp,painter);      //1所选为铅笔时，画图函数
            break;
        case eraser:
            paintType_eraser(detailsTemp,painter);      //4所选为橡皮时，画图函数
            break;
        case line:
            paintType_line(detailsTemp,painter);        //7所选为直线时，画图函数
            break;
        case curve:
            paintType_curve(detailsTemp,painter);       //8所选为曲线时，画图函数
            break;
        case ellipse:
            paintType_ellipse(detailsTemp,painter);     //9所选为椭圆时，画图函数
            break;
        case rectangle:
            paintType_rectangle(detailsTemp,painter);   //10所选为矩形时，画图函数
            break;
        case roundedRectangle:
            paintType_roundedRect(detailsTemp,painter); //11所选为圆角矩形时，画图函数
            break;
        case triangle:
            paintType_triangle(detailsTemp,painter);    //12所选为三角形时，画图函数
            break;
        case rightAngledTriangle:
            paintType_rightTri(detailsTemp,painter);    //13所选为直角三角形时，画图函数
            break;
        case diamond:
            paintType_diamond(detailsTemp,painter);     //14所选为菱形时，画图函数
            break;
        case pentagon:
            paintType_pentagon(detailsTemp,painter);    //15所选为五边形时，画图函数
            break;
        case hexagon:
            paintType_hexagon(detailsTemp,painter);     //16所选为六边形时，画图函数
            break;
        case arrow:
            paintType_arrow(detailsTemp,painter);       //17所选为箭头时，画图函数
            break;
        case fourPointedStar:
            paintType_4pStar(detailsTemp,painter);      //18所选为四角星时，画图函数
            break;
        default:
            break;
    }
}

void MyPainterWidget::paintType_pencil(paintDetails detailsTemp,QPainter *painter)      //0_pencil
{
    if(!detailsTemp.paintLines.isEmpty())                   //非空时进入，防止调用空vector产生崩溃
    {
        for(int i=0;i<detailsTemp.paintLines.size();i++)        //对paintLines中的每一条线段画线
        {
            myLine *pLine = detailsTemp.paintLines[i];
            painter->drawLine(pLine->startPnt,pLine->endPnt);   //每一条线段的起点和终点
        }
    }
}

void MyPainterWidget::paintType_eraser(paintDetails detailsTemp, QPainter *painter)     //4_eraser
{
    if(!detailsTemp.paintLines.isEmpty())                   //非空时进入，防止调用空vector产生崩溃
    {
        for(int i=0;i<detailsTemp.paintLines.size();i++)        //对paintLines中的每一条线段画线
        {
            myLine *pLine = detailsTemp.paintLines[i];
            painter->drawLine(pLine->startPnt,pLine->endPnt);   //每一条线段的起点和终点
        }
    }
}

void MyPainterWidget::paintType_line(paintDetails detailsTemp, QPainter *painter)       //7_line
{
    if(!detailsTemp.paintLines.isEmpty())                   //非空时进入，防止调用空vector产生崩溃
    {
        int i = detailsTemp.paintLines.size();              //找出paintLines中最后一条线段
        painter->drawLine(detailsTemp.paintLines[0]->startPnt,detailsTemp.paintLines[i-1]->endPnt);     //paintLines中有多条线段，取第一条起点和最后一条终点画直线
    }
}

void MyPainterWidget::paintType_curve(paintDetails detailsTemp, QPainter *painter)      //8_curve
{
    if(!detailsTemp.paintLines.isEmpty())                   //非空时进入，防止调用空vector产生崩溃
    {
        int i = detailsTemp.paintLines.size();              //找出paintLines中最后一条线段
        QRectF rectTmp(detailsTemp.paintLines[0]->startPnt,detailsTemp.paintLines[i-1]->endPnt);        //先用左上和右下两点生成矩形
        painter->drawArc(rectTmp,30*16,120*16);             //将矩形和角度传递给painter
    }
}

void MyPainterWidget::paintType_ellipse(paintDetails detailsTemp, QPainter *painter)    //9_ellipse
{
    if(!detailsTemp.paintLines.isEmpty())                   //非空时进入，防止调用空vector产生崩溃
    {
        int i = detailsTemp.paintLines.size();              //找出paintLines中最后一条线段
        QRectF rectTmp(detailsTemp.paintLines[0]->startPnt,detailsTemp.paintLines[i-1]->endPnt);        //先用左上和右下两点生成矩形
        painter->drawEllipse(rectTmp);                      //将矩形传递给painter，可以绘制出椭圆
    }
}

void MyPainterWidget::paintType_rectangle(paintDetails detailsTemp, QPainter *painter)  //10_rectangle
{
    if(!detailsTemp.paintLines.isEmpty())                   //非空时进入，防止调用空vector产生崩溃
    {
        int i = detailsTemp.paintLines.size();              //找出paintLines中最后一条线段
        QRectF rectTmp(detailsTemp.paintLines[0]->startPnt,detailsTemp.paintLines[i-1]->endPnt);        //先用左上和右下两点生成矩形
        painter->drawRect(rectTmp);                         //将矩形传递给painter，绘制图像
    }
}

void MyPainterWidget::paintType_roundedRect(paintDetails detailsTemp, QPainter *painter)//11_roundedRectangle
{
    if(!detailsTemp.paintLines.isEmpty())                   //非空时进入，防止调用空vector产生崩溃
    {
        int i = detailsTemp.paintLines.size();              //找出paintLines中最后一条线段
        QRectF rectTmp(detailsTemp.paintLines[0]->startPnt,detailsTemp.paintLines[i-1]->endPnt);        //先用左上和右下两点生成矩形
        painter->drawRoundedRect(rectTmp,15.0,25.0,Qt::RelativeSize);               //将矩形传递给painter，绘制出圆角矩形
    }
}

void MyPainterWidget::paintType_triangle(paintDetails detailsTemp, QPainter *painter)   //12_triangle
{
    if(!detailsTemp.paintLines.isEmpty())                   //非空时进入，防止调用空vector产生崩溃
    {
        int i = detailsTemp.paintLines.size();              //找出paintLines中最后一条线段
        double x_left_top = detailsTemp.paintLines[0]->startPnt.x();                //左上角点
        double y_left_top = detailsTemp.paintLines[0]->startPnt.y();
        double x_right_bottom = detailsTemp.paintLines[i-1]->endPnt.x();            //右下角点
        double y_right_bottom = detailsTemp.paintLines[i-1]->endPnt.y();
        QPointF points[3] = {QPointF((x_left_top+x_right_bottom)/2,y_left_top),     //等腰三角形顶角
                             QPointF(x_left_top,y_right_bottom),                    //等腰三角形底角
                             QPointF(x_right_bottom,y_right_bottom)};               //等腰三角形底角
        painter->drawPolygon(points,3);                     //采用绘制多边形功能，将三个点传递给painter，绘制图像
    }
}

void MyPainterWidget::paintType_rightTri(paintDetails detailsTemp, QPainter *painter)   //13_rightAngledTriangle
{
    if(!detailsTemp.paintLines.isEmpty())                   //非空时进入，防止调用空vector产生崩溃
    {
        int i = detailsTemp.paintLines.size();              //找出paintLines中最后一条线段
        double x_left_top = detailsTemp.paintLines[0]->startPnt.x();                //左上角点
        double y_left_top = detailsTemp.paintLines[0]->startPnt.y();
        double x_right_bottom = detailsTemp.paintLines[i-1]->endPnt.x();            //右下角点
        double y_right_bottom = detailsTemp.paintLines[i-1]->endPnt.y();
        QPointF points[3] = {QPointF(x_left_top,y_left_top),                        //直角三角形顶角
                             QPointF(x_left_top,y_right_bottom),                    //直角三角形直角
                             QPointF(x_right_bottom,y_right_bottom)};               //直角三角形底角
        painter->drawPolygon(points,3);                     //采用绘制多边形功能，将三个点传递给painter，绘制图像
    }
}

void MyPainterWidget::paintType_diamond(paintDetails detailsTemp, QPainter *painter)    //14_diamond
{
    if(!detailsTemp.paintLines.isEmpty())
    {
        int i = detailsTemp.paintLines.size();              //找出paintLines中最后一条线段
        double x_left_top = detailsTemp.paintLines[0]->startPnt.x();                    //左上角点
        double y_left_top = detailsTemp.paintLines[0]->startPnt.y();
        double x_right_bottom = detailsTemp.paintLines[i-1]->endPnt.x();                //右下角点
        double y_right_bottom = detailsTemp.paintLines[i-1]->endPnt.y();
        QPointF points[4] = {QPointF((x_left_top+x_right_bottom)/2,y_left_top),         //顶
                             QPointF(x_right_bottom,(y_left_top+y_right_bottom)/2),     //右
                             QPointF((x_left_top+x_right_bottom)/2,y_right_bottom),     //底
                             QPointF(x_left_top,(y_left_top+y_right_bottom)/2)};        //左
        painter->drawPolygon(points,4);                     //采用绘制多边形功能，将四个点传递给painter，绘制图像
    }
}

void MyPainterWidget::paintType_pentagon(paintDetails detailsTemp, QPainter *painter)   //15_pentagon
{
    if(!detailsTemp.paintLines.isEmpty())                   //非空时进入，防止调用空vector产生崩溃
    {
        int i = detailsTemp.paintLines.size();              //找出paintLines中最后一条线段
        double x_left_top = detailsTemp.paintLines[0]->startPnt.x();                //左上角点
        double y_left_top = detailsTemp.paintLines[0]->startPnt.y();
        double x_right_bottom = detailsTemp.paintLines[i-1]->endPnt.x();            //右下角点
        double y_right_bottom = detailsTemp.paintLines[i-1]->endPnt.y();
        double widthQ = x_right_bottom - x_left_top;                                //宽度
        double heightQ = y_right_bottom - y_left_top;                               //高度
        double ratioA = sin(3.1415926 * 36 / 180)/(sin(2.1415926 * 36 / 180) + sin(3.1415926 * 72 / 180));  //长度比例
        double ratioB = cos(3.1415926 * 72 / 180)/(1 + 2 * cos(3.1415926 * 72 / 180));                      //长度比例
        double widthPlus = widthQ * ratioB;
        double heightPlus = heightQ * ratioA;
        QPointF points[5] = {QPointF((x_left_top+x_right_bottom)/2,y_left_top),     //a
                             QPointF(x_right_bottom,y_left_top+heightPlus),         //b
                             QPointF(x_right_bottom-widthPlus,y_right_bottom),      //c
                             QPointF(x_left_top+widthPlus,y_right_bottom),          //d
                             QPointF(x_left_top,y_left_top+heightPlus)};            //e
        painter->drawPolygon(points,5);                     //采用绘制多边形功能，将五个点传递给painter，绘制图像
    }
}

void MyPainterWidget::paintType_hexagon(paintDetails detailsTemp, QPainter *painter)    //16_hexagon
{
    if(!detailsTemp.paintLines.isEmpty())                   //非空时进入，防止调用空vector产生崩溃
    {
        int i = detailsTemp.paintLines.size();              //找出paintLines中最后一条线段
        double x_left_top = detailsTemp.paintLines[0]->startPnt.x();                //左上角点
        double y_left_top = detailsTemp.paintLines[0]->startPnt.y();
        double x_right_bottom = detailsTemp.paintLines[i-1]->endPnt.x();            //右下角点
        double y_right_bottom = detailsTemp.paintLines[i-1]->endPnt.y();
        double widthQ = x_right_bottom - x_left_top;                                //宽度
        QPointF points[6] = {QPointF(x_left_top,(y_left_top+y_right_bottom)/2),     //a
                             QPointF(x_left_top+widthQ/4,y_left_top),               //b
                             QPointF(x_right_bottom-widthQ/4,y_left_top),           //c
                             QPointF(x_right_bottom,(y_left_top+y_right_bottom)/2), //c
                             QPointF(x_right_bottom-widthQ/4,y_right_bottom),       //d
                             QPointF(x_left_top+widthQ/4,y_right_bottom)};          //e
        painter->drawPolygon(points,6);                     //采用绘制多边形功能，将六个点传递给painter，绘制图像
    }
}

void MyPainterWidget::paintType_arrow(paintDetails detailsTemp, QPainter *painter)      //17_arrow
{
    if(!detailsTemp.paintLines.isEmpty())                   //非空时进入，防止调用空vector产生崩溃
    {
        int i = detailsTemp.paintLines.size();              //找出paintLines中最后一条线段
        double x_left_top = detailsTemp.paintLines[0]->startPnt.x();                //左上角点
        double y_left_top = detailsTemp.paintLines[0]->startPnt.y();
        double x_right_bottom = detailsTemp.paintLines[i-1]->endPnt.x();            //右下角点
        double y_right_bottom = detailsTemp.paintLines[i-1]->endPnt.y();
        double widthQ = x_right_bottom - x_left_top;                                //宽度
        QPointF points[4] = {QPointF(x_left_top,(y_left_top+y_right_bottom)/2),     //a
                             QPointF(x_right_bottom,(y_left_top+y_right_bottom)/2), //b
                             QPointF(x_right_bottom-widthQ/8,y_left_top),           //c
                             QPointF(x_right_bottom-widthQ/8,y_right_bottom)};      //d
        painter->drawLine(points[0],points[1]);             //绘制标示箭头的三条线
        painter->drawLine(points[2],points[1]);
        painter->drawLine(points[3],points[1]);
    }
}

void MyPainterWidget::paintType_4pStar(paintDetails detailsTemp, QPainter *painter)     //18_fourPointedStar
{
    if(!detailsTemp.paintLines.isEmpty())                   //非空时进入，防止调用空vector产生崩溃
    {
        int i = detailsTemp.paintLines.size();              //找出paintLines中最后一条线段
        double x_left_top = detailsTemp.paintLines[0]->startPnt.x();                //左上角点
        double y_left_top = detailsTemp.paintLines[0]->startPnt.y();
        double x_right_bottom = detailsTemp.paintLines[i-1]->endPnt.x();            //右下角点
        double y_right_bottom = detailsTemp.paintLines[i-1]->endPnt.y();
        double widthQ = x_right_bottom - x_left_top;                                //宽度
        double heightQ = y_right_bottom - y_left_top;                               //高度
        QPointF points[8] = {QPointF(x_left_top+widthQ/2,y_left_top),     //a
                             QPointF(x_left_top+widthQ*5/8,y_left_top+heightQ*3/8), //b
                             QPointF(x_right_bottom,y_left_top+heightQ/2),          //c
                             QPointF(x_left_top+widthQ*5/8,y_left_top+heightQ*5/8), //d
                             QPointF(x_left_top+widthQ/2,y_right_bottom),           //e
                             QPointF(x_left_top+widthQ*3/8,y_left_top+heightQ*5/8), //f
                             QPointF(x_left_top,y_left_top+heightQ/2),              //g
                             QPointF(x_left_top+widthQ*3/8,y_left_top+heightQ*3/8)};//h
        painter->drawPolygon(points,8);                     //采用绘制多边形功能，将八个点传递给painter，绘制图像
    }
}
