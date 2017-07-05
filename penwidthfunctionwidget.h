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

    QSpinBox *penWidthSpinBox;
    QLabel *label;
};

#endif // PENWIDTHFUNCTIONWIDGET_H
