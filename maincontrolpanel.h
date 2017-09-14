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

    colorsFunctionWidget *colorsFunction;
};

#endif
