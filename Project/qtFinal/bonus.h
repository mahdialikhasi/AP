#ifndef BONUS
#define BONUS

#include <QGraphicsPixmapItem>

class Bonus : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
private:
    double vy;
public:
    Bonus(QGraphicsPixmapItem * parent = 0);
    virtual void gift() = 0;
public slots:
    void move();
};


class BonusHealth :public Bonus{
public:
    BonusHealth(Bonus * parent = 0);
    void gift();
};


class BonusShield :public Bonus{
public:
    BonusShield(Bonus * parent = 0);
    void gift();
};


class BonusButtom :public Bonus{
public:
    BonusButtom(Bonus * parent = 0);
    void gift();
};


#endif // BONUS

