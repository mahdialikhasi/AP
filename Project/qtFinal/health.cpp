#include "health.h"
#include <QFont>
Health::Health(QGraphicsTextItem *parent):QGraphicsTextItem(parent){
    health = 25; //initialize score

    setPlainText(QString("ژووووووون :: ") + QString::number(health)); //draw the score
    setDefaultTextColor(Qt::red);
    setFont(QFont("Aria", 16));

    setPos(0,20);
}

void Health::decrease(){
    health--;
    setPlainText(QString("ژووووووون :: ") + QString::number(health)); //draw the score
}

void Health::increase(){
    health++;
    setPlainText(QString("ژووووووون :: ") + QString::number(health)); //draw the score
}


int Health::getHealth()
{
    return health;
}


