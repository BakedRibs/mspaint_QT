#include "mspaint_qt.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mspaint_QT w;
    w.showMaximized();

    return a.exec();
}
