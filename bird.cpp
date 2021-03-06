#include "bird.h"

bird::bird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):game_item(world){
    g_pixmap.setPixmap(pixmap);
    g_pixmap.setTransformOriginPoint(g_pixmap.boundingRect().width()/2,g_pixmap.boundingRect().height()/2);
    g_size = QSize(radius*1,radius*1);

    b2BodyDef bodydef;
    bodydef.type = b2_dynamicBody;
    bodydef.bullet = true;
    bodydef.position.Set(x,y);
    bodydef.userData = this;
    g_body = world->CreateBody(&bodydef);

    b2CircleShape bodyshape;
    bodyshape.m_radius = radius;

    b2FixtureDef fixturedef;
    fixturedef.shape = &bodyshape;
    fixturedef.density = BIRD_DENSITY;
    fixturedef.friction = BIRD_FRICTION;
    fixturedef.restitution = BIRD_RESTITUTION;
    g_body->SetAngularDamping(3);
    g_body->CreateFixture(&fixturedef);

    connect(timer, SIGNAL(timeout()), this,SLOT(paint()));

    scene->addItem(&g_pixmap);
}

void bird::set_linear_velocity(b2Vec2 velocity)
{
    g_body->SetLinearVelocity(velocity);
}

void bird::set_transform(b2Vec2 loc, float angle){
    g_body->SetTransform(loc, angle);
}

b2Vec2 bird::get_linear_velocity(){
    return g_body->GetLinearVelocity();
}

b2Vec2 bird::get_position(){
    return g_body->GetPosition();
}
