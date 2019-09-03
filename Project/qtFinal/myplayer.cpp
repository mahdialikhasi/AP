#include "myplayer.h"
#include <QDebug>
#include <QKeyEvent>
#include "bullet.h"
#include <QGraphicsScene>
#include <QTimer>
#include "boundary.h"
#include "pad.h"
#include "score.h"
#include <QGraphicsPixmapItem>
#include "game.h"
#include <QtMultimedia>
#include <QGraphicsRectItem>
#include <QPixmap>
#include <time.h>
#include "enemy.h"
#include "bonus.h"

extern Game * game; //using global game
MyPlayer::MyPlayer(Boundary *Bdown, QGraphicsPixmapItem *parent): QObject(), QGraphicsPixmapItem(parent){
    canCreateBullet = 1;
    this->setPixmap(QPixmap(":/images/resources/mainChar.png")); //set player image
    this->Bdown = Bdown;
    //create a leg for player
    leg = new QGraphicsRectItem();
    leg->setRect(0,0, width(), height() / 2);
    leg->hide();
    v = v0 = 30;
    g = 1;
    //add sound for pad
    padSound = new QMediaPlayer();
    padSound->setMedia(QUrl("qrc:/sounds/resources/pad1.wav"));
    //slot and signal
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(20);
    //shottig sound
    laserSound = new QMediaPlayer();
    laserSound->setMedia(QUrl("qrc:/sounds/resources/laser.mp3"));
    hurtSound = new QMediaPlayer();
    hurtSound->setMedia(QUrl("qrc:/sounds/resources/playerHurt1.mp3"));
    shield = buttom = 0;


}


/*void MyPlayer::createEnemy()
{
    //adding enemies
    Enemy *enemy = new Enemy();
    scene->addItem(enemy);
}*/

MyPlayer::~MyPlayer()
{
    delete leg;
}
void MyPlayer::keyPressEvent(QKeyEvent *event){

    if(event->key() == Qt::Key_Left){ //moving using key press
        //qDebug() << x() << scene()->width();
        setPos(x() - 18, y());
        leg->setPos(leg->x() - 18, leg->y());
        if(pos().x() <  -1 * width()){ //dont let the player go off the scene, make it circular
            setPos(scene()->width(), y());
            leg->setPos(scene()->width(), leg->y());
        }
    }else if(event->key() == Qt::Key_Right){ //moving using key press
        setPos(x() + 18, y());
        leg->setPos(leg->x() + 18, leg->y());
        if(pos().x() > scene()->width()) //dont let the player go off the scene, make it circular
        {
            setPos(-1 * width(), y());
            leg->setPos(-1 * leg->rect().width(), leg->y());
        }
    } else if(event->key() == Qt::Key_Space){ //shooting using spacebar
        if(canCreateBullet){
            Bullet *bullet = new Bullet();
            bullet->setPos(x() + width() / 2,y()); //set position
            scene()->addItem(bullet);

            //playing the sound of laser
            //qDebug() << laserSound->state();
            laserSound->setMedia(QUrl("qrc:/sounds/resources/laser.mp3"));
            laserSound->play();

        }
    }
}

qreal MyPlayer::width(){
    return 75;
}

qreal MyPlayer::height(){
    return 75;
}

void MyPlayer::setShield(){
    QTimer *timer = new QTimer();
    timer->start(9000);
    timer->setSingleShot(true);
    shield = 1;
    this->setPixmap(QPixmap(":/images/resources/mainCharShield.png")); //set player image
    connect(timer, SIGNAL(timeout()), this, SLOT(shieldEnd()));
}

void MyPlayer::setButtom()
{
    QTimer *timer = new QTimer();
    timer->start(9000);
    timer->setSingleShot(true);
    buttom = 1;
    connect(timer, SIGNAL(timeout()), this, SLOT(buttomEnd()));
}



