#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "QLabel"
#include "QLineEdit"
class Widget : public QWidget
{
    Q_OBJECT
public slots:
    void myslot();
public:
    QLineEdit *le1;
    QLabel *lb1;
    QLineEdit *le2;
    QLabel *lb2;
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // WIDGET_H
