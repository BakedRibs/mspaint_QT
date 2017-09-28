#include "maincontrolpanel.h"

mainControlPanel::mainControlPanel(QWidget *parent) : QWidget(parent)
{
    setMinimumSize(1024,100);

    toolsFunction = new toolsFunctionWidget(this);          //不在此处定义，而是在类中定义
    shapesFunction = new shapesFunctionWidget(this);        //不在此处定义，而是在类中定义
    penWidthFunction = new penwidthFunctionWidget(this);    //不在此处定义，而是在类中定义
    colorsFunction = new colorsFunctionWidget(this);        //不在此处定义，而是在类中定义

    splitterFunctionWidget *splitterFunction1 = new splitterFunctionWidget(this);
    splitterFunctionWidget *splitterFunction2 = new splitterFunctionWidget(this);
    splitterFunctionWidget *splitterFunction3 = new splitterFunctionWidget(this);
    splitterFunctionWidget *splitterFunction4 = new splitterFunctionWidget(this);

    QHBoxLayout *controlPanelLayout = new QHBoxLayout;
    controlPanelLayout->addWidget(toolsFunction);
    controlPanelLayout->addWidget(splitterFunction1);
    controlPanelLayout->addWidget(shapesFunction);
    controlPanelLayout->addWidget(splitterFunction2);
    controlPanelLayout->addWidget(penWidthFunction);
    controlPanelLayout->addWidget(splitterFunction3);
    controlPanelLayout->addWidget(colorsFunction);
    controlPanelLayout->addWidget(splitterFunction4);
    controlPanelLayout->addStretch();

    this->setLayout(controlPanelLayout);
}

mainControlPanel::~mainControlPanel()
{

}

