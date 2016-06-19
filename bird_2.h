#ifndef BIRD_2_H
#define BIRD_2_H

#include "game_item.h"
#include "bird.h"

class bird_2 : public bird{
public:
    bird_2(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    virtual void skill();
};

#endif // BIRD_BLUE_H
