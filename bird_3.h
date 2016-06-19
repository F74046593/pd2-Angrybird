#ifndef BIRD_3_H
#define BIRD_3_H

#include "game_item.h"
#include "bird.h"

class bird_3 : public bird{
public:
    bird_3(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    virtual void skill();
};

#endif // BIRD_3_H
