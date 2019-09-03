#include "game.h"
#include "myplayer.h"
#include "boundary.h"
#include "pad.h"
#include "score.h"
#include "health.h"
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QtMultimedia>
#include "enemy.h"
#include "bonus.h"
#include <QFont>
#include <QGraphicsTextItem>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QVideoWidget>
#include <QList>
#include <algorithm>
#include <QGridLayout>
#include <QPalette>
extern Game * game;
Game::Game(int restart, QWidget *parent): QGraphicsView(parent){
    if(restart){
        start();
    }else{
        //play intro
        QMediaPlayer *player = new QMediaPlayer;

        QMediaPlaylist *playlist = new QMediaPlaylist();
        player->setPlaylist(playlist);
        playlist->addMedia(QUrl("qrc:/video/resources/mainMenu-fin.mp4"));
        introVideoWidget = new QVideoWidget;
        player->setVideoOutput(introVideoWidget);
        introVideoWidget->setFixedSize(800,800);
        introVideoWidget->show();
        playlist->setCurrentIndex(1);
        player->play();
        connect(player, SIGNAL(stateChanged(QMediaPlayer::State)), this, SLOT(startGame(QMediaPlayer::State)));

    }
    ended = 0;
    level = 0;
}
void Game::start(){
    //visualize page
    scene = new QGraphicsScene(); //create a scene
    //add scene to view
    this->setScene(scene);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); //hide scroll bar
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); //hide scroll bar
    //this->setWindowState(Qt::WindowFullScreen);//make it full screen
    this->setFixedSize(800,800);
    scene->setSceneRect(0,0,800,800); //set scene position and size as the view
    scene->setBackgroundBrush(QBrush(QImage(":/images/resources/moonLight.jpg")));

    //initialize first items of page
    //create Boundaries
    Boundary *Bdown = new Boundary();
    Bdown->setRect(0,0, scene->width(),10);
    Bdown->setPos(0,scene->height());
    scene->addItem(Bdown);


    player = new MyPlayer(Bdown); //create a player
    player->setPos(scene->width() / 2 - player->width() / 2 , scene->height() - player->height());
    //Focuse on rect to use keyPressEvent
    player->setFlag(QGraphicsItem::ItemIsFocusable); //make item focusable
    player->setFocus(); //focuse on item
    scene->addItem(player);
    scene->addItem(player->leg);


    //create three first pad
    NormalPad *pad1 = new NormalPad(0,scene->height() / 5, scene->width());
    NormalPad *pad2 = new NormalPad(scene->height() / 5, (scene->height() / 5) * 2, scene->width());
    NormalPad *pad3 = new NormalPad((scene->height() / 5) * 2, (scene->height() / 5) * 3,scene->width());
    NormalPad *pad4 = new NormalPad((scene->height() / 5) * 3, (scene->height() / 5) * 4, scene->width());
    NormalPad *pad5 = new NormalPad((scene->height() / 5) * 4, (scene->height() / 5) * 5,scene->width());
    scene->addItem(pad1);
    scene->addItem(pad2);
    scene->addItem(pad3);
    scene->addItem(pad4);
    scene->addItem(pad5);

    //add score
    score = new Score();
    scene->addItem(score);


    //add health
    health = new Health();
    scene->addItem(health);

    //add sounds
    bgPlayList = new QMediaPlaylist();
    bgPlayList ->addMedia(QUrl("qrc:/sounds/resources/pop.wav"));
    bgPlayList ->setPlaybackMode(QMediaPlaylist::Loop);

    bgSound = new QMediaPlayer();
    bgSound->setPlaylist(bgPlayList);
    bgSound->play();

    //creating enemy
    QTimer * timer = new QTimer();
    timer->start(2000);
    connect(timer,SIGNAL(timeout()), this, SLOT(createEnemy()));



    //creating bonus
    QTimer * timer2 = new QTimer();
    timer2->start(3542);
    connect(timer2,SIGNAL(timeout()), this, SLOT(createBonus()));


    //playing video
    //QMediaPlaylist *bgVideoPlayList = new QMediaPlaylist();
    //bgVideoPlayList->addMedia(QUrl("qrc:/video/resources/bgfinal.mp4"));
    //bgVideoPlayList->setPlaybackMode(QMediaPlaylist::Loop);
    //QMediaPlayer *VideoPlayer = new QMediaPlayer;
    //VideoPlayer->setPlaylist(bgVideoPlayList);

    //QGraphicsVideoItem *videoItem = new QGraphicsVideoItem();
    //videoItem->setPos(0,0);
    //videoItem->setSize(QSizeF(scene->width(),scene->height()));
    //VideoPlayer->setVideoOutput(videoItem);
    //scene->addItem(videoItem);
    //bgVideoPlayList->setCurrentIndex(1);
    //VideoPlayer->play();



    show();
}

