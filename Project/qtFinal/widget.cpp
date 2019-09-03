#include "widget.h"
#include "QLabel"
#include "QLineEdit"
#include "QVBoxLayout"
#include "QHBoxLayout"
#include "QGridLayout"
#include "QPushButton"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *mainBox = new QVBoxLayout();
    setLayout(mainBox);
    setWindowTitle("Final AP QT");

    /*Box One*/
    QHBoxLayout *hb1 = new QHBoxLayout();
    le1 = new QLineEdit();
    lb1 = new QLabel("Label 1");
    QGridLayout *gr1 = new QGridLayout();
    mainBox->addLayout(hb1);
    hb1->addLayout(gr1);
    gr1->addWidget(lb1,0,0,1,2);
    gr1->addWidget(le1,0,2,2,1);

    /*Box Two*/
    QHBoxLayout *hb2 = new QHBoxLayout();
    le2 = new QLineEdit();
    lb2 = new QLabel("Label 2");
    QGridLayout *gr2 = new QGridLayout();
    mainBox->addLayout(hb2);
    hb2->addLayout(gr2);
    gr2->addWidget(lb2,0,0,1,2);
    gr2->addWidget(le2,0,2,2,1);

    /*Box three*/
    QHBoxLayout *hb3 = new QHBoxLayout();
    QPushButton *OK = new QPushButton("OK");
    QPushButton *cancel = new QPushButton("Cancel");
    mainBox->addLayout(hb3);
    hb3->addWidget(OK);
    hb3->addWidget(cancel);

    /*Signal and Slots*/
    connect(cancel, SIGNAL(clicked(bool)), this, SLOT(close()));
    connect(OK, SIGNAL(clicked(bool)), this, SLOT(myslot()));
}

Widget::~Widget()
{

}

void Widget::myslot(){
    this->lb1->setText(this->le1->text());
    this->lb2->setText(this->le2->text());

}
