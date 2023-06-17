#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Enemy: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:

    Enemy();

    void collision();

public slots:

    void move_to();
};

#endif // ENEMY_H
