#ifndef VIEW
#define VIEW
#include <QApplication>
#include "QGraphicsScene"
#include "QGraphicsItem"
#include "QGraphicsView"
#include "QGraphicsRectItem"
class View : public QGraphicsView{
    QGraphicsScene *scene1;
public:
    View(QGraphicsView *parent);
    ~View();
};

#endif // VIEW

