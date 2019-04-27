#include "animatedbee.h"

AnimatedBee::AnimatedBee()
{





    //Connect
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()), this,SLOT(move()));

    timer->start(100);//every 100ms timeout changes



    //scene->removeitem(this);
    //pos.x()
    //setPos(x(),y());
    //check collision
    //QList<QGraphicsItem *> items = collidingItems();
        //for loops checking if items in Qlist
        //if  (typeid(*(colliding_items[i])) == typeid(Enemy)
    //remove and then delete
    //then return

}


void AnimatedBee::move(){


}
