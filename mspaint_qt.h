#ifndef MSPAINT_QT_H
#define MSPAINT_QT_H

#include <QMainWindow>

namespace Ui {
class mspaint_QT;
}

class mspaint_QT : public QMainWindow
{
    Q_OBJECT

public:
    explicit mspaint_QT(QWidget *parent = 0);
    ~mspaint_QT();

private:
    Ui::mspaint_QT *ui;
};

#endif // MSPAINT_QT_H
