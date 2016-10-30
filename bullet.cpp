#include "bullet.h"
#include "enemy.h"

#include <QTimer>
#include <QGraphicsScene>
#include <Qlist>

Bullet::Bullet() : QObject(), QGraphicsRectItem()
{
    // drew the rect
    setRect(0, 0, 10, 50);

    // connect
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));


    timer->start(50);
}

void Bullet::move()
{
    // if bulet collide with enemy , destroy both
    QList<QGraphicsItem *> colliding_items = collidingItems();

    for (int i = 0, n = colliding_items.size(); i < n; ++i) {
        if (typeid(*(colliding_items[i])) == typeid(Enemy)) {
            // remove both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            // delete from heap
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    // move bullet up
    setPos(x(), y() - 10);

    if (pos().y()  + rect().height() < 0) {
        scene()->removeItem(this);
        delete this;
    }
}
