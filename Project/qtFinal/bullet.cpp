#include "bullet.h"
#include "enemy.h"
#include "game.h"
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QtMultimedia>
extern Game * game;
Bullet::Bullet(QGraphicsPixmapItem *parent): QObject(), QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/resources/bullet.png")); //create a bullet
    //create a timer and a slot signal for moving
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50); //start timer
    hitSound = new QMediaPlayer();
    hitSound->setMedia(QUrl("qrc:/sounds/resources/enemyDie1.mp3"));
}

void Bullet::move(){
    setPos(x(), y() - 40); //move bullets up
    //delete bullet if it go off the scene
    if(pos().y() < -10 ){ //10 = bullet height
        scene()->removeItem(this);
        delete this;

    }

    //if hit a enemy
    QList<QGraphicsItem *> items = this->collidingItems(); //select all colliding Items
    foreach( QGraphicsItem *item, items ){

        if( dynamic_cast<Enemy *>(item))
        {

                game->score->increase();
                scene()->removeItem(dynamic_cast<Enemy *>(item));
                delete item;
                scene()->removeItem(this);
                delete this;
                hitSound->setMedia(QUrl("qrc:/sounds/resources/enemyDie1.mp3"));
                hitSound->play();
        }

    }
}

