#ifndef OBSTACLE_ICE_HILL_H
#define OBSTACLE_ICE_HILL_H

#include "Motionless.h"
#include "game.h"


class Obstacle_ice_hill: public Motionless
{
    Q_OBJECT
public:

    Obstacle_ice_hill();


    void attribute();

public slots:

    void collision();
};

#endif // OBSTACLE_ICE_HILL_H
