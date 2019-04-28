#include "framework.h"

FrameWork::FrameWork()
{

}


QGraphicsScene * FrameWork::createEnvironment(){
    animationScene = new QGraphicsScene();







//    object = new QGraphicsRectItem();
//    object->setRect(0,0,100,100);



    QPixmap hivePic(":/images /images/beeHive.png");

    hivePic = hivePic.scaled(100,100,Qt::KeepAspectRatio);
    hive = new QGraphicsPixmapItem(hivePic);

    //animationScene->addItem(object);

    animationScene->addItem(hive);

    //    display =  new QGraphicsView(animationScene);
    //    display->setScene(animationScene);

    //  display->show();

    return animationScene;
}
