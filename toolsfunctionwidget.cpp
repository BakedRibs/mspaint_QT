#include "toolsfunctionwidget.h"

toolsFunctionWidget::toolsFunctionWidget(QWidget *parent) : QWidget(parent)
{
    //存放：铅笔/用颜色填充/文本/橡皮擦/颜色选取器/放大镜 共6项功能的QToolButton
    pencilButton       = new QPushButton(this);    //铅笔
    fillWithColor      = new QPushButton(this);    //用颜色填充
    textButton         = new QPushButton(this);    //文本
    eraserButton       = new QPushButton(this);    //橡皮擦
    colorSelectButton  = new QPushButton(this);    //颜色选取器
    magnifierButton    = new QPushButton(this);    //放大镜

    label = new QLabel(QString::fromUtf8("工具") , this);
    label->setAlignment(Qt::AlignCenter);

    QString picPath = QApplication::applicationDirPath();
    this->setButtonAlignment(pencilButton       , picPath + "/icons/toolsFunctionWidget/pencil.png");
    this->setButtonAlignment(fillWithColor      , picPath + "/icons/toolsFunctionWidget/fillWithColor.png");
    this->setButtonAlignment(textButton         , picPath + "/icons/toolsFunctionWidget/text.png");
    this->setButtonAlignment(eraserButton       , picPath + "/icons/toolsFunctionWidget/eraser.png");
    this->setButtonAlignment(colorSelectButton  , picPath + "/icons/toolsFunctionWidget/colorSelect.png");
    this->setButtonAlignment(magnifierButton    , picPath + "/icons/toolsFunctionWidget/magnifier.png");

    QGridLayout *toolsLayout = new QGridLayout;
    toolsLayout->addWidget(pencilButton         , 0 , 0 , Qt::AlignCenter);     //左上
    toolsLayout->addWidget(fillWithColor        , 0 , 1 , Qt::AlignCenter);
    toolsLayout->addWidget(textButton           , 0 , 2 , Qt::AlignCenter);
    toolsLayout->addWidget(eraserButton         , 1 , 0 , Qt::AlignCenter);
    toolsLayout->addWidget(colorSelectButton    , 1 , 1 , Qt::AlignCenter);
    toolsLayout->addWidget(magnifierButton      , 1 , 2 , Qt::AlignCenter);     //右下
    toolsLayout->addWidget(label                , 2 , 1 , Qt::AlignCenter);     //中间位置，不用调整label的尺寸了

    this->setFixedSize(120,100);
    this->setLayout(toolsLayout);
    this->show();
}

toolsFunctionWidget::~toolsFunctionWidget()
{

}
//设置每个QToolButton的icon/iconSize/style等
void toolsFunctionWidget::setButtonAlignment(QPushButton *tmpButton , QString iconPath)
{
    tmpButton->setIcon(QIcon(iconPath));                    //设置图标
    tmpButton->setIconSize(QSize(20,20));                   //设置图标大小
}
