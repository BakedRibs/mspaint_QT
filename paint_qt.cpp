#include <QtGui>
#include "paint_qt.h"

paint_QT::paint_QT()
{
    QVBoxLayout *mainLayout = new QVBoxLayout;
    MyPainterWidget *paintZone = new MyPainterWidget(this);
    mainControlPanel *topControlPanel = new mainControlPanel(this);

    mainLayout->addWidget(topControlPanel);
    mainLayout->addWidget(paintZone);

    setLayout(mainLayout);

}
