#include "animatedbee.h"



AnimatedBee::AnimatedBee()
{
    QPixmap beeIMG(":/images /images/Indiv_Bee.png");
    beeIMG = beeIMG.scaled(5,5,Qt::KeepAspectRatio);
    bee = new QGraphicsPixmapItem(beeIMG);
    buzz = new QMediaPlayer();
    buzz->setMedia(QUrl("qrc:/sounds/sound/beeSound.wav"));




}

AnimatedBee::AnimatedBee(int gate)
{

    this->gate = gate;


    beeIMG.load(":/images /images/Indiv_Bee.png");
    //beeIMG = new  QPixmap(":/images /images/Indiv_Bee.png");
    beeIMG = beeIMG.scaled(beeSize,beeSize,Qt::KeepAspectRatio);
    bee = new QGraphicsPixmapItem(beeIMG);


    //Connect
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()), this,SLOT(move()));

    timer->start(10);//every 100ms timeout changes

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



void AnimatedBee::playSound(){
    buzz->play();
}



bool AnimatedBee::checkBounds(){
   // bool bounds;

    //If the bee is exiting
    if(gate > 4 &&  gate <= 8 ){

        if (bee->x() <50 &&
                bee->x() > -50 && bee->y() < 50 && bee->y() > -50)
        {
           // return true;
            delete this;
        }

    }





    return false;
}


void AnimatedBee::move(){
    if(checkBounds()){

    }
    count ++;

    if (count % 100 == 0 && beeSize > 10){


        beeIMG = beeIMG.scaled(beeSize--,beeSize--,Qt::KeepAspectRatio);
        bee = new QGraphicsPixmapItem(beeIMG);
        count = 1;
    }






    //bee = new QGraphicsPixmapItem(beeIMG);

    //if it is a bee entry
    if(gate == 1){
        if(bee->x() > 40){
            bee->setPos(bee->x() - 1, bee->y());
        }
        else if(bee->x() < 40){
            bee->setPos(bee->x() + 1 , bee->y());
        }
        if(bee->y() > -75){
            bee->setPos(bee->x() , bee->y()- 1);
        }
        else if(bee->y() < -75){
            bee->setPos(bee->x() , bee->y()+ 1);
        }
    }



    if(gate == 2){


        if(bee->x() > -50){
            bee->setPos(bee->x() - 1, bee->y());
        }
        else if(bee->x() < -50){
            bee->setPos(bee->x() + 1 , bee->y());
        }

        if(bee->y() > -80){
            bee->setPos(bee->x() , bee->y()- 1);
        }
        else if(bee->y() < -80){
            bee->setPos(bee->x() , bee->y()+ 1);

        }
    }



    if(gate == 3){


        if(bee->x() > -25){
            bee->setPos(bee->x() - 1, bee->y());
        }
        else if(bee->x() < -25){
            bee->setPos(bee->x() + 1 , bee->y());
        }

        if(bee->y() > -25){
            bee->setPos(bee->x() , bee->y()- 1);
        }
        else if(bee->y() < -25){
            bee->setPos(bee->x() , bee->y()+ 1);

        }
    }



    if(gate == 4){


        if(bee->x() > -25){
            bee->setPos(bee->x() - 1, bee->y());
        }
        else if(bee->x() < -25){
            bee->setPos(bee->x() + 1 , bee->y());
        }

        if(bee->y() > 50){
            bee->setPos(bee->x() , bee->y()- 1);
        }
        else if(bee->y() < 50){
            bee->setPos(bee->x() , bee->y()+ 1);

        }
    }

    if (gate == 5){
        bee->setPos(bee->x() + 10 , bee->y()-  1);
    }
    if (gate == 6){
        bee->setPos(bee->x() - 10 , bee->y()-  1);
    }
    if (gate == 7){
        bee->setPos(bee->x() - 10 , bee->y()+  1);
    }
    if (gate == 8){
        bee->setPos(bee->x() + 10 , bee->y()+  1);
    }



    if (checkBounds()){




    }//checks to see if the bee is inside
}




int AnimatedBee::getGate(){
    return gate;
}



QGraphicsPixmapItem* AnimatedBee::getBee(){
    return bee;
}






QRectF AnimatedBee::boundingRect(){
    QRectF n;
    return n;
}

void AnimatedBee::paint(QPainter*,const QStyleOptionGraphicsItem*, QWidget*){

}