void MyPlayer::move(){
    setPos(x(), y() - v); //jump the player
    leg->setPos(pos().x(), pos().y() + height() - leg->rect().height());
    if(buttom && (y() + height() > scene()->height())){ //for buttom
        v = v0;
    }
    //if goes of the page, hame over
    if(y() > scene()->height()){
        //qDebug() << "y";
        game->end();
    }
    //if hit a enemy or bonus
    QList<QGraphicsItem *> itemz = this->collidingItems(); //select all colliding Items
    foreach( QGraphicsItem *item, itemz ){

        if( dynamic_cast<Enemy *>(item))
        {
            if(game->health->getHealth() > 0 && shield == 0)
            {
                game->health->decrease();
                hurtSound->setMedia(QUrl("qrc:/sounds/resources/playerHurt1.mp3"));
                hurtSound->play();
                scene()->removeItem(dynamic_cast<Enemy *>(item));
                delete item;
            }else if(game->health->getHealth() <= 0 ){ //health == -1 and die :(
                game->end();
            }
        }
        else if( dynamic_cast<Bonus *>(item))
        {
            dynamic_cast<Bonus *>(item)->gift();
            scene()->removeItem(item);
            delete item;
        }

    }

    //if hit the pad or ground
    QList<QGraphicsItem *> items = leg->collidingItems(); //select all colliding Items
    foreach( QGraphicsItem *item, items ){
        Pad *padItem = dynamic_cast<Pad *> (item); //select pads
        if(padItem && v < 0){ //if colliding pads
            //hited
            if(hittedPad != padItem){ //unique hitted pad
                hittedPad = padItem;
                //scoreUp
                game->score->increase();
            }

            //move scene up
            timer2 = new QTimer();
            timer2->start(50);
            times = ((scene()->height() - padItem->pos().y()) / 5) - 20; //how many times timer intervals
            connect(timer2,SIGNAL(timeout()), this, SLOT(moveScene()));

            //check what kind of pad hitted
            v = v0;
            if(dynamic_cast<JumpingPad *> (item)){
                v *= 1.2;

            }else if(dynamic_cast<BreakingPad *> (item)){
                dynamic_cast<BreakingPad *> (item)->setOpacity(0.2);
                times += 25;
            }

            //playSound

            padSound->setMedia(QUrl("qrc:/sounds/resources/pad1.wav"));
            padSound->play();


        }else if(dynamic_cast<Boundary *> (item)){ //if colliding ground
            v = v0;
        }
    }
    v = v - g;
}

void MyPlayer::moveScene(){
    times--;
    if(times > 0){
        QList<QGraphicsItem *> items2 = scene()->items(); //select all scene Item
        foreach( QGraphicsItem *item, items2 ){
            if(!dynamic_cast<Score *> (item) && !dynamic_cast<Health *> (item)) //dont move score
                item->setPos(item->pos().x(), item->pos().y() + 5);
            //if item goes off the page
            if(item->pos().y() + 100 > scene()->height()){
                //delete it
                if(dynamic_cast<Pad *> (item)){

                    //create a new pad with weighted random number
                    qsrand(time(NULL) + dynamic_cast<Pad *> (item)->count);
                    int x = qrand() % 10;
                    if(x < 2){
                        BreakingPad *pad = new BreakingPad(-1 * (scene()->height() / 5), 0 , scene()->width());
                        scene()->addItem(pad);
                    }else if(x < 5){
                        JumpingPad *pad = new JumpingPad(-1 * (scene()->height() / 5), 0 , scene()->width());
                        scene()->addItem(pad);
                    }else{
                        NormalPad *pad = new NormalPad(-1 * (scene()->height() / 5), 0 , scene()->width());
                        scene()->addItem(pad);
                    }
                    scene()->removeItem(item);
                    delete item;
                }
            }
        }
    }else{
        timer2->stop();
        return; //end of moving scene
    }

}

void MyPlayer::shieldEnd(){
    shield = 0;
    this->setPixmap(QPixmap(":/images/resources/mainChar.png")); //set player image
}

void MyPlayer::buttomEnd(){
    buttom = 0;
}
