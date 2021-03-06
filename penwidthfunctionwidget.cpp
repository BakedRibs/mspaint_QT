#include "penwidthfunctionwidget.h"

penwidthFunctionWidget::penwidthFunctionWidget(QWidget *parent) : QWidget(parent)
{
    penWidthSpinBox = new QSpinBox(this);
    penWidthSpinBox->setMinimum(1);                         //最小宽度1像素
    penWidthSpinBox->setMaximum(10);                        //最大宽度2像素
    penWidthSpinBox->setSingleStep(1);                      //每次增加1像素
    penWidthSpinBox->setWrapping(true);                     //超出范围回卷
    penWidthSpinBox->setFixedSize(52,40);                   //固定尺寸
    penWidthSpinBox->setFocusPolicy(Qt::NoFocus);           //SpinBox中的数字可以选定，不可修改

    label = new QLabel(QString::fromUtf8("粗细") , this);
    label->setAlignment(Qt::AlignCenter);

    QVBoxLayout *penWidthLayout = new QVBoxLayout;
    penWidthLayout->addWidget(penWidthSpinBox,Qt::AlignCenter);
    penWidthLayout->addWidget(label,Qt::AlignCenter);

    this->setFixedHeight(100);
    this->setLayout(penWidthLayout);
    this->show();

    connect(penWidthSpinBox,SIGNAL(valueChanged(int)),this,SLOT(penWidthClicked(int)));     //在SpinBox值变化时，调用SLOT
}

penwidthFunctionWidget::~penwidthFunctionWidget()
{

}

void penwidthFunctionWidget::penWidthClicked(int value)
{
    emit penWidthChanged(value);                            //发出信号，传递修改后的宽度值
}

