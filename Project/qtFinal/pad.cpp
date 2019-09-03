#include "pad.h"
#include <time.h>
#include <QGraphicsPixmapItem>
#include <QPixmap>
int Pad::count = 0;
Pad::Pad(int miny, int maxy, int maxx, QGraphicsPixmapItem *parent): QGraphicsPixmapItem(parent){
    qsrand(time(NULL) + count * 10);
    count++;
    double y = (qrand() % (maxy - miny)) + miny;
    double x = qrand() % (maxx - 100); //100 = pad width
    setPos(x,y);
    //qDebug() << count << " " << x;
}

NormalPad::NormalPad(int miny, int maxy, int maxx, QGraphicsPixmapItem *parent):Pad(miny,maxy,maxx,parent){
    setPixmap(QPixmap(":/images/resources/pad1.png"));
}
BreakingPad::BreakingPad(int miny, int maxy, int maxx, QGraphicsPixmapItem *parent):Pad(miny,maxy,maxx,parent){
    setPixmap(QPixmap(":/images/resources/pad2.png"));
}
JumpingPad::JumpingPad(int miny, int maxy, int maxx, QGraphicsPixmapItem *parent):Pad(miny,maxy,maxx,parent){
    setPixmap(QPixmap(":/images/resources/pad3.png"));
}
