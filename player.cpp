#include "player.h"
#include "bullet.h"
#include "enemy.h"

#include <QKeyEvent>
#include <QGraphicsScene>

Player::Player(QGraphicsItem *parent) : QGraphicsRectItem(parent)
{
    bulletSound = new QMediaPlayer();
    bulletSound->setMedia(QUrl("qrc:/sounds/frog.mp3"));
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left) {
        if (pos().x() > 0)
            setPos(x() - 10, y());
    }
    else if (event->key() == Qt::Key_Right) {
        if (pos().x() + 100 < 800)
            setPos(x() + 10, y());
    }
    else if (event->key() == Qt::Key_Space) {
        // create a bullet
        Bullet *bullet = new Bullet();
        bullet->setPos(x(), y());
        scene()->addItem(bullet);

        // play bulletSound
        if (bulletSound->state() == QMediaPlayer::PlayingState)
            bulletSound->setPosition(0);
        else if (bulletSound->state() == QMediaPlayer::StoppedState)
            bulletSound->play();
    }
}

void Player::spawn()
{
    // create an enemy
    Enemy *enemy = new Enemy();
    scene()->addItem(enemy);
}
