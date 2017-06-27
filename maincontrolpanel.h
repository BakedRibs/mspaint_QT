#ifndef MAINCONTROLPANEL_H
#define MAINCONTROLPANEL_H

#include <QWidget>
#include <QHBoxLayout>
#include "toolsfunctionwidget.h"
#include "colorsfunctionwidget.h"

class mainControlPanel : public QWidget
{
public:
    mainControlPanel(QWidget *parent);
    ~mainControlPanel();
};

#endif
