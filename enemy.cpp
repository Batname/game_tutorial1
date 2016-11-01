#include "enemy.h"
#include "game.h"

#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h> // rand() -> large int

extern Game *game; // external global variable

Enemy::Enemy(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent)
{
    // set random position
    int random_number = rand() % 700;
    setPos(random_number, 0);

    // drew the rect
    setPixmap(QPixmap(":/images/BasicEnemy.png"));
    setTransformOriginPoint(50, 50);
    setRotation(0);

    // connect
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));


    timer->start(50);
}

void Enemy::move()
{
    // move enemy down
    setPos(x(), y() + 5);

    if (pos().y()  > 600) {
        // decrease health
        game->health->decrease();

        scene()->removeItem(this);
        delete this;
    }
}
