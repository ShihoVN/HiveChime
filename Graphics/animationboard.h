#ifndef ANIMATIONBOARD_H
#define ANIMATIONBOARD_H

#include "../Data/beegeneration.h"
#include "../Data/datacontainer.h"
#include "../Data/datadecoder.h"
#include <QGraphicsRectItem>
#include <animatedbee.h>
#include <vector>
#include <random>
#include <QObject>

using namespace std;

class AnimationBoard:public QObject, public QGraphicsRectItem

//class AnimationBoard: public QGraphicsRectItem
{
    Q_OBJECT
public:
    AnimationBoard();
    void populate();
    void setPosition(AnimatedBee *b);



private:
    pair<int,int> topL;
    pair<int,int> topR;
    pair<int,int> bottomL;
    pair<int,int> bottomR;
    pair<int,int> mid;
    int beeSize = 50;
    int b=0;
    QMediaPlayer *buzz;
    void playSound();

    DataContainer container;
    vector<AnimatedBee*> bees;


public slots:
    void addBee();


};

#endif // ANIMATIONBOARD_H
