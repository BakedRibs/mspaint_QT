#include "splitterfunctionwidget.h"

splitterFunctionWidget::splitterFunctionWidget(QWidget *parent) : QWidget(parent)
{
    this->setAutoFillBackground(true);
    QPalette palette;
    QString picPath = QApplication::applicationDirPath()+"/icons/splitterFunctionWidget/splitter.png";
    QPixmap pixmap(picPath);
    palette.setBrush(QPalette::Window,QBrush(pixmap));  //以图片作为QWidget背景
    this->setPalette(palette);
    this->setFixedSize(9,100);                          //设置QWidget尺寸
    this->show();
}

splitterFunctionWidget::~splitterFunctionWidget()
{

}

