#ifndef COLORSFUNCTIONWIDGET_H
#define COLORSFUNCTIONWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QApplication>
#include <QTextCodec>
#include <QLabel>
#include <QVector>

class colorsFunctionWidget : public QWidget
{
public:
    colorsFunctionWidget(QWidget *parent);
    ~colorsFunctionWidget();

    QPushButton *colorOneButton;
    QPushButton *colorTwoButton;
    QPushButton *paletteButton;
    QPushButton *buttonList[30];
    QLabel *label;

    void colorButtonsInit(const int colors[][3]);
    void buttonListIconCreate(QPushButton *tempButton,int Rint,int Gint,int Bint);
};

#endif // COLORSFUNCTIONWIDGET_H
