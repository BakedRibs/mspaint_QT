#include "toolsfunctionwidget.h"

toolsFunctionWidget::toolsFunctionWidget(QWidget *parent) : QWidget(parent)
{
    //存放：铅笔/用颜色填充/文本/橡皮擦/颜色选取器/放大镜 共6项功能的QToolButton
    pencilButton       = new QToolButton(this);    //铅笔
    fillWithColor      = new QToolButton(this);    //用颜色填充
    textButton         = new QToolButton(this);    //文本
    eraserButton       = new QToolButton(this);    //橡皮擦
    colorSelectButton  = new QToolButton(this);    //颜色选取器
    magnifierButton    = new QToolButton(this);    //放大镜

    this->setButtonAlignment(pencilButton       , ":/icons/toolsFunctionWidget/pencil.png");
    this->setButtonAlignment(fillWithColor      , ":/icons/toolsFunctionWidget/fillWithColor.png");
    this->setButtonAlignment(textButton         , ":/icons/toolsFunctionWidget/text.png");
    this->setButtonAlignment(eraserButton       , ":/icons/toolsFunctionWidget/eraser.png");
    this->setButtonAlignment(colorSelectButton  , ":/icons/toolsFunctionWidget/colorSelect.png");
    this->setButtonAlignment(magnifierButton    , ":/icons/toolsFunctionWidget/magnifier.png");

    QGridLayout *toolsLayout = new QGridLayout;
    toolsLayout->addWidget(pencilButton         , 0 , 0 , Qt::AlignCenter);
    toolsLayout->addWidget(fillWithColor        , 0 , 1 , Qt::AlignCenter);
    toolsLayout->addWidget(textButton           , 0 , 2 , Qt::AlignCenter);
    toolsLayout->addWidget(eraserButton         , 1 , 0 , Qt::AlignCenter);
    toolsLayout->addWidget(colorSelectButton    , 1 , 1 , Qt::AlignCenter);
    toolsLayout->addWidget(magnifierButton      , 1 , 2 , Qt::AlignCenter);

    this->setLayout(toolsLayout);
    this->show();
}

toolsFunctionWidget::~toolsFunctionWidget()
{

}
//设置每个QToolButton的icon/iconSize/style等
void toolsFunctionWidget::setButtonAlignment(QToolButton *tmpButton , QString iconPath)
{
    tmpButton->setToolButtonStyle(Qt::ToolButtonIconOnly);  //按钮只显示图片，不显示文字
    tmpButton->setIcon(QIcon(iconPath));                    //设置图标
    tmpButton->setIconSize(QSize(20,20));                   //设置图标大小
}
