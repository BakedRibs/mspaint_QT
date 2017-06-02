#include "mspaint_qt.h"
#include "ui_mspaint_qt.h"

mspaint_QT::mspaint_QT(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mspaint_QT)
{
    ui->setupUi(this);
}

mspaint_QT::~mspaint_QT()
{
    delete ui;
}
