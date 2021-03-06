#ifndef PAINT_QT_H
#define PAINT_QT_H

#include <QDialog>
#include "maincontrolpanel.h"
#include "mypainterwidget.h"

class paint_QT : public QDialog
{
    Q_OBJECT                            //若包含自定义SIGNAL或SLOT，需包含此项

public:
    paint_QT();
    ~paint_QT();

    QVBoxLayout *mainLayout;
    MyPainterWidget *paintZone;         //画图区域
    mainControlPanel *topControlPanel;  //控制区域

public slots:
    void colorButtonClicked(QColor* tmpColor);      //收到颜色区域信号
    void toolsButtonClicked(QString tmpString);     //收到工具区域信号
    void shapesButtonClicked(int tmpNum);           //收到形状区域信号
    void penwidthButtonClicked(int tmpWid);         //收到宽度区域信号

};

#endif
