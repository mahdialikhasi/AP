#ifndef ENEMY
#define ENEMY

#include <QPixmap>
#include <QGraphicsPixmapItem>

class Enemy : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
protected:
    double vy;


public:
    Enemy(QGraphicsPixmapItem * parent=0);

public slots:
    void move();
};



class EnemyDerived1:public Enemy
{
public:
    EnemyDerived1(QGraphicsPixmapItem * parent=0);

};


class EnemyDerived2:public Enemy{
    Q_OBJECT
public:
    EnemyDerived2(QGraphicsPixmapItem * parent=0);
public slots:
    void move();
};



#endif // ENEMY

