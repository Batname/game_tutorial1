#include "myrect.h"

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // create a scene
    QGraphicsScene *scene = new QGraphicsScene();

    // create item and put it into scene
    MyRect *player = new MyRect();
    player->setRect(0, 0, 100, 100);

    // make item focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // add the item to the scene
    scene->addItem(player);

    // add a view
    QGraphicsView *view = new QGraphicsView(scene);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->show();

    view->setFixedSize(800, 600);
    scene->setSceneRect(0, 0, 800, 600);

    player->setPos(view->width() / 2, view->height() - player->rect().height());

    return a.exec();
}
