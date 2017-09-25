#ifndef MAINCONTROLPANEL_H
#define MAINCONTROLPANEL_H

#include <QWidget>
#include <QHBoxLayout>
#include "toolsfunctionwidget.h"
#include "shapesfunctionwidget.h"
#include "penwidthfunctionwidget.h"
#include "colorsfunctionwidget.h"
#include "splitterfunctionwidget.h"

class mainControlPanel : public QWidget
{
public:
    mainControlPanel(QWidget *parent);
    ~mainControlPanel();

    toolsFunctionWidget *toolsFunction;         //工具栏窗口
    shapesFunctionWidget *shapesFunction;       //形状栏窗口
    penwidthFunctionWidget *penWidthFunction;   //宽度栏窗口
    colorsFunctionWidget *colorsFunction;       //颜色栏窗口
};

#endif
