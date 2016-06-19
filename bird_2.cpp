#include "bird_2.h"

bird_2::bird_2(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene) : bird(x, y, radius, timer, pixmap, world, scene){
}

void bird_2::skill(){
    set_linear_velocity(b2Vec2(0, 0));
}
