#ifndef HEALTH
#define HEALTH
#include <QGraphicsSimpleTextItem>


class Health: public QGraphicsTextItem{
    int health;
public:
    Health(QGraphicsTextItem * parent = 0);
    void decrease();
    void increase();
    int getHealth();
};



#endif // HEALTH

