#ifndef PLAYER_H
#define PLAYER_H

#include "bullet.h"
#include "motionless.h"
#include <QGraphicsRectItem>
#include <QObject>
#include "enemy.h"


class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:

    Player(QGraphicsItem *parent = 0);


    void keyPressEvent(QKeyEvent *event);


    ~Player();

public slots:

    void create();


    void create_obstacle_fale();


    void create_obstacle_ice_hill();

private:

    void create_motionless(Motionless *object);

    std::vector<Motionless *> objects;
    std::vector<Enemy *> enemies;
    std::vector<Bullet *> bullets;
    int moveSpeed = 7;
};

#endif // PLAYER_H


































































































































































































































































































































































#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include "obstacle_fale.h"


class Player:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);
    int moveSpeed;
public slots:
    void spawn();
    void spawn_obstacle_ice_hill();
    void spawn_obstacle_fale();

};

#endif // PLAYER_H
