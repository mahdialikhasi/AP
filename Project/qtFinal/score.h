#ifndef SCORE
#define SCORE
#include <QGraphicsSimpleTextItem>
class Score: public QGraphicsTextItem{
    int score;
public:
    Score(QGraphicsTextItem * parent = 0);
    void increase();
    int getScore();
};

#endif // SCORE

