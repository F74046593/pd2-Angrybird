#ifndef SHOOTER_H
#define SHOOTER_H

#include "game_item.h"

class shooter : public game_item{
public:
    shooter(float x, float y, float w, float h, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
};

#endif // SHOOTER_H
