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

    QVBoxLayout *mainLayout;
    MyPainterWidget *paintZone;
    mainControlPanel *topControlPanel;

public slots:
    void colorButtonClicked(QColor* tmpColor);
    void toolsButtonClicked(QString tmpString);
    void shapesButtonClicked(int tmpNum);
    void penwidthButtonClicked(int tmpWid);

private:
};

#endif
