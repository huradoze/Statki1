#ifndef OBSTACLE_FALE_H
#define OBSTACLE_FALE_H

#include "Motionless.h"


class Obstacle_fale: public Motionless
{
    Q_OBJECT
public:

    Obstacle_fale();


    void attribute();

public slots:

    void collision();
};

#endif // OBSTACLE_FALE_H

