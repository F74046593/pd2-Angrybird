#-------------------------------------------------
#
# Project created by QtCreator 2016-06-10T15:55:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pd2-Angrybird
TEMPLATE = app


SOURCES +=  main.cpp\
            mainwindow.cpp \
            game_item.cpp \
            land.cpp \
            bird.cpp \
    bird_2.cpp \
    bird_1.cpp \
    bird_3.cpp \
    bird_4.cpp \
    wood.cpp \
    pig.cpp \
    shooter.cpp

HEADERS  += mainwindow.h \
            Box2D/Collision/Shapes/b2ChainShape.h \
            Box2D/Collision/Shapes/b2CircleShape.h \
            Box2D/Collision/Shapes/b2EdgeShape.h \
            Box2D/Collision/Shapes/b2PolygonShape.h \
            Box2D/Collision/Shapes/b2Shape.h \
            Box2D/Collision/b2BroadPhase.h \
            Box2D/Collision/b2Collision.h \
            Box2D/Collision/b2Distance.h \
            Box2D/Collision/b2DynamicTree.h \
            Box2D/Collision/b2TimeOfImpact.h \
            Box2D/Common/b2BlockAllocator.h \
            Box2D/Common/b2Draw.h \
            Box2D/Common/b2GrowableStack.h \
            Box2D/Common/b2Math.h \
            Box2D/Common/b2Settings.h \
            Box2D/Common/b2StackAllocator.h \
            Box2D/Common/b2Timer.h \
            Box2D/Dynamics/Contacts/b2ChainAndCircleContact.h \
            Box2D/Dynamics/Contacts/b2ChainAndPolygonContact.h \
            Box2D/Dynamics/Contacts/b2CircleContact.h \
            Box2D/Dynamics/Contacts/b2Contact.h \
            Box2D/Dynamics/Contacts/b2ContactSolver.h \
            Box2D/Dynamics/Contacts/b2EdgeAndCircleContact.h \
            Box2D/Dynamics/Contacts/b2EdgeAndPolygonContact.h \
            Box2D/Dynamics/Contacts/b2PolygonAndCircleContact.h \
            Box2D/Dynamics/Contacts/b2PolygonContact.h \
            Box2D/Dynamics/Joints/b2DistanceJoint.h \
            Box2D/Dynamics/Joints/b2FrictionJoint.h \
            Box2D/Dynamics/Joints/b2GearJoint.h \
            Box2D/Dynamics/Joints/b2Joint.h \
            Box2D/Dynamics/Joints/b2MotorJoint.h \
            Box2D/Dynamics/Joints/b2MouseJoint.h \
            Box2D/Dynamics/Joints/b2PrismaticJoint.h \
            Box2D/Dynamics/Joints/b2PulleyJoint.h \
            Box2D/Dynamics/Joints/b2RevoluteJoint.h \
            Box2D/Dynamics/Joints/b2RopeJoint.h \
            Box2D/Dynamics/Joints/b2WeldJoint.h \
            Box2D/Dynamics/Joints/b2WheelJoint.h \
            Box2D/Dynamics/b2Body.h \
            Box2D/Dynamics/b2ContactManager.h \
            Box2D/Dynamics/b2Fixture.h \
            Box2D/Dynamics/b2Island.h \
            Box2D/Dynamics/b2TimeStep.h \
            Box2D/Dynamics/b2World.h \
            Box2D/Dynamics/b2WorldCallbacks.h \
            Box2D/Rope/b2Rope.h \
            Box2D/Box2D.h \
            game_item.h \
            land.h \
            bird.h \
    bird_2.h \
    bird_1.h \
    bird_3.h \
    bird_4.h \
    wood.h \
    pig.h \
    shooter.h

LIBS += -L. -lBox2D

RESOURCES += res.qrc
