#include "animatedbee.h"
#include <QGraphicsScene>


//not used
AnimatedBee::AnimatedBee()
{
    QPixmap beeIMG(":/images /images/Indiv_Bee.png");
    beeIMG = beeIMG.scaled(5,5,Qt::KeepAspectRatio);
    bee = new QGraphicsPixmapItem(beeIMG);
    buzz = new QMediaPlayer();
    buzz->setMedia(QUrl("qrc:/sounds/sound/beeSound.wav"));

}


//not used
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


//this constructor is being used
AnimatedBee::AnimatedBee(int board, bool type)
{
    //set the properties of the bee data to the object
    this->board = board;
    this->type = type;


    //loads image, rescale's it and use it to create a Qgraphics item to be displayed
    beeSize = 30; //initial size of bee
    beeIMG.load(":/images /images/Indiv_Bee.png");
    beeIMG = beeIMG.scaled(beeSize,beeSize,Qt::KeepAspectRatio);
    bee = new QGraphicsPixmapItem(beeIMG);


    //Timer to move object based off the timeout interval
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()), this,SLOT(move()));
    timer->start(50);//every 50ms timeout changes


    //sets up bee hive sounds #not used yet
    buzz = new QMediaPlayer();
    buzz->setMedia(QUrl("qrc:/sounds/sound/beeSound.wav"));
}





void AnimatedBee::playSound(){
    if (buzz->isAvailable()){
        buzz->play();
    }
}


//Checks if the beeobject is in bounds
bool AnimatedBee::isInBounds(){





    //it is an exit data
    if (type == false ){



        //check if its not within display window
        if(bee->x() == rightBorder - 50 || bee->x() == leftBorder
                || bee->y() == bottomBorder - 50 || bee->y() == topBorder){

            //cout << "exited ";
            return false;
        }
        else {
            //cout << "bee deleted";
            return true;

        }
    }


    //Write code for bounds for entry;

}


void AnimatedBee::move(){


    if(bee->x() < rightBorder){
        bee->setPos(bee->x() + 1, bee->y());
    }
    if(bee->y() < bottomBorder){
        bee->setPos(bee->x() , bee->y()+ 1);
    }


    //Scene might give error
    if(!isInBounds()){
        scene()->removeItem(bee);
                //->removeItem(bee);
        //cout << "bee deleted";
        //delete bee;
        return;

    }








    //Used to decrease size of image not implemented yet
//    count ++;
//    if (count % 100 == 0 && beeSize > 10){
//        beeIMG = beeIMG.scaled(beeSize--,beeSize--,Qt::KeepAspectRatio);
//        bee = new QGraphicsPixmapItem(beeIMG);
//        count = 1;
//    }


/*

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

    */
}




int AnimatedBee::getGate(){
    return gate;
}

int AnimatedBee::getBoard(){
    return board;
}

int AnimatedBee::getBeeSize(){
    return beeSize;
}

bool AnimatedBee::getType(){
    return type;
}




QGraphicsPixmapItem* AnimatedBee::getBee(){
    return bee;
}





//Anything below this line is not implemented
QRectF AnimatedBee::boundingRect(){
    QRectF n;
    return n;
}

void AnimatedBee::paint(QPainter*,const QStyleOptionGraphicsItem*, QWidget*){

}
