#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QtMultimedia>
class Bullet : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT //using connect method

private:
    QMediaPlayer *hitSound;
public slots:
    void move();
public:
    Bullet(QGraphicsPixmapItem *parent = 0);

};

#endif // BULLET_H
