#ifndef SHAPESFUNCTIONWIDGET_H
#define SHAPESFUNCTIONWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QApplication>
#include <QLabel>

class shapesFunctionWidget : public QWidget
{
public:
    shapesFunctionWidget(QWidget *parent);
    ~shapesFunctionWidget();

    QPushButton *shapesButtonList[18];
    QLabel *label;

    void shapesButtonsInit();
};

#endif // SHAPESFUNCTIONWIDGET_H
