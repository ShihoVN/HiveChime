#ifndef ANIMATEDBEE_H
#define ANIMATEDBEE_H

#include <QGraphicsRectItem>
#include <QTimer>
#include <QImage>
#include <QList>
#include <QPixmap>


class AnimatedBee: public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    AnimatedBee();





public slots:
    void move();



};

#endif // ANIMATEDBEE_H
