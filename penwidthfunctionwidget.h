#ifndef PENWIDTHFUNCTIONWIDGET_H
#define PENWIDTHFUNCTIONWIDGET_H

#include <QWidget>
#include <QSpinBox>
#include <QLabel>
#include <QVBoxLayout>

class penwidthFunctionWidget : public QWidget
{
public:
    penwidthFunctionWidget(QWidget *parent);
    ~penwidthFunctionWidget();

    QSpinBox *penWidthSpinBox;  //设置画笔宽度
    QLabel *label;
};

#endif // PENWIDTHFUNCTIONWIDGET_H
