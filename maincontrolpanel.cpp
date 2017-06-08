#include "maincontrolpanel.h"

mainControlPanel::mainControlPanel(QWidget *parent) : QWidget(parent)
{
    setMinimumSize(1024,100);
    QHBoxLayout *controlPanelLayout = new QHBoxLayout;

    toolsFunctionWidget *toolsFunction = new toolsFunctionWidget(this);

    controlPanelLayout->addWidget(toolsFunction);

    this->setLayout(controlPanelLayout);
}

mainControlPanel::~mainControlPanel()
{

}

