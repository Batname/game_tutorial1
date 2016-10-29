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
    MyRect *rect = new MyRect();
    rect->setRect(0, 0, 100, 100);

    // make item focusable
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();

    // add the item to the scene
    scene->addItem(rect);

    // add a view
    QGraphicsView *view = new QGraphicsView(scene);
    view->show();

    return a.exec();
}
