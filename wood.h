#ifndef WOOD_H
#define WOOD_H

#include <QTimer>

#include "game_item.h"

#define WOOD_DENSITY 10.0f
#define WOOD_FRICTION 0.2f
#define WOOD_RESTITUTION 0.5f

class wood : public game_item{
public:
    wood(float x, float y, float w, float h, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
};

#endif // WOOD_H
