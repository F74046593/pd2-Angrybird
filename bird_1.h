#ifndef BIRD_1_H
#define BIRD_1_H

#include "game_item.h"
#include "bird.h"

class bird_1 : public bird{
public:
    bird_1(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    virtual void skill();
};

#endif // BIRD_1_H
