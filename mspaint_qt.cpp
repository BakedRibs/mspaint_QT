#include "mspaint_qt.h"
#include "mypainterwidget.h"
#include "ui_mspaint_qt.h"

mspaint_QT::mspaint_QT(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mspaint_QT)
{
    ui->setupUi(this);

    QGridLayout *mainLayout = new QGridLayout;
    MyPainterWidget *paintZone = new MyPainterWidget(this);
    mainLayout->addWidget(paintZone);
    this->setLayout(mainLayout);
}

mspaint_QT::~mspaint_QT()
{
    delete ui;
}
