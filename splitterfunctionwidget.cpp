#include "splitterfunctionwidget.h"

splitterFunctionWidget::splitterFunctionWidget(QWidget *parent) : QWidget(parent)
{
    this->setAutoFillBackground(true);
    QPalette palette;
    QString picPath = QApplication::applicationDirPath()+"/icons/splitterFunctionWidget/splitter.png";
    QPixmap pixmap(picPath);
    palette.setBrush(QPalette::Window,QBrush(pixmap));
    this->setPalette(palette);
    this->setFixedSize(9,100);
    this->show();
}

splitterFunctionWidget::~splitterFunctionWidget()
{

}

