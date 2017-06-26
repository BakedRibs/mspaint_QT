#ifndef COLORSFUNCTIONWIDGET_H
#define COLORSFUNCTIONWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QApplication>
#include <QTextCodec>
#include <QLabel>

class colorsFunctionWidget : public QWidget
{
public:
    colorsFunctionWidget(QWidget *parent);
    ~colorsFunctionWidget();

    QPushButton *colorOneButton;
    QPushButton *colorTwoButton;
    QPushButton *paletteButton;
    QList<QPushButton*> *changelessButtonList;
    QList<QPushButton*> *changeableButtonList;
    QLabel *label;

    void colorButtonsInit();
};

#endif // COLORSFUNCTIONWIDGET_H
