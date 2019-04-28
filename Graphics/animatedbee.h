#ifndef ANIMATEDBEE_H
#define ANIMATEDBEE_H


#include <QList>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QTimer>
#include <QObject>




//class AnimatedBee: public QGraphicsPixmapItem

class AnimatedBee:public QObject, public QGraphicsPixmapItem

{
    Q_OBJECT


public:
    AnimatedBee();
    AnimatedBee(int gate);
    AnimatedBee(QPixmap pic);
    AnimatedBee(QGraphicsItem *parent);
    void setPosition();
    int getGate();
    void addBee(int i);

    QGraphicsPixmapItem* getBee();




    //Virtual methods
    QRectF boundingRect();
    void paint(QPainter*,const QStyleOptionGraphicsItem*, QWidget*);


private:
    int gate;
    QGraphicsPixmapItem *bee;


public slots:
    void move();



};

#endif // ANIMATEDBEE_H
