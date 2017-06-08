#include <QApplication>
#include "paint_qt.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    paint_QT paint_qt;
    paint_qt.show();

    return app.exec();
}
