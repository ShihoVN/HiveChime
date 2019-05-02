#include "animationboard.h"
#include <QGraphicsScene>

AnimationBoard::AnimationBoard()
{
//    buzz = new QMediaPlayer();
//    buzz->setMedia(QUrl("qrc:/sounds/sound/beeSound.wav"));

}


void AnimationBoard::playSound(){
   // buzz->play();
}


void AnimationBoard::populate(){
    DataDecoder d(&container);
    BeeGeneration* BG = new BeeGeneration("0002", 16000);
    for (int i=0;i<10000 ;i++) {
        d.decode(BG->makeBee());
    }
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()), this,SLOT(addBee()));
    //connect(timer,SIGNAL(timeout()), this,SLOT(playSound()));
   timer->start(rand() % 100 + 1000);//every 100ms timeout changes
}


void AnimationBoard::addBee(){
    Data bee=*container.getUdpMessages().at(b);
    int ran = rand() % 8 + 1;
    if(b<container.getUdpMessages().size()-1)
        b++;
    //int ran = 2;
    AnimatedBee *b = new AnimatedBee(1,bee.type);
    setPosition(b);
    //b->playSound();

}


void AnimationBoard::setPosition(AnimatedBee *b){
     b->getBee()->setPos(0,0 );

//    switch(b->getGate()){

//    case 1: b->getBee()->setPos(rand()%500 -250,-250 );
//        break;

//    case 2: b->getBee()->setPos(-250  ,rand()%500 -250 );
//        break;

//    case 3: b->getBee()->setPos(rand()%500 -250  ,250 - beeSize);
//        break;

//    case 4: b->getBee()->setPos(250 - beeSize,rand()%500 -250);
//        break;

//    default: b->getBee()->setPos(-25,-25);
//        break;
//    }


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
