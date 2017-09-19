#include "penwidthfunctionwidget.h"

penwidthFunctionWidget::penwidthFunctionWidget(QWidget *parent) : QWidget(parent)
{
    penWidthSpinBox = new QSpinBox(this);
    penWidthSpinBox->setMinimum(1);         //最小宽度1像素
    penWidthSpinBox->setMaximum(10);        //最大宽度2像素
    penWidthSpinBox->setSingleStep(1);      //每次增加1像素
    penWidthSpinBox->setWrapping(true);     //超出范围回卷
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

void penwidthFunctionWidget::penWidthChanged()
{

}
