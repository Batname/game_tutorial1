#include "game.h"
#include "enemy.h"

#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QMediaPlayer>

Game::Game(QWidget *parent)
{
    // create a scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 800, 600);

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800, 600);

    player = new Player();
    player->setRect(0, 0, 100, 100);
    player->setPos(400, 500);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player); // add the item to the scene

    // create  the score
    score = new Score();
    scene->addItem(score);

    // create health
    health = new Health();
    health->setPos(health->x(), health->y() + 25);
    scene->addItem(health);

    // span enemies
    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(2000);

    // play background music
    QMediaPlayer *music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/sax.mp3"));
    music->play();

    show();
}
