#ifndef BIRD_H
#define BIRD_H

#include "game_item.h"

#include <QTimer>

#define BIRD_DENSITY 10.0f
#define BIRD_FRICTION 0.2f
#define BIRD_RESTITUTION 0.5f

class bird : public game_item
{
public:
    bird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    void set_linear_velocity(b2Vec2 velocity);
    void set_transform(b2Vec2 loc, float angle);
    b2Vec2 get_linear_velocity();
    b2Vec2 get_position();
    virtual void skill() = 0;
};

#endif // BIRD_H
