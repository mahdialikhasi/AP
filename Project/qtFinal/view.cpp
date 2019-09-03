#include "view.h"
View::View(QGraphicsView *parent):QGraphicsView(parent){
    scene1 = new QGraphicsScene(); //create a scene
    QGraphicsRectItem *rect = new QGraphicsRectItem(); //create a rectangle
    rect->setRect(0,0,100,100); //set rectangle at x = 0, y = 0, width = 100, height = 100
    scene1->addItem(rect);
}
