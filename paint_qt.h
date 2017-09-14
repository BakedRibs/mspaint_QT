#ifndef PAINT_QT_H
#define PAINT_QT_H

#include <QDialog>
#include "maincontrolpanel.h"
#include "mypainterwidget.h"

class paint_QT : public QDialog
{
    Q_OBJECT

public:
    paint_QT();
    ~paint_QT();

public slots:
    void colorButtonClicked();

private:
};

#endif
