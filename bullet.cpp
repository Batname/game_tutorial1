#include "bullet.h"
#include "enemy.h"
#include "game.h"

#include <QTimer>
#include <QGraphicsScene>
#include <Qlist>

extern Game *game; // external global variable

Bullet::Bullet(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent)
{
    // draw graphics
    setPixmap(QPixmap(":/images/bullet.png"));

    // connect
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));


    timer->start(30);
}

void Bullet::move()
{
    // if bulet collide with enemy , destroy both
    QList<QGraphicsItem *> colliding_items = collidingItems();

    for (int i = 0, n = colliding_items.size(); i < n; ++i) {
        if (typeid(*(colliding_items[i])) == typeid(Enemy)) {
            // increase the score
            game->score->increase();

            // remove both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            // delete from heap
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    // if there was no collision with an Enemy, move the bullet forward
    setPos(x(),y()-10);
    // if the bullet is off the screen, destroy it
    if (pos().y() < 0){
        scene()->removeItem(this);
        delete this;
    }
}
