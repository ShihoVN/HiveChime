#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "animatedbee.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    //Ensures that the window stays fixed
    ui->display->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->display->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    //Creates the display environment and displays it in the graphics view
    createEnvironment();

}



void MainWindow::createEnvironment(){
    //Create a scene
    animationScene = new QGraphicsScene();
    animationScene->setSceneRect(-250,-250,500,500);



    //Create board to be added to the scene
    AnimationBoard* board = new AnimationBoard();
    board->setRect(-250,-250,500,500);

    //add board to the scene
    animationScene->addItem(board);





    QPixmap hivePic(":/images /images/MainBeeHive.png");
    hivePic = hivePic.scaled(800,800,Qt::KeepAspectRatio);


    //    QPixmap hivePic(":/images /images/beeHive.png");
    //    hivePic = hivePic.scaled(100,100,Qt::KeepAspectRatio);
    hive = new QGraphicsPixmapItem(hivePic);





    //hive->setPos(-50,-50);



    hive->setPos(-250,-250);
    animationScene->addItem(hive);
    hive->setFlag(QGraphicsItem::ItemIsFocusable);
    hive->setFocus();
    ui->display->setScene(animationScene);
    //ui->display->show();




    //populate the board with bees
    board->populate();



    //    QPixmap beeIMG(":/images /images/Indiv_Bee.png");
    //    beeIMG = beeIMG.scaled(50,50,Qt::KeepAspectRatio);
    //    QGraphicsPixmapItem *bee = new QGraphicsPixmapItem(beeIMG);
    //    bee->setPos(-250,-25);
    //    animationScene->addItem(bee);


    //    AnimatedBee *bee = new AnimatedBee();
    //    bee->getBee()->setPos(-250,-25);
    //    animationScene->addItem(bee->getBee());

}




void MainWindow::populate(){

    for (int i = 1; i <= 8; i++){
        //AnimatedBee *b = new AnimatedBee(i);
        // setPosition(b);
        //    bees.push_back(b);
    }

}







MainWindow::~MainWindow()
{
    delete ui;
}


//void MainWindow::setPosition(AnimatedBee *b){
//    //animationScene->addItem(b);


//    switch(b->getGate()){

//    //case 1: b->setPos(ui->display->width(),0);
//        case 1: b->setPos(20,20);
//        break;

//    case 2: b->setPos(0,0);
//        break;

//    case 3: b->setPos(0,ui->display->height());
//        break;

//    case 4: b->setPos(ui->display->width(),ui->display->height());
//        break;

//    default: b->setPos(ui->display->width()/2,ui->display->height()/2);
//        break;
//    }

//    animationScene->addItem(b);

//}






//leave methods
QRectF MainWindow::boundingRect(){
    QRectF demo;

    return demo;
}

void MainWindow::paint(QPainter*,const QStyleOptionGraphicsItem*, QWidget){

}
