#ifndef LAND_H
#define LAND_H

#include "game_item.h"

class land : public game_item{
public:
    land(float x, float y, float w, float h, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
};

#endif // LAND_H
