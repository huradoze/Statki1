#ifndef MOTIONLESS_H
#define MOTIONLESS_H

#include <QGraphicsRectItem>
#include <QObject>


class Motionless : public QGraphicsPixmapItem, public QObject
{
public:

    Motionless();

    int scale;


    virtual void attribute() = 0;


    virtual void collision() = 0;
};

#endif  // MOTIONLESS_H
