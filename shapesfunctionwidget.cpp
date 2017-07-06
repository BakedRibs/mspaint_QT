#include "shapesfunctionwidget.h"

shapesFunctionWidget::shapesFunctionWidget(QWidget *parent) : QWidget(parent)
{
    shapesButtonsInit();
    QGridLayout *shapesButtonsLayout = new QGridLayout;     //形状按钮布局，存放18个形状按钮
    shapesButtonsLayout->setSpacing(2);                     //设置按钮之间间隔为2像素
    for(int i=0;i<18;i++)
    {
        if(i<6)
        {
            shapesButtonsLayout->addWidget(shapesButtonList[i],0,i);        //第一行6个
        }
        else if(i<12)
        {
            shapesButtonsLayout->addWidget(shapesButtonList[i],1,i-6);      //第二行6个
        }
        else
        {
            shapesButtonsLayout->addWidget(shapesButtonList[i],2,i-12);     //第三行6个
        }
    }

    QHBoxLayout *horizontalLayout = new QHBoxLayout;        //水平总体布局
    horizontalLayout->addLayout(shapesButtonsLayout);

    QVBoxLayout *mainLayout = new QVBoxLayout;              //垂直总体布局
    mainLayout->addLayout(horizontalLayout);
    mainLayout->addWidget(label);

    this->setLayout(mainLayout);
    this->show();
}

shapesFunctionWidget::~shapesFunctionWidget()
{

}

void shapesFunctionWidget::shapesButtonsInit()
{
    for(int i=0;i<18;i++)
    {
        shapesButtonList[i] = new QPushButton(this);
        shapesButtonList[i]->setIconSize(QSize(16,16));
        shapesButtonList[i]->setFixedSize(QSize(22,22));
    }
    shapesButtonList[ 0]->setIcon(QIcon(QApplication::applicationDirPath()+"/icons/shapesFunctionWidget/line.png"));
    shapesButtonList[ 1]->setIcon(QIcon(QApplication::applicationDirPath()+"/icons/shapesFunctionWidget/curve.png"));
    shapesButtonList[ 2]->setIcon(QIcon(QApplication::applicationDirPath()+"/icons/shapesFunctionWidget/ellipse.png"));
    shapesButtonList[ 3]->setIcon(QIcon(QApplication::applicationDirPath()+"/icons/shapesFunctionWidget/rectangle.png"));
    shapesButtonList[ 4]->setIcon(QIcon(QApplication::applicationDirPath()+"/icons/shapesFunctionWidget/roundedRectangle.png"));
    shapesButtonList[ 5]->setIcon(QIcon(QApplication::applicationDirPath()+"/icons/shapesFunctionWidget/triangle.png"));

    shapesButtonList[ 6]->setIcon(QIcon(QApplication::applicationDirPath()+"/icons/shapesFunctionWidget/rightAngledTriangle.png"));
    shapesButtonList[ 7]->setIcon(QIcon(QApplication::applicationDirPath()+"/icons/shapesFunctionWidget/diamond.png"));
    shapesButtonList[ 8]->setIcon(QIcon(QApplication::applicationDirPath()+"/icons/shapesFunctionWidget/pentagon.png"));
    shapesButtonList[ 9]->setIcon(QIcon(QApplication::applicationDirPath()+"/icons/shapesFunctionWidget/hexagon.png"));
    shapesButtonList[10]->setIcon(QIcon(QApplication::applicationDirPath()+"/icons/shapesFunctionWidget/arrow.png"));
    shapesButtonList[11]->setIcon(QIcon(QApplication::applicationDirPath()+"/icons/shapesFunctionWidget/fourPointedStar.png"));

    shapesButtonList[12]->setIcon(QIcon(QApplication::applicationDirPath()+"/icons/shapesFunctionWidget/fivePointedStar.png"));
    shapesButtonList[13]->setIcon(QIcon(QApplication::applicationDirPath()+"/icons/shapesFunctionWidget/sixPointedStar.png"));
    shapesButtonList[14]->setIcon(QIcon(QApplication::applicationDirPath()+"/icons/shapesFunctionWidget/rectangleDialogBox.png"));
    shapesButtonList[15]->setIcon(QIcon(QApplication::applicationDirPath()+"/icons/shapesFunctionWidget/roundDialogBox.png"));
    shapesButtonList[16]->setIcon(QIcon(QApplication::applicationDirPath()+"/icons/shapesFunctionWidget/heart.png"));
    shapesButtonList[17]->setIcon(QIcon(QApplication::applicationDirPath()+"/icons/shapesFunctionWidget/flash.png"));

    label = new QLabel(QString::fromUtf8("形状") , this);
    label->setAlignment(Qt::AlignCenter);       //设置label居中
}

