#ifndef GAME_ITEM_H
#define GAME_ITEM_H

#include <Box2D/Box2D.h>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QTransform>
#include <QtMath>

class game_item : public QObject{
    Q_OBJECT
public:
    game_item(b2World *world);
    ~game_item();
    static void set_global_size(QSizeF worldsize, QSizeF windowsize);
public slots:
    void paint();
protected:
    b2Body *g_body;
    QGraphicsPixmapItem g_pixmap;
    QSizeF g_size;
    b2World *g_world;
    static QSizeF g_worldsize, g_windowsize;
};

#endif // GAME_ITEM_H
