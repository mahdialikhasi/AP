#ifndef GAME
#define GAME
#include <QGraphicsView>
#include "myplayer.h"
#include <QGraphicsScene>
#include "score.h"
#include "health.h"
#include <QGraphicsTextItem>

class Game: public QGraphicsView{
    Q_OBJECT
private:
    QMediaPlaylist *bgPlayList;
    QMediaPlayer *bgSound;
    QWidget * gameOver;
    QVideoWidget *introVideoWidget;
    int level;
public:
    Game(int restart = 0, QWidget *parent = 0);
    ~Game();
    MyPlayer *player;
    Score *score;
    Health *health;
    QGraphicsScene *scene;
    int ended;
    void start();
    void end();
    void levelUp();
public slots:
    void createEnemy();
    void createBonus();
    void restart();
    void startGame(QMediaPlayer::State state);
};

#endif // GAME

