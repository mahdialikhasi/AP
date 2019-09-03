#include<QTimer>
#include<time.h>
#include"bonus.h"
#include <QDebug>
#include"game.h"

extern Game * game;
Bonus::Bonus(QGraphicsPixmapItem *parent): QObject(), QGraphicsPixmapItem(parent){
    QTimer * timer = new QTimer;
    timer->start(50);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    vy=-3;
    qsrand(time(NULL));
    setPos(qrand()%700, -100);     //800= scene.width() && 100= obj`s width
    setTransformOriginPoint(46,46);
}

void Bonus::move(){
    setPos(x(),y()-vy);
    setRotation(rotation() + 5);
}



BonusHealth::BonusHealth(Bonus *parent):Bonus(parent){
    setPixmap(QPixmap(":/images/resources/healthPachage.png"));
}

void BonusHealth::gift()
{
    //qDebug() << "health";
    game->health->increase();
}

BonusShield::BonusShield(Bonus *parent):Bonus(parent){
    setPixmap(QPixmap(":/images/resources/shield.png"));
}

void BonusShield::gift()
{
    //qDebug() << "Shield";
    game->player->setShield();
}

BonusButtom::BonusButtom(Bonus *parent):Bonus(parent){
    setPixmap(QPixmap(":/images/resources/noButtom.png"));
}

void BonusButtom::gift()
{
    //qDebug() << "Buttom";
    game->player->setButtom();
}
