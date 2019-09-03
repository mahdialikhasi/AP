#include "score.h"
#include <QFont>
#include <QGraphicsScene>
#include "game.h"
extern Game * game;
Score::Score(QGraphicsTextItem *parent):QGraphicsTextItem(parent){
    score = 0; //initialize score

    setPlainText(QString("امتیاز :: ") + QString::number(score)); //draw the score
    setDefaultTextColor(Qt::blue);
    setFont(QFont("Aria", 16));

}

void Score::increase(){
    score++;
    if(score == 15){
        game->levelUp();
    }else if(score == 30 ){
        game->levelUp();
    }
    setPlainText(QString("امتیاز :: ") + QString::number(score)); //draw the score
}

int Score::getScore()
{
    return score;
}

