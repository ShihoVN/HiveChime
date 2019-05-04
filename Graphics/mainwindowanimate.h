#ifndef MAINWINDOWANIMATE_H
#define MAINWINDOWANIMATE_H

#include <QMainWindow>

#include "animatedbee.h"
#include <QGraphicsScene>
#include <vector>
#include <iostream>
#include <QObject>

#include "animationboard.h"
using namespace std;

namespace Ui {
class MainWindowAnimate;
}

class MainWindowAnimate : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowAnimate(QWidget *parent = nullptr);
    ~MainWindowAnimate();
    void setPosition(AnimatedBee *b);
    void populate();
    void setSound( bool s);

    void createEnvironment();

    QRectF boundingRect();
    void paint(QPainter*, const QStyleOptionGraphicsItem*,QWidget);



private:
    Ui::MainWindowAnimate *ui;
    QGraphicsScene * animationScene;
    QGraphicsPixmapItem *hive;
    bool sound = false;
};

#endif // MAINWINDOWANIMATE_H
