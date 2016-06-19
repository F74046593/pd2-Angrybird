#include "bird_3.h"

bird_3::bird_3(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene) : bird(x, y, radius, timer, pixmap, world, scene){
}

void bird_3::skill(){
    set_linear_velocity(b2Vec2(50, 0));
}
