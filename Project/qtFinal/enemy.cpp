#include"enemy.h"
#include<QTimer>
#include<QGraphicsScene>
#include <QDebug>
#include <time.h>
Enemy::Enemy(QGraphicsPixmapItem *parent):QObject(),QGraphicsPixmapItem(parent){
    qsrand(time(NULL));
    int base = qrand() % 400;
    setPos(base,-100);
    vy=-5;
}

void Enemy::move()
{
    //qDebug() << x() << " " << y();
    vy-=1;
    setPos(x() + 9,y()-vy);
    if(x()> scene()->width() || y()>scene()->height())
    {
        scene()->removeItem(this);
        delete this;
    }


}



EnemyDerived1::EnemyDerived1(QGraphicsPixmapItem *parent):Enemy(parent){
    setPixmap(QPixmap(":/images/resources/police.png"));
}

EnemyDerived2::EnemyDerived2(QGraphicsPixmapItem *parent):Enemy(parent)
{
    setPixmap(QPixmap(":/images/resources/soldier.png"));
    qsrand(time(NULL));
    int base = (qrand() % 400) + 400;
    setPos(base,-100);
}

void EnemyDerived2::move(){
    //qDebug() << x() << " " << y();
    vy-= 1;
    setPos(x() - 9,y()-vy);
    if(x()< -100 || y()>scene()->height()){ //100 = enemy width
        scene()->removeItem(this);
        delete this;
    }


}
