#include "penwidthfunctionwidget.h"

penwidthFunctionWidget::penwidthFunctionWidget(QWidget *parent) : QWidget(parent)
{
    penWidthSpinBox = new QSpinBox(this);
    penWidthSpinBox->setMinimum(1);
    penWidthSpinBox->setMaximum(10);
    penWidthSpinBox->setSingleStep(1);
    penWidthSpinBox->setWrapping(true);
    penWidthSpinBox->setFixedSize(52,40);

    label = new QLabel(QString::fromUtf8("粗细") , this);
    label->setAlignment(Qt::AlignCenter);

    QVBoxLayout *penWidthLayout = new QVBoxLayout;
    penWidthLayout->addWidget(penWidthSpinBox,Qt::AlignCenter);
    penWidthLayout->addWidget(label,Qt::AlignCenter);

    this->setFixedHeight(100);
    this->setLayout(penWidthLayout);
    this->show();
}

penwidthFunctionWidget::~penwidthFunctionWidget()
{

}

