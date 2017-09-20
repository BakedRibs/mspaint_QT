#ifndef PENWIDTHFUNCTIONWIDGET_H
#define PENWIDTHFUNCTIONWIDGET_H

#include <QWidget>
#include <QSpinBox>
#include <QLabel>
#include <QVBoxLayout>

class penwidthFunctionWidget : public QWidget
{
    Q_OBJECT        //注意：若包含自定义SIGNAL或SLOT，则需包含此行

public:
    penwidthFunctionWidget(QWidget *parent);
    ~penwidthFunctionWidget();

    QSpinBox *penWidthSpinBox;  //设置画笔宽度
    QLabel *label;

public slots:
    void penWidthClicked(int value);

signals:
    void penWidthChanged(int changedValue);
};

#endif // PENWIDTHFUNCTIONWIDGET_H
