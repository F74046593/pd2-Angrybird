#ifndef BIRD_4_H
#define BIRD_4_H

#include "game_item.h"
#include "bird.h"

class bird_4 : public bird{
public:
    bird_4(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    virtual void skill();
};

#endif // BIRD_4_H
