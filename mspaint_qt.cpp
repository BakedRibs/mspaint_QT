#include "mspaint_qt.h"
#include "mypainterwidget.h"
#include "maincontrolpanel.h"
#include "ui_mspaint_qt.h"

mspaint_QT::mspaint_QT(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mspaint_QT)
{
    ui->setupUi(this);

    QGridLayout *mainLayout = new QGridLayout;
    MyPainterWidget *paintZone = new MyPainterWidget(this);
    mainControlPanel *topControlPanel = new mainControlPanel(this);
    mainLayout->addWidget(topControlPanel,0,0);
    mainLayout->addWidget(paintZone,1,0);
    this->setLayout(mainLayout);
}

mspaint_QT::~mspaint_QT()
{
    delete ui;
}
