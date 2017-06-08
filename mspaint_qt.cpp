#include "mspaint_qt.h"
#include "mypainterwidget.h"
#include "maincontrolpanel.h"
#include "ui_mspaint_qt.h"

mspaint_QT::mspaint_QT(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mspaint_QT)
{
    ui->setupUi(this);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    MyPainterWidget *paintZone = new MyPainterWidget(this);
    mainControlPanel *topControlPanel = new mainControlPanel(this);
    topControlPanel->setAttribute(Qt::WA_LayoutUsesWidgetRect);
    paintZone->setAttribute(Qt::WA_LayoutUsesWidgetRect);
    mainLayout->addWidget(topControlPanel);
    mainLayout->addWidget(paintZone);
    this->setLayout(mainLayout);

}

mspaint_QT::~mspaint_QT()
{
    delete ui;
}
