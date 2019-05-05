#include "mainwindowanimate.h"
#include "ui_mainwindowanimate.h"
#include "animatedbee.h"

MainWindowAnimate::MainWindowAnimate(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowAnimate)
{
    ui->setupUi(this);
    //Ensures that the window stays fixed
    ui->display->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->display->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    //Creates the display environment and displays it in the graphics view
    //createEnvironment();

}


void MainWindowAnimate::createEnvironment(){
    //Create a scene
    animationScene = new QGraphicsScene();
    animationScene->setSceneRect(-250,-250,500,500);



    //Create board to be added to the scene
    cout<< "sound " << sound << endl;
    board = new AnimationBoard(sound);
    board->setRect(-250,-250,500,500);

    //add board to the scene
    animationScene->addItem(board);





    QPixmap hivePic(":/images /images/BeehiveEdited5.png");
    hivePic = hivePic.scaled(550,550,Qt::KeepAspectRatio);



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

        QTimer *timer = new QTimer();
        connect(timer,SIGNAL(timeout()), this,SLOT(playSound()));
        timer->start(100);//ev





    //    connect(timer,SIGNAL(timeout()), this,SLOT(populateRT()));
    //    //connect(timer,SIGNAL(timeout()), this,SLOT(playSoundOnScreen()));
    //    timer->start(5000);//every 100ms timeout changes

    //    QTimer *timer1 = new QTimer();
    //    connect(timer,SIGNAL(timeout()), this,SLOT(addBeeRT()));
    //    //connect(timer,SIGNAL(timeout()), this,SLOT(playSoundOnScreen()));
    //    timer1->start(rand() % 100 + 100);//every 100ms timeout changes
    //board->playSoundOnScreen();





    //    QPixmap beeIMG(":/images /images/Indiv_Bee.png");
    //    beeIMG = beeIMG.scaled(50,50,Qt::KeepAspectRatio);
    //    QGraphicsPixmapItem *bee = new QGraphicsPixmapItem(beeIMG);
    //    bee->setPos(-250,-25);
    //    animationScene->addItem(bee);


    //    AnimatedBee *bee = new AnimatedBee();
    //    bee->getBee()->setPos(-250,-25);
    //    animationScene->addItem(bee->getBee());

}

void MainWindowAnimate::addBeeRT(){

    board->addBeeRT();


}

void MainWindowAnimate::populateRT(){

    board->populateRT();


}


void MainWindowAnimate::playSound(){
    if(ui->sound->isChecked()){
        if(board->returnSound()->state() == QMediaPlayer::StoppedState)
            board->returnSound()->play();
        else if (board->returnSound()->isMuted()) {
            board->returnSound()->setMuted(false);
        }
    }
    else {
        if(board->returnSound()->state() == QMediaPlayer::PlayingState)
            board->returnSound()->setMuted(true);
    }

}


MainWindowAnimate::~MainWindowAnimate()
{

    board->returnSound()->stop();
    delete ui;
}


void MainWindowAnimate::populate(){

    //for (int i = 1; i <= 8; i++){
    //AnimatedBee *b = new AnimatedBee(i);
    // setPosition(b);
    //    bees.push_back(b);
    // }

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




void MainWindowAnimate::setSound(bool s){
    sound = s;
}

//leave methods
QRectF MainWindowAnimate::boundingRect(){
    QRectF demo;

    return demo;
}

void MainWindowAnimate::paint(QPainter*,const QStyleOptionGraphicsItem*, QWidget){

}

