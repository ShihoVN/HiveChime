#include "animationboard.h"
#include <QGraphicsScene>

AnimationBoard::AnimationBoard()
{

}


void AnimationBoard::populate(){
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()), this,SLOT(addBee()));

   // timer->start(100);
   timer->start(rand() % 1000 + 100);//every 100ms timeout changes

    for (int i = 1; i <= 100; i++){
        addBee();


        //        timer->start(100);//every 100ms timeout changes
        //        AnimatedBee *b = new AnimatedBee(i);
        //        setPosition(b);

        //        bees.push_back(b);
    }
}


void AnimationBoard::addBee(){
    int ran = rand() % 8 + 1;

    //int ran = 2;
    AnimatedBee *b = new AnimatedBee(ran);
    setPosition(b);

}


void AnimationBoard::setPosition(AnimatedBee *b){


    switch(b->getGate()){

    case 1: b->getBee()->setPos(rand()%500 -250,-250 );
        break;

    case 2: b->getBee()->setPos(-250  ,rand()%500 -250 );
        break;

    case 3: b->getBee()->setPos(rand()%500 -250  ,250 - beeSize);
        break;

    case 4: b->getBee()->setPos(250 - beeSize,rand()%500 -250);
        break;

    default: b->getBee()->setPos(-25,-25);
        break;
    }


//    switch(b->getGate()){

//    case 1: b->getBee()->setPos(250 - beeSize,-250 );
//        break;

//    case 2: b->getBee()->setPos(-250  ,-250 );
//        break;

//    case 3: b->getBee()->setPos(-250  ,250 - beeSize);
//        break;

//    case 4: b->getBee()->setPos(250 - beeSize,250 - beeSize);
//        break;

//    default: b->getBee()->setPos(-25,-25);
//        break;
//    }

    scene()->addItem(b->getBee());

}