void Game::end(){
    if(ended == 0){
        bgSound->pause();
        //qDebug() << "y";
        game->close();
        player->setPos(-200,0);
        //scene->clear();
        gameOver = new QWidget();

        gameOver->setMaximumSize(800,800);
        gameOver->setMinimumSize(800,800);
        //QPalette *p = new QPalette();
        //p->setBrush(QPalette::Background, QBrush(QImage(":/images/resources/restartMenu.jpg")));
        gameOver->setStyleSheet("background-image:url(:/images/resources/restartMenu.jpg)");
        QLabel *lbl = new QLabel("امتیاز شما " + QString::number(this->score->getScore()));
        lbl->setStyleSheet("color: white");
        lbl->setFont(QFont("Arial", 30));
        lbl->setAlignment(Qt::AlignCenter);
        QVBoxLayout *VBox = new QVBoxLayout();

        gameOver->setLayout(VBox);
        VBox->addWidget(lbl);
        /*
        QList<int> lst;
        QList<int>::iterator it;
        QFile file(":/data/scoreBoard.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;

        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            //process_line(line);
            int read;
            read = line.toInt();
            lst.push_back(read);
            lst.push_back(game->score->getScore());


        }
        std::sort(lst.begin(), lst.end());
        file.close();
        QGridLayout * gr = new QGridLayout;
        VBox->addLayout(gr);
        it = lst.begin();
        for(int i=0; i<10; i++){
            QLabel * lb = new QLabel(QString::number(*it));
            gr->addWidget(lb);
            it++;

        }
        */
        QPushButton *restart = new QPushButton("شروع مجدد");
        restart->setStyleSheet("color : white; background-color: white");
        restart->setFont(QFont("Arial", 30));
        VBox->addWidget(restart);
        connect(restart,SIGNAL(clicked(bool)), this,SLOT(restart()));

        gameOver->show();
        ended = 1;
    }
}

void Game::levelUp(){
    level++;
    bgPlayList->removeMedia(0);
    if(level == 1){

        bgPlayList->addMedia(QUrl("qrc:/sounds/resources/jazz.wav"));
        bgSound->setPlaylist(bgPlayList);
        bgSound->play();
    }else{
        bgPlayList->addMedia(QUrl("qrc:/sounds/resources/rock.wav"));
        bgSound->setPlaylist(bgPlayList);
        bgSound->play();
    }
}

Game::~Game(){
    delete player;
    delete score;
    delete scene;
}

void Game::createEnemy(){
    //adding enemies
    qsrand(time(NULL));
    int x= qrand()%2;

    if(x == 0){
        EnemyDerived1 *enemy = new EnemyDerived1();
        scene->addItem(enemy);
        QTimer * timer = new QTimer;
        timer->start(50);
        connect(timer,SIGNAL(timeout()),enemy,SLOT(move()));
    }else{
        EnemyDerived2 *enemy = new EnemyDerived2();
        scene->addItem(enemy);
        QTimer * timer = new QTimer;
        timer->start(50);
        connect(timer,SIGNAL(timeout()),enemy,SLOT(move()));
    }

}



void Game::createBonus(){
    //adding bonuses
    qsrand(time(NULL));
    int x= qrand()%3;
    if(x == 0){
        BonusHealth *bonus = new BonusHealth();
        scene->addItem(bonus);
    }else if(x == 1){
        BonusShield *bonus = new BonusShield();
        scene->addItem(bonus);
    }else if(x == 2){
        BonusButtom *bonus = new BonusButtom();
        scene->addItem(bonus);
    }

}

void Game::restart(){
    gameOver->close();
    Game *pr = game;
    //scene->clear();
    game = new Game(1);
    game->show();
    delete pr;
}

void Game::startGame(QMediaPlayer::State state){
    //qDebug() << state;
    if(state == QMediaPlayer::StoppedState){
        start();
        introVideoWidget->close();
    }

}
