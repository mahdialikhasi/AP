#ifndef MYPLAYER
#define MYPLAYER
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QObject>
#include "boundary.h"
#include "pad.h"
#include <QtMultimedia>

class MyPlayer : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
    int canCreateBullet;
    double v0; //the base speed
    double v; //the speed
    double g; //gravity
    Boundary *Bdown; //down boundary
    QTimer *timer2;
    int times;
    Pad *hittedPad; //hitted pad
    QMediaPlayer *padSound;
    QMediaPlayer * laserSound;
    QMediaPlayer *hurtSound;
    int shield; //is sheilded
    int buttom; //is buttomed
public:
    MyPlayer(Boundary *Bdown, QGraphicsPixmapItem *parent = 0);
    ~MyPlayer();
    QGraphicsRectItem *leg;
    void keyPressEvent(QKeyEvent *);
    qreal width(); //width of obj
    qreal height(); //height of obj
    void setShield();
    void setButtom();
public slots:
    void move(); //move the Item
    void moveScene(); //move the scene
    void shieldEnd();
    void buttomEnd();
};

#endif // MYPLAYER

