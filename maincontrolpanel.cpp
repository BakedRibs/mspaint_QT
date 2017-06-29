#include "maincontrolpanel.h"

mainControlPanel::mainControlPanel(QWidget *parent) : QWidget(parent)
{
    setMinimumSize(1024,100);

    toolsFunctionWidget *toolsFunction = new toolsFunctionWidget(this);
    colorsFunctionWidget *colorsFunction = new colorsFunctionWidget(this);
    splitterFunctionWidget *splitterFunction = new splitterFunctionWidget(this);

    QHBoxLayout *controlPanelLayout = new QHBoxLayout;
    controlPanelLayout->addWidget(toolsFunction);
    controlPanelLayout->addWidget(splitterFunction);
    controlPanelLayout->addWidget(colorsFunction);
    controlPanelLayout->addStretch();

    this->setLayout(controlPanelLayout);
}

mainControlPanel::~mainControlPanel()
{

}

