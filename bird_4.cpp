#include "bird_4.h"

bird_4::bird_4(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene) : bird(x, y, radius, timer, pixmap, world, scene){
}

void bird_4::skill(){
    set_linear_velocity(b2Vec2(-50, 0));
}
